#include "AppData.h"

template<class HeadType>class SimpleHeadNode;
template<class HeadType,class ElementType>class SimpleChainList;

template<class ElementType>
class SimpleChainNode
{//简单链表数据元素结点结构类定义
	//friend SimpleChainList <class HeadType,class ElementType>;
	public:
		ElementType						data;
		SimpleChainNode<ElementType>		*link;
};

template<class HeadType>
class SimpleHeadNode
{//简单链表表头数据元素结点结构类定义
	//friend SimpleChainList <class HeadType,class ElementType>;
	public:
		HeadType									Hdata;
		SimpleChainNode<class ElementType>		*first;
};



template<class HeadType,class ElementType>
class SimpleChainList
{//线性表链式存储结构-简单链表模板类 SimpleChainList的定义
	public:
	SimpleChainList();					//构造函数
	~SimpleChainList();					//析构函数
	int	LengthSimpleChainList() const ;	//求简单链表长度
	void  PutValueSimpleHeadNode(HeadType &headValue)
	{HeadPtr->Hdata=headValue;};	//已知值headValue给表头结点Hdata域赋值
	SimpleHeadNode<HeadType> * GetHeadPtrSimpleChainList(){return HeadPtr;};
		//HeadPtr：返回链表表头的指针HeadPtr
	SimpleChainNode<ElementType> * GetFirstPtrSimpleChainList()
	{return HeadPtr->first;};//获取简单链表中第一个结点指针first值

//*****查找函数
	bool GetElementSimpleChainList(int k,ElementType &result);
	//查找:简单链表中查找第k个元素，存入result中，多态函数
	bool GetElementSimpleChainList(SimpleChainNode<ElementType> *current,
ElementType &result);
	//查找:简单链表中查找current指针所指的数据元素，存入result中，多态函数
	SimpleChainNode<ElementType> * SearchElementSimpleChainList(int searchkey);
	//查找：查找关键字值为searchkey(数值型)的元素，返回元素位置（指针）
SimpleChainNode<ElementType> *SearchElementSimpleChainList(char* searchkey);
	//查找：查找关键字值为searchkey(字符型)的元素，返回元素位置（指针）

//*******插入、删除函数
	bool	InsertElementSimpleChainList(int k, ElementType &newvalue );
	//插入：插入值为newvalue元素到简单链表中第k个数据元素之后
	bool	InsertElementFrontSimpleChainList(ElementType &newvalue ,
 SimpleChainNode<ElementType>	* InsertPtr);
	//插入元素：插入值为newvalue元素到简单链表中InsertPtr指针所指数据元素之前
	bool	DeleteElementSimpleChainList( int k );
	//删除元素：删除简单链表中第k个数据元素（多态函数）
	bool	DeleteElementSimpleChainList(SimpleChainNode<ElementType> 
* DeletePtr );  
	//删除元素：删除简单链表中DeletePtr指针所指数据元素（多态函数）
	
	
	void	DisplaySimpleChainList(SimpleChainList<HeadType,ElementType>
 &AppList );
	//显示输出链表的所有数据元素的值
	void	DisplayElementSimpleChainList(ElementType result);
			//显示输出链表的数据元素result的值




	bool MovelElementFirstSimpleChainList(int k);
	//在简单链表中将第K个数据元素移至链表表首

	void InvertSimpleChainList();
    //对简单链表进行逆向
     
	
	private:
		SimpleHeadNode<HeadType>	*HeadPtr;			//表头结点的指针
};


template<class HeadType,class ElementType>
SimpleChainList<HeadType,ElementType>::
SimpleChainList()
{
	//构造函数。定义线性表空间大小MaxSize、
    //申请元素空间element、定义线性表长度初值length
	HeadPtr=new SimpleHeadNode<HeadType>;
	HeadPtr->first=NULL;
}

template<class HeadType,class ElementType>
SimpleChainList<HeadType,ElementType>::
~SimpleChainList()
{//析构函数。删除链表中所有数据结点及表头结点，并释放结点空间
	SimpleChainNode<ElementType> 	* current;
	current =HeadPtr->first;
	while (HeadPtr->first)
	{// 删除链表中所有数据结点，并释放结点空间
		current = current ->link;
		delete HeadPtr->first;
		HeadPtr->first = current;
	}
	delete HeadPtr;
}

template<class HeadType,class ElementType>
int SimpleChainList<HeadType,ElementType>::
LengthSimpleChainList() const
{//求简单链表中数据元素结点数（链表长度）
	SimpleChainNode<ElementType> *current = HeadPtr->first;
	int len = 0;
	while (current)
	{
		len++;
		current = current->link;
	}
	return len;
}

template<class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
GetElementSimpleChainList(int k,ElementType &result)
{ //简单链表第k个元素值取至result中带回。如不存在返回false，存在返回true
	if (k < 1) return false;
	SimpleChainNode<ElementType>  	*current = HeadPtr->first;
	int 		index = 1; 
	while (index < k && current)
	{//查找第k个数据元素
		current = current->link;
		index++;
	}
	if (current)
	{
		result = current->data;
		return true;
	}
	return false; 		// k值太大，不存在第k个结点
}

template<class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
GetElementSimpleChainList(SimpleChainNode<ElementType> *current,ElementType &result)
{ //简单链表第k个元素值取至result中带回。如不存在返回false，存在返回true
	if (!current) return false;
		result = current->data;
		return true;
}

template<class HeadType,class ElementType>
SimpleChainNode<ElementType> * SimpleChainList<HeadType,ElementType>::
SearchElementSimpleChainList(int searchkey)	//char *searchkey
{// 简单链表中查找数据元素关键字为searchkey（年龄）的元素
 //如果找到返回元素所在的地址；如果未找到返回NULL 
   SimpleChainNode<ElementType>  *current = HeadPtr->first;
   while (current && current->data.key != searchkey )	
		current = current->link;
   if (current)
		return current;
   else
		return NULL;
}

template<class HeadType,class ElementType>
SimpleChainNode<ElementType> * SimpleChainList<HeadType,ElementType>::
SearchElementSimpleChainList(char searchkey[])	//char *searchkey
{// 简单链表中查找数据元素关键字为searchkey（年龄）的元素
 //如果找到返回元素所在的地址；如果未找到返回NULL 
   SimpleChainNode<ElementType>  *current = HeadPtr->first;
   while (current && !strcmp(current->data.key,searchkey ))	//strcmp(current->data.place,searchkey)
		current = current->link;
   if (current)
		return current;
   else
		return NULL;
}



template<class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
InsertElementSimpleChainList( int k, ElementType &newvalue )
{// 在简单链表中第k个数据元素之后中插入新元素（值为newvalue）
 // 如果不存在第k个元素，则返回false
	if (k < 0) return false;
	int			index = 1;
	SimpleChainNode<ElementType>	*current = HeadPtr->first;
	while  (index < k && current)
	{//查找第k个结点
		index++;
		current = current ->link;
	}
	if (k > 0 && ! current) return false;
	SimpleChainNode<ElementType>   *q = new SimpleChainNode<ElementType>;
	q->data = newvalue;
	if (k)
	{// 插入在current 之后
		q->link = current ->link;
		current ->link = q;
	}
	else 
	{// 作为第一个元素结点插入
		q->link = HeadPtr->first;
		HeadPtr->first = q;
	}
	return true;
}





template<class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
InsertElementFrontSimpleChainList(ElementType &newvalue  , SimpleChainNode<ElementType> * InsertPtr)
{// 在简单链表中InsertPtr指针所指数据元素之前中插入新元素（值为newvalue）
	if (!InsertPtr) 
		return false;
		
	SimpleChainNode<ElementType>	*current = HeadPtr->first;
	if(InsertPtr!= HeadPtr->first)
	{//InsertPtr不是头结点指针时，推进指针current直到current=InsertPtr，查找结点。
		while  (current && current->link!=InsertPtr)
		{//查找InsertPtr指针指向的结点
			current = current ->link;
		}
		if (! current) return false;//current为NULL，查找失败，不存在此结点
	}
	SimpleChainNode<ElementType>   *q = new SimpleChainNode<ElementType>;
//申请插入新数据空间
	q->data = newvalue;		//新数据值赋值到数据空间中
	if (InsertPtr== HeadPtr->first) 
	{// InsertPtr== HeadPtr->first时，作为第一个元素结点插入
		q->link= HeadPtr->first;
		HeadPtr->first=q;
	}
	else
	{// InsertPtr！= HeadPtr->first时，插入在current 之后
		q->link = current ->link;
		current ->link = q;
	}
	return true;
}

template<class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
DeleteElementSimpleChainList( int k )
{// 在简单表中删除第k个数据元素,如果不存在第k个元素返回false
	if (k < 1 || ! HeadPtr->first)	//k值太小或链表为空
		return false;
	SimpleChainNode<ElementType>   * current = HeadPtr->first;
	if (k == 1)						// 删除的是链表中第一个结点
		HeadPtr->first = current->link; 
	else 
	{ 
		SimpleChainNode<ElementType>   *q = HeadPtr->first;
		for (int index = 1; index < k - 1 && q ; index++)
			q = q->link;       		// q 指向第k-1个结点
		if (!q || !q->link)	
//q为空时：不存在第k-1个结点；q->link为空时：不存在第k个结点
			return false; 
		current = q->link;      	// current 指向第k个结点
		q->link = current ->link; 
	}
	delete current;          		// 释放被删除结点current的空间
	return true;
}

template<class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
DeleteElementSimpleChainList( SimpleChainNode<ElementType> * DeletePtr )
{// 在简单表中删除DeletePtr指针所指数据元素,如果不存在返回false
	if (! HeadPtr->first)		
		return false;
		
	if (DeletePtr == HeadPtr->first)
	{// DeletePtr == first时，删除的是链表中第一个结点
		HeadPtr->first = DeletePtr->link; 
		return true;
	}
	else 
	{ 
		SimpleChainNode<ElementType>   *q = HeadPtr->first;
		while (q->link!=DeletePtr && q)	// 推进q，指向DeletePtr指向结点的前驱	
			q = q->link;       		
		if (!q )	//q为空时，不存在DeletePtr指向结点，插入失败。
			return false; 
		q->link = DeletePtr ->link;		//插入
		delete DeletePtr;          		// 释放被删除DeletePtr指向结点的空间
	}
	return true;
}


template<class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
MovelElementFirstSimpleChainList(int k)
{
	if(k<1 || !HeadPtr->first)     //k值太小或链表为空
		return false;
	SimpleChainNode<ElementType>  *current = HeadPtr->first;
	if(k==1)
		return true;
	else
	{
		SimpleChainNode<ElementType>  *q = HeadPtr->first;
		for(int index=1; index < k-1 && q;index++)
			q = q->link;
		if(!q || !q->link)
			//若q为空，则不存在第K-1个结点；若q->link空，则不存在第K个结点
			return false;
		current = q->link;         //current指向第K个结点
		q->link = current->link;   //删除第K个结点
	}
	current->link = HeadPtr->first;
	HeadPtr->first = current;
	return true;
}

template<class HeadType,class ElementType>
void SimpleChainList<HeadType,ElementType>::
InvertSimpleChainList()
{
	//对简单链表逆向
	SimpleChainNode<ElementType> *p = HeadPtr->first;
	SimpleChainNode<ElementType>  *current;
	HeadPtr->first = NULL;
	while(p)
	{
		current = p;
		p = p->link;
		current->link = HeadPtr->first;
		HeadPtr->first = current;
	}
}


template<class HeadType,class ElementType>
void SimpleChainList<HeadType,ElementType>::
DisplayElementSimpleChainList(ElementType result)
{// 输出简单链表中的数据元素，此算法不属于模板类SimpleChainList
	cout<<result.number<<"    ";
	cout<<result.name<<"    ";
	cout<<result.sex<<"   ";
	cout<<result.age<<"   ";
	cout<<result.place<<endl;
}

template<class HeadType,class ElementType>
void SimpleChainList<HeadType,ElementType>::
DisplaySimpleChainList(SimpleChainList<HeadType,ElementType> &AppList )
{// 输出简单链表中的所有数据元素，此算法不属于模板类SimpleChainList
 // 算法的参数类型是模板SimpleChainList类型，对象（实例）使用引用变量！
	SimpleHeadNode<HeadType>    *HEADPTR = GetHeadPtrSimpleChainList();
	SimpleChainNode<ElementType>	*current = HEADPTR->first;

	cout<<"\n\n";
	cout<<" ┌──────────────────────────────┐"<<endl;
	cout<<" │     学生表                   │"<<endl;
	cout<<" ├────────┬─────────────────────┤"<<endl;
	cout<<" │        │      │       │      │"<<endl;
	cout<<" │学    号│ 姓 名│ 性 别 │ 年龄 │"<<endl;
	cout<<" │　　　　│　　　│       │      │"<<endl;
	cout<<" ├──────-─┼──────┼───────┼──────┤"<<endl;

	for (int i = 1; i <= AppList.LengthSimpleChainList(); i++)
	{
		cout<<" │  "<<current->data.number;  
		cout<<"  │ "<<current->data.name;
		cout<<" │   "<<current->data.sex;
		cout<<"   │ "<<current->data.age<<"   │ "<<endl;
		cout<<" ├────────┼──────┼───────┼──────┤"<<endl;
		current = current->link;
	}
}


