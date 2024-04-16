#include "AppData.h"

template<class HeadType>class SimpleHeadNode;
template<class HeadType,class ElementType>class SimpleChainList;

template<class ElementType>
class SimpleChainNode
{//����������Ԫ�ؽ��ṹ�ඨ��
	//friend SimpleChainList <class HeadType,class ElementType>;
	public:
		ElementType						data;
		SimpleChainNode<ElementType>		*link;
};

template<class HeadType>
class SimpleHeadNode
{//�������ͷ����Ԫ�ؽ��ṹ�ඨ��
	//friend SimpleChainList <class HeadType,class ElementType>;
	public:
		HeadType									Hdata;
		SimpleChainNode<class ElementType>		*first;
};



template<class HeadType,class ElementType>
class SimpleChainList
{//���Ա���ʽ�洢�ṹ-������ģ���� SimpleChainList�Ķ���
	public:
	SimpleChainList();					//���캯��
	~SimpleChainList();					//��������
	int	LengthSimpleChainList() const ;	//���������
	void  PutValueSimpleHeadNode(HeadType &headValue)
	{HeadPtr->Hdata=headValue;};	//��ֵ֪headValue����ͷ���Hdata��ֵ
	SimpleHeadNode<HeadType> * GetHeadPtrSimpleChainList(){return HeadPtr;};
		//HeadPtr�����������ͷ��ָ��HeadPtr
	SimpleChainNode<ElementType> * GetFirstPtrSimpleChainList()
	{return HeadPtr->first;};//��ȡ�������е�һ�����ָ��firstֵ

//*****���Һ���
	bool GetElementSimpleChainList(int k,ElementType &result);
	//����:�������в��ҵ�k��Ԫ�أ�����result�У���̬����
	bool GetElementSimpleChainList(SimpleChainNode<ElementType> *current,
ElementType &result);
	//����:�������в���currentָ����ָ������Ԫ�أ�����result�У���̬����
	SimpleChainNode<ElementType> * SearchElementSimpleChainList(int searchkey);
	//���ң����ҹؼ���ֵΪsearchkey(��ֵ��)��Ԫ�أ�����Ԫ��λ�ã�ָ�룩
SimpleChainNode<ElementType> *SearchElementSimpleChainList(char* searchkey);
	//���ң����ҹؼ���ֵΪsearchkey(�ַ���)��Ԫ�أ�����Ԫ��λ�ã�ָ�룩

//*******���롢ɾ������
	bool	InsertElementSimpleChainList(int k, ElementType &newvalue );
	//���룺����ֵΪnewvalueԪ�ص��������е�k������Ԫ��֮��
	bool	InsertElementFrontSimpleChainList(ElementType &newvalue ,
 SimpleChainNode<ElementType>	* InsertPtr);
	//����Ԫ�أ�����ֵΪnewvalueԪ�ص���������InsertPtrָ����ָ����Ԫ��֮ǰ
	bool	DeleteElementSimpleChainList( int k );
	//ɾ��Ԫ�أ�ɾ���������е�k������Ԫ�أ���̬������
	bool	DeleteElementSimpleChainList(SimpleChainNode<ElementType> 
* DeletePtr );  
	//ɾ��Ԫ�أ�ɾ����������DeletePtrָ����ָ����Ԫ�أ���̬������
	
	
	void	DisplaySimpleChainList(SimpleChainList<HeadType,ElementType>
 &AppList );
	//��ʾ����������������Ԫ�ص�ֵ
	void	DisplayElementSimpleChainList(ElementType result);
			//��ʾ������������Ԫ��result��ֵ




	bool MovelElementFirstSimpleChainList(int k);
	//�ڼ������н���K������Ԫ�������������

	void InvertSimpleChainList();
    //�Լ������������
     
	
	private:
		SimpleHeadNode<HeadType>	*HeadPtr;			//��ͷ����ָ��
};


template<class HeadType,class ElementType>
SimpleChainList<HeadType,ElementType>::
SimpleChainList()
{
	//���캯�����������Ա�ռ��СMaxSize��
    //����Ԫ�ؿռ�element���������Ա��ȳ�ֵlength
	HeadPtr=new SimpleHeadNode<HeadType>;
	HeadPtr->first=NULL;
}

template<class HeadType,class ElementType>
SimpleChainList<HeadType,ElementType>::
~SimpleChainList()
{//����������ɾ���������������ݽ�㼰��ͷ��㣬���ͷŽ��ռ�
	SimpleChainNode<ElementType> 	* current;
	current =HeadPtr->first;
	while (HeadPtr->first)
	{// ɾ���������������ݽ�㣬���ͷŽ��ռ�
		current = current ->link;
		delete HeadPtr->first;
		HeadPtr->first = current;
	}
	delete HeadPtr;
}

template<class HeadType,class ElementType>
int SimpleChainList<HeadType,ElementType>::
LengthSimpleChainList() const
{//�������������Ԫ�ؽ�����������ȣ�
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
{ //�������k��Ԫ��ֵȡ��result�д��ء��粻���ڷ���false�����ڷ���true
	if (k < 1) return false;
	SimpleChainNode<ElementType>  	*current = HeadPtr->first;
	int 		index = 1; 
	while (index < k && current)
	{//���ҵ�k������Ԫ��
		current = current->link;
		index++;
	}
	if (current)
	{
		result = current->data;
		return true;
	}
	return false; 		// kֵ̫�󣬲����ڵ�k�����
}

template<class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
GetElementSimpleChainList(SimpleChainNode<ElementType> *current,ElementType &result)
{ //�������k��Ԫ��ֵȡ��result�д��ء��粻���ڷ���false�����ڷ���true
	if (!current) return false;
		result = current->data;
		return true;
}

template<class HeadType,class ElementType>
SimpleChainNode<ElementType> * SimpleChainList<HeadType,ElementType>::
SearchElementSimpleChainList(int searchkey)	//char *searchkey
{// �������в�������Ԫ�عؼ���Ϊsearchkey�����䣩��Ԫ��
 //����ҵ�����Ԫ�����ڵĵ�ַ�����δ�ҵ�����NULL 
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
{// �������в�������Ԫ�عؼ���Ϊsearchkey�����䣩��Ԫ��
 //����ҵ�����Ԫ�����ڵĵ�ַ�����δ�ҵ�����NULL 
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
{// �ڼ������е�k������Ԫ��֮���в�����Ԫ�أ�ֵΪnewvalue��
 // ��������ڵ�k��Ԫ�أ��򷵻�false
	if (k < 0) return false;
	int			index = 1;
	SimpleChainNode<ElementType>	*current = HeadPtr->first;
	while  (index < k && current)
	{//���ҵ�k�����
		index++;
		current = current ->link;
	}
	if (k > 0 && ! current) return false;
	SimpleChainNode<ElementType>   *q = new SimpleChainNode<ElementType>;
	q->data = newvalue;
	if (k)
	{// ������current ֮��
		q->link = current ->link;
		current ->link = q;
	}
	else 
	{// ��Ϊ��һ��Ԫ�ؽ�����
		q->link = HeadPtr->first;
		HeadPtr->first = q;
	}
	return true;
}





template<class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
InsertElementFrontSimpleChainList(ElementType &newvalue  , SimpleChainNode<ElementType> * InsertPtr)
{// �ڼ�������InsertPtrָ����ָ����Ԫ��֮ǰ�в�����Ԫ�أ�ֵΪnewvalue��
	if (!InsertPtr) 
		return false;
		
	SimpleChainNode<ElementType>	*current = HeadPtr->first;
	if(InsertPtr!= HeadPtr->first)
	{//InsertPtr����ͷ���ָ��ʱ���ƽ�ָ��currentֱ��current=InsertPtr�����ҽ�㡣
		while  (current && current->link!=InsertPtr)
		{//����InsertPtrָ��ָ��Ľ��
			current = current ->link;
		}
		if (! current) return false;//currentΪNULL������ʧ�ܣ������ڴ˽��
	}
	SimpleChainNode<ElementType>   *q = new SimpleChainNode<ElementType>;
//������������ݿռ�
	q->data = newvalue;		//������ֵ��ֵ�����ݿռ���
	if (InsertPtr== HeadPtr->first) 
	{// InsertPtr== HeadPtr->firstʱ����Ϊ��һ��Ԫ�ؽ�����
		q->link= HeadPtr->first;
		HeadPtr->first=q;
	}
	else
	{// InsertPtr��= HeadPtr->firstʱ��������current ֮��
		q->link = current ->link;
		current ->link = q;
	}
	return true;
}

template<class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
DeleteElementSimpleChainList( int k )
{// �ڼ򵥱���ɾ����k������Ԫ��,��������ڵ�k��Ԫ�ط���false
	if (k < 1 || ! HeadPtr->first)	//kֵ̫С������Ϊ��
		return false;
	SimpleChainNode<ElementType>   * current = HeadPtr->first;
	if (k == 1)						// ɾ�����������е�һ�����
		HeadPtr->first = current->link; 
	else 
	{ 
		SimpleChainNode<ElementType>   *q = HeadPtr->first;
		for (int index = 1; index < k - 1 && q ; index++)
			q = q->link;       		// q ָ���k-1�����
		if (!q || !q->link)	
//qΪ��ʱ�������ڵ�k-1����㣻q->linkΪ��ʱ�������ڵ�k�����
			return false; 
		current = q->link;      	// current ָ���k�����
		q->link = current ->link; 
	}
	delete current;          		// �ͷű�ɾ�����current�Ŀռ�
	return true;
}

template<class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
DeleteElementSimpleChainList( SimpleChainNode<ElementType> * DeletePtr )
{// �ڼ򵥱���ɾ��DeletePtrָ����ָ����Ԫ��,��������ڷ���false
	if (! HeadPtr->first)		
		return false;
		
	if (DeletePtr == HeadPtr->first)
	{// DeletePtr == firstʱ��ɾ�����������е�һ�����
		HeadPtr->first = DeletePtr->link; 
		return true;
	}
	else 
	{ 
		SimpleChainNode<ElementType>   *q = HeadPtr->first;
		while (q->link!=DeletePtr && q)	// �ƽ�q��ָ��DeletePtrָ�����ǰ��	
			q = q->link;       		
		if (!q )	//qΪ��ʱ��������DeletePtrָ���㣬����ʧ�ܡ�
			return false; 
		q->link = DeletePtr ->link;		//����
		delete DeletePtr;          		// �ͷű�ɾ��DeletePtrָ����Ŀռ�
	}
	return true;
}


template<class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
MovelElementFirstSimpleChainList(int k)
{
	if(k<1 || !HeadPtr->first)     //kֵ̫С������Ϊ��
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
			//��qΪ�գ��򲻴��ڵ�K-1����㣻��q->link�գ��򲻴��ڵ�K�����
			return false;
		current = q->link;         //currentָ���K�����
		q->link = current->link;   //ɾ����K�����
	}
	current->link = HeadPtr->first;
	HeadPtr->first = current;
	return true;
}

template<class HeadType,class ElementType>
void SimpleChainList<HeadType,ElementType>::
InvertSimpleChainList()
{
	//�Լ���������
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
{// ����������е�����Ԫ�أ����㷨������ģ����SimpleChainList
	cout<<result.number<<"    ";
	cout<<result.name<<"    ";
	cout<<result.sex<<"   ";
	cout<<result.age<<"   ";
	cout<<result.place<<endl;
}

template<class HeadType,class ElementType>
void SimpleChainList<HeadType,ElementType>::
DisplaySimpleChainList(SimpleChainList<HeadType,ElementType> &AppList )
{// ����������е���������Ԫ�أ����㷨������ģ����SimpleChainList
 // �㷨�Ĳ���������ģ��SimpleChainList���ͣ�����ʵ����ʹ�����ñ�����
	SimpleHeadNode<HeadType>    *HEADPTR = GetHeadPtrSimpleChainList();
	SimpleChainNode<ElementType>	*current = HEADPTR->first;

	cout<<"\n\n";
	cout<<" ����������������������������������������������������������������"<<endl;
	cout<<" ��     ѧ����                   ��"<<endl;
	cout<<" �������������������Щ�������������������������������������������"<<endl;
	cout<<" ��        ��      ��       ��      ��"<<endl;
	cout<<" ��ѧ    �ũ� �� ���� �� �� �� ���� ��"<<endl;
	cout<<" ��������������������       ��      ��"<<endl;
	cout<<" ��������������-���੤�����������੤�������������੤������������"<<endl;

	for (int i = 1; i <= AppList.LengthSimpleChainList(); i++)
	{
		cout<<" ��  "<<current->data.number;  
		cout<<"  �� "<<current->data.name;
		cout<<" ��   "<<current->data.sex;
		cout<<"   �� "<<current->data.age<<"   �� "<<endl;
		cout<<" �������������������੤�����������੤�������������੤������������"<<endl;
		current = current->link;
	}
}


