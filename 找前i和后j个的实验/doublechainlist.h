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
{//˫������ģ����DoubleChainList�Ķ���
	public:
		DoubleChainList();         //���캯��
		~DoubleChainList();		   //��������
		int LengthDoubleChainList() const;     //��˫��������

		void PutValueDoubleChainHeadNode(HeadType &HeadValue)
			{ HeadPtr->Hdata = HeadValue;};			//ʹ��ֵHeadValue����ͷ���Hdata��ֵ
		DoubleHeadNode <HeadType> *GetHeadPtrDoubleChainList()
			{return HeadPtr;};				//��ȡ˫�������б�ͷ���ָ��HeadPtr��ֵ
		DoubleChainNode<ElementType>  *GetFirstPtrDoubleChainList()
			{return HeadPtr->first;};		//��ȡ˫�������е�һ������ָ��first��ֵ

		
		DoubleChainNode<ElementType> *GetElementDoubleChainList(int searchkey);
		//��˫�������в��ҹؼ���Ϊsearchkey������Ԫ�أ�����result�У���̬������
		bool InsertElementDoubleChainList(int k,ElementType &newvalue);
		//����Ԫ��
		bool DeleteElementDoubleChainList(int k);
		//ɾ��˫�������е�K������Ԫ��
		void	DisplayDoubleChainList(DoubleChainList<HeadType, ElementType> &AppList);
	//��ʾ������Ա��е���������Ԫ�ص�ֵ
		void    DisplayDoubleChainNode(ElementType result);
		//��ʾ����Ԫ��

		bool  findbeforeAndAfter(int searchkey,int x,int y);
		//����ĳһѧ��x����ͬʱ�ҵ���ѧ����X��ǰ����ѧ����Ϣ���Լ���ѧ����Y����̵�ѧ����Ϣ������x, X��Y�Ӽ�������


	private:
		DoubleHeadNode<HeadType>  *HeadPtr;    //��ͷ����ָ��
		
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
	{//ɾ�������������ݽ�㣬���ͷſռ�
		current = current->nlink;
		delete HeadPtr->first;
		HeadPtr->first = current;
	}
	delete HeadPtr;  //ɾ����ͷ���
}


template <class HeadType,class ElementType>
int DoubleChainList<HeadType,ElementType>::
LengthDoubleChainList() const
{
	DoubleChainNode<ElementType>   *current = HeadPtr->first;
	int len = 0;
	while(current)
	{//�ƽ�ָ�룬������
		len++;
		current = current->nlink;
	}
	return len;
}

template <class HeadType,class ElementType>
DoubleChainNode<ElementType>  *DoubleChainList<HeadType,ElementType>::
GetElementDoubleChainList(int searchkey)
{//���ҹؼ���Ϊsearchkey��Ԫ��
//����ҵ�������Ԫ�����ڵĵ�ַ�����δ�ҵ�������NULL
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
{//��˫�������еĵ�K��Ԫ�غ����ֵΪnewvalue����Ԫ��
	if(k<0) return false;   //�粻���ڵ�K��Ԫ�أ�return false
	DoubleChainNode<ElementType>  *current=HeadPtr->first;
	int index = 1;
	while(index<k && current)
	{//���ҵ�K�����
		index++;
		current = current->nlink;
	}
    if(k>0 && !current) return false;   

	DoubleChainNode<ElementType>   *q = new DoubleChainNode<ElementType>;
	q->data = newvalue;

	if(k)
	{//������current֮��currentָ�������м�Ľ��
		q->nlink = current->nlink;
		q->plink = current;
		DoubleChainNode<ElementType>   *p=current->nlink;
		if(p)					//���PΪNULL��Q��Ϊ���һ������
			p->plink = q;		//�½��ĺ��ָ��ָ���½��
		
		current->nlink = q;		//���������ָ��ָ���½��
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
{//ɾ����K�����
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
			q = q->nlink;			//qָ���K-1�����
		}
		if(!q)
			return false;
		//qΪ�գ������ڵ�K-1����㣬q->nlinkΪ�գ������ڵ�K�����
		current = q;     //currentָ���K�����
		q = current->plink;
		p =current->nlink;
		q->nlink = p;
		if(p)					//pΪ��ʱ��ɾ���Ĳ������һ�����
			p->plink = q;
	}
	delete current;    //�ͷű�ɾ�����current �Ŀռ�
	return true;
}

template <class HeadType,class ElementType>
void DoubleChainList<HeadType,ElementType>::
DisplayDoubleChainList(DoubleChainList<HeadType, ElementType> &AppList)
{// ����������е���������Ԫ�أ����㷨������ģ����SimpleChainList
 // �㷨�Ĳ���������ģ��SimpleChainList���ͣ�����ʵ����ʹ�����ñ�����
	DoubleHeadNode<HeadType>    *HEADPTR = GetHeadPtrDoubleChainList();
	DoubleChainNode<ElementType>	*current = HEADPTR->first;

	cout<<"\n\n";
	cout<<" ����������������������������������"<<endl;
	cout<<" ��     ѧ����    ��"<<endl;
	cout<<" �������������������Щ�������������"<<endl;
	cout<<" ��        ��      ��"<<endl;
	cout<<" ��ѧ    �ũ��� �� ��"<<endl;
	cout<<" ��������������������"<<endl;
	cout<<" ��������������-���੤������������"<<endl;

	for (int i = 1; i <= AppList.LengthDoubleChainList(); i++)
	{
		cout<<" ��  "<<current->data.num;  
		cout<<"     ��    "<<current->data.name<<"��"<<endl;
		cout<<" �������������������੤������������"<<endl;
		current = current->nlink;
	}



	
	cout<<endl<<endl<<endl;
}


template <class HeadType,class ElementType>
void DoubleChainList<HeadType,ElementType>::
DisplayDoubleChainNode(ElementType result)
{//��ʾ����Ԫ��
	cout<<"ѧ����"<<result.num<<"    ";
	cout<<"������"<<result.name<<endl;
}



template <class HeadType,class ElementType>
bool DoubleChainList<HeadType,ElementType>::
findbeforeAndAfter(int searchkey,int x,int y)
{//�ҵ�ѧ��Ϊsearchkey��Ԫ�ص�ǰX��Ԫ�أ��ͺ�Y��Ԫ��
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
		cout<<"ǰ"<<x<<"�����ҵ�"<<endl;
		DisplayDoubleChainNode(p->data);
		
	}
	else
		cout<<"ǰ"<<x<<"��δ�ҵ�"<<endl;
	
	for(j=0; j<y && q; j++)
	{
		q = q->nlink;
	}

	if(q)
	{	
		cout<<"��"<<y<<"�����ҵ�"<<endl;
		DisplayDoubleChainNode(q->data);
	}
	else
		cout<<"��"<<x<<"��δ�ҵ�"<<endl;

	if(q || p)
		return true ;
	else
		return false;

	
}