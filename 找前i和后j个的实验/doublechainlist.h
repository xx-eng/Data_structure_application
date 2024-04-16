#include "AppData_doublechainlist.h"




template <class ElementType>
class DoubleChainNode
{
public:
	ElementType      data;
	DoubleChainNode<ElementType>     *plink;
	DoubleChainNode<ElementType>     *nlink;
};

template <class HeadType>
class DoubleHeadNode
{
public:
	HeadType  Hdata;
	DoubleChainNode<ElementType>   *first;
};


template <class HeadType,class ElementType>
class DoubleChainList
{//双向链表模板类DoubleChainList的定义
	public:
		DoubleChainList();         //构造函数
		~DoubleChainList();		   //析构函数
		int LengthDoubleChainList() const;     //求双向链表长度

		void PutValueDoubleChainHeadNode(HeadType &HeadValue)
			{ HeadPtr->Hdata = HeadValue;};			//使用值HeadValue给表头结点Hdata域赋值
		DoubleHeadNode <HeadType> *GetHeadPtrDoubleChainList()
			{return HeadPtr;};				//获取双向链表中表头结点指针HeadPtr的值
		DoubleChainNode<ElementType>  *GetFirstPtrDoubleChainList()
			{return HeadPtr->first;};		//获取双向链表中第一个结点的指针first的值

		
		DoubleChainNode<ElementType> *GetElementDoubleChainList(int searchkey);
		//在双向链表中查找关键字为searchkey的数据元素，存入result中（多态函数）
		bool InsertElementDoubleChainList(int k,ElementType &newvalue);
		//插入元素
		bool DeleteElementDoubleChainList(int k);
		//删除双向链表中第K个数据元素
		void	DisplayDoubleChainList(DoubleChainList<HeadType, ElementType> &AppList);
	//显示输出线性表中的所有数据元素的值
		void    DisplayDoubleChainNode(ElementType result);
		//显示单个元素

		bool  findbeforeAndAfter(int searchkey,int x,int y);
		//给定某一学号x，能同时找到该学生第X个前驱的学生信息，以及该学生第Y个后继的学生信息，参数x, X，Y从键盘输入


	private:
		DoubleHeadNode<HeadType>  *HeadPtr;    //表头结点的指针
		
};

template <class HeadType,class ElementType>
DoubleChainList<HeadType,ElementType>::
DoubleChainList()
{
	HeadPtr = new DoubleHeadNode<HeadType>;
	HeadPtr->first = NULL;
}

template <class HeadType,class ElementType>
DoubleChainList<HeadType,ElementType>::
~DoubleChainList()
{
	DoubleChainNode<ElementType>   *current = HeadPtr->first;
	while(HeadPtr->first)
	{//删除表中所有数据结点，并释放空间
		current = current->nlink;
		delete HeadPtr->first;
		HeadPtr->first = current;
	}
	delete HeadPtr;  //删除表头结点
}


template <class HeadType,class ElementType>
int DoubleChainList<HeadType,ElementType>::
LengthDoubleChainList() const
{
	DoubleChainNode<ElementType>   *current = HeadPtr->first;
	int len = 0;
	while(current)
	{//推进指针，并计数
		len++;
		current = current->nlink;
	}
	return len;
}

template <class HeadType,class ElementType>
DoubleChainNode<ElementType>  *DoubleChainList<HeadType,ElementType>::
GetElementDoubleChainList(int searchkey)
{//查找关键字为searchkey的元素
//如果找到，返回元素所在的地址；如果未找到，返回NULL
	DoubleChainNode<ElementType> *current = HeadPtr->first;
	while(current && current->data.num != searchkey)
		current = current->nlink;
	if(current)
		return current;
	else
		return NULL;

}

template <class HeadType,class ElementType>
bool DoubleChainList<HeadType,ElementType>::
InsertElementDoubleChainList(int k,ElementType &newvalue)
{//在双向链表中的第K个元素后插入值为newvalue的新元素
	if(k<0) return false;   //如不存在第K个元素，return false
	DoubleChainNode<ElementType>  *current=HeadPtr->first;
	int index = 1;
	while(index<k && current)
	{//查找第K个结点
		index++;
		current = current->nlink;
	}
    if(k>0 && !current) return false;   

	DoubleChainNode<ElementType>   *q = new DoubleChainNode<ElementType>;
	q->data = newvalue;

	if(k)
	{//插入在current之后，current指向最后或中间的结点
		q->nlink = current->nlink;
		q->plink = current;
		DoubleChainNode<ElementType>   *p=current->nlink;
		if(p)					//如果P为NULL则Q作为最后一个插入
			p->plink = q;		//新结点的后继指针指向新结点
		
		current->nlink = q;		//插入点结点后继指针指向新结点
	}
	else
	{
		q->nlink = HeadPtr->first;
		q->plink = NULL;
		DoubleChainNode<ElementType>   *p = HeadPtr->first;
		if(p)
			p->plink = q;
		HeadPtr->first = q;
	}
	return true;
}


template <class HeadType,class ElementType>
bool DoubleChainList<HeadType,ElementType>::
DeleteElementDoubleChainList(int k)
{//删除第K个结点
	DoubleChainNode<ElementType>    *p;
	DoubleChainNode<ElementType>    *current = HeadPtr->first;
	if(k<1 || !HeadPtr->first) 
		return false;
	if(k==1)
	{
		p = current->nlink;
		if(p)
			p->plink = NULL;
		HeadPtr->first = p;
	}
	else
	{
		DoubleChainNode<ElementType>  *q = HeadPtr->first;
		for(int index=1; index<k && q ; index++)
		{
			q = q->nlink;			//q指向第K-1个结点
		}
		if(!q)
			return false;
		//q为空，不存在第K-1个结点，q->nlink为空，不存在第K个结点
		current = q;     //current指向第K个结点
		q = current->plink;
		p =current->nlink;
		q->nlink = p;
		if(p)					//p为真时，删除的不是最后一个结点
			p->plink = q;
	}
	delete current;    //释放被删除结点current 的空间
	return true;
}

template <class HeadType,class ElementType>
void DoubleChainList<HeadType,ElementType>::
DisplayDoubleChainList(DoubleChainList<HeadType, ElementType> &AppList)
{// 输出简单链表中的所有数据元素，此算法不属于模板类SimpleChainList
 // 算法的参数类型是模板SimpleChainList类型，对象（实例）使用引用变量！
	DoubleHeadNode<HeadType>    *HEADPTR = GetHeadPtrDoubleChainList();
	DoubleChainNode<ElementType>	*current = HEADPTR->first;

	cout<<"\n\n";
	cout<<" ┌───────────────┐"<<endl;
	cout<<" │     学生表    │"<<endl;
	cout<<" ├────────┬──────┤"<<endl;
	cout<<" │        │      │"<<endl;
	cout<<" │学    号│姓 名 │"<<endl;
	cout<<" │　　　　│　　　│"<<endl;
	cout<<" ├──────-─┼──────┤"<<endl;

	for (int i = 1; i <= AppList.LengthDoubleChainList(); i++)
	{
		cout<<" │  "<<current->data.num;  
		cout<<"     │    "<<current->data.name<<"│"<<endl;
		cout<<" ├────────┼──────┤"<<endl;
		current = current->nlink;
	}



	
	cout<<endl<<endl<<endl;
}


template <class HeadType,class ElementType>
void DoubleChainList<HeadType,ElementType>::
DisplayDoubleChainNode(ElementType result)
{//显示单个元素
	cout<<"学号是"<<result.num<<"    ";
	cout<<"姓名是"<<result.name<<endl;
}



template <class HeadType,class ElementType>
bool DoubleChainList<HeadType,ElementType>::
findbeforeAndAfter(int searchkey,int x,int y)
{//找到学号为searchkey的元素的前X个元素，和后Y个元素
	int i,j;

	DoubleChainNode<ElementType> *current = HeadPtr->first;
	while(current && current->data.num != searchkey)
		current = current->nlink;

	DoubleChainNode<ElementType> *p = current;
	DoubleChainNode<ElementType> *q = current;
	for(i=0; i<x && p; i++)
	{
		p = p->plink;
	}
	if(p)
	{
		cout<<"前"<<x<<"项已找到"<<endl;
		DisplayDoubleChainNode(p->data);
		
	}
	else
		cout<<"前"<<x<<"项未找到"<<endl;
	
	for(j=0; j<y && q; j++)
	{
		q = q->nlink;
	}

	if(q)
	{	
		cout<<"后"<<y<<"项已找到"<<endl;
		DisplayDoubleChainNode(q->data);
	}
	else
		cout<<"后"<<x<<"项未找到"<<endl;

	if(q || p)
		return true ;
	else
		return false;

	
}