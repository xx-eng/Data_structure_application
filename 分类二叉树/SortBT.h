
#include <iostream>
using namespace std;
#define Average key          //��ƽ���ɼ���Ϊ�˲��ҡ�ɾ���ؼ���

typedef struct 
{
	int 	No;		//ѧ��
	char 	Name[10];//	����
	float 	CPMark;//���������
	float 	DSMark;	//���ݽṹ
	float 	PGMark;//�������
	float 	Average;//ƽ���ɼ�
}Student;

typedef Student ElementType;




//************���������******************
typedef struct  TreeNode
{
	ElementType data;
	TreeNode *LChild;
	TreeNode *RChild;
}BinaryTreeNode;

BinaryTreeNode *MakeNode(ElementType &newvalue)
{//������������
	BinaryTreeNode *ptr;
	ptr = new BinaryTreeNode;
	if(!ptr) return NULL;
	ptr->data = newvalue;
	ptr->LChild = NULL;
	ptr->RChild = NULL;
	return ptr;
}

void MakeBinaryTree(BinaryTreeNode *root,BinaryTreeNode *left,BinaryTreeNode *right)
{//���������
	root->LChild = left;
	root->RChild = right;
}

void NodesCount(BinaryTreeNode *BTroot,int &count)
{//���������м������
	if(BTroot)
	{
		count++;
		NodesCount(BTroot->LChild,count);
		NodesCount(BTroot->RChild,count);
	}
}

int Height(BinaryTreeNode *BTroot)
{//�������ĸ߶�
	if(!BTroot) return 0;
	int HighL = Height(BTroot->LChild);
	int HighR = Height(BTroot->RChild);
	if(HighL>HighR)
		return ++HighL;
	else
		return ++HighR;
}

void InOrderRecurseive(BinaryTreeNode *BTroot)
{//�������
	if(BTroot)
	{
		InOrderRecurseive(BTroot->LChild);
		cout<<"  "<<BTroot->data.No<<"  "<<BTroot->data.Name<<"      "
			<<BTroot->data.CPMark<<"        "<<BTroot->data.DSMark<<"         "
			<<BTroot->data.PGMark<<"       "<<BTroot->data.key<<endl;
		InOrderRecurseive(BTroot->RChild);
	}
}

bool Search(BinaryTreeNode *BTroot,ElementType &result,int &SearchKey)
{//���ҹؼ���ΪSearKey�Ľ��ֵresult,����ƽ���ɼ�Ϊ���Ҷ���
	BinaryTreeNode *p = BTroot;
	while(p)
	{
		if(SearchKey < p->data.key)
			p = p->LChild;
		else
			if(SearchKey > p->data.key)
				p = p->RChild;
			else
			{
				result = p->data;
				return true;
			}
	}
	return false;
}


bool Insert(BinaryTreeNode *BTroot,ElementType &newvalue)
{//���뺯����Ҫ����ֲ�ͬ��ֵ��������X
	BinaryTreeNode *p = BTroot;
	BinaryTreeNode *parent = NULL;
	while(p)
	{
		parent = p;
		if(newvalue.key < p->data.key)
			p = p->LChild;
		else
			if(newvalue.key > p->data.key)
				p = p->RChild;
			else 
				return false;        //�ظ����֣�����ֵͬ������
	}

	//�ҵ�����㣬Ϊnewvalue����һ���ռ�������ֵ�������ý��������parent
	BinaryTreeNode *q = new BinaryTreeNode;
	q->data = newvalue;
	q->LChild = NULL;
	q->RChild = NULL;
	if(BTroot)
	{//ԭ���ǿ�
		if(newvalue.key < parent->data.key)
			parent->LChild = q;
		else
			parent->RChild = q;
	}
	else
		BTroot = q;  //���뵽������
	return true;
}


BinaryTreeNode *Delete(BinaryTreeNode *BTroot,int &SearchKey)
{//ɾ���ؼ���ΪSearchKey�Ľ��
	BinaryTreeNode *p = BTroot, *parent = NULL;
	BinaryTreeNode *son,  *ps;  //*psָ��son ��˫��
	while(p && p->data.key != SearchKey)
	{//����ɾ�����p
		parent = p;
		if(SearchKey < p->data.key)
			p = p->LChild;
		else 
			p = p->RChild;
	}
	if(!p)         //PΪ��ʱ��������ɾ�����
	{
		cout<<"****ľ��ɾ���Ľ�㣡*****"<<endl;
		return BTroot;
	}
	//�ع����������
	if(p->LChild && p->RChild )
	{//��ɾ��������������������P���������в������Ԫ�أ����������Ҳ�������������в�����СԪ�أ����������
	 //���ô˽��ֵ�滻��ɾ������ֵ
		//�滻�󣬽�ɾ�������ı�Ϊɾ���ҵ������Ԫ�أ��������
		son = p->LChild ;
		ps = p;
		while(son->RChild )
		{//son�ƽ���P�����������Ԫ�أ��������
			ps = son;
			son = son->RChild ;
		}
		p->data = son->data;  //�����������Ԫ�أ����������ֲ��P
		p = son;   
		parent = ps;
		//��ɾ�����ת��Ϊ�������е����Ԫ��
		//����Pָ���������е����Ԫ�أ�parentָ��son��˫��
	}
	if(p->LChild )   //P���ֻ��һ������
		son = p->LChild;
	else                      //��ɾ���P�����Һ��ӻ�Ҷ�ӽ��
		son = p->RChild;      //��ɾ���P��Ҷ�ӽ��ʱ��son��ֵΪ��
	if(p == BTroot)
		BTroot = son;
	else             
	{//�ж�P��parent���ӻ����Һ���
		if(p == parent->LChild)
			parent->LChild = son;
		else 
			parent->RChild = son;
	}
	delete p;
	return BTroot;

}
//***********************************************

bool InitializeMaxHeap(ElementType heap[],int HeapSize)
{//���������ݳ�ʼ��Ϊһ������
	for(int i=HeapSize/2; i>=1; i--)
	{//�����һ�����ĸ���ʼ��ֱ����һ�����
		heap[0] = heap[i];       //���������ڵ㸴�Ƶ���������HEAP��0����
		int son = 2*i;    //son����ָ��I������
		while(son <= HeapSize)
		{//�ҵ����Һ����нϴ�Ľ��
			if(son < HeapSize && heap[son].key < heap[son+1].key )
				son++;
			//son < HeapSizeʱ�������Һ��ӣ�������С���Һ��ӣ�sonָ���Һ���
			if(heap[0].key >= heap[son].key )
				break;
			//�������빤���н��ֵ�����Ƚ�
			heap[son/2] = heap[son];  //����������˫�׵�λ��
			son *= 2;   //son ����һ�㵽���ƵĽ�㣨���ӣ�λ��
		}
		heap[son/2] = heap[0];
	}
	return true;
}

bool InsertMaxHeap(ElementType heap[],int HeapSize,ElementType &newvalue)
{//����ֵΪX�Ľ�㵽�����У�MaxSize������ռ��������
//if(HeapSize == MaxSize)
	//return false            ?????????????
	int i = ++HeapSize;         //i �ĳ�ֵ��Ϊ�ѵ�Ԫ�ظ���
	while(i != 1 && newvalue.key > heap[i/2].key)
	{//Ѱ��NEWVALUE�Ĳ����
		heap[i] = heap[i/2];  //iλ�õ�˫��i/2�Ľ������
		i = i/2;               //i ָ��i��˫�׵�i/2��λ��,i����
	}
	heap[i] = newvalue;  //newvalue�����ҵ��Ĳ���λ��
	return true;
}


bool DeleteMaxHeap(ElementType heap[],int HeapSize,ElementType &result)
{//ɾ��������ջ��
	int parents,son;
	if(HeapSize == 0) return false;  //�ѿգ�����
	result = heap[1];        //�Ѷ�������ŵ�result����
	heap[0] = heap[HeapSize--];       //���һ������ŵ�heap[0]����������Ԫ�صĸ���
	parents = 1;    //parents����ָ��Ѷ�
	son = 2*parents;   //sonָ��parents ������
	while(son <= HeapSize)
	{
		if(son < HeapSize && heap[son].key < heap[son+1].key)
			son++;
		if(heap[0].key >= heap[son].key)
			break;
		heap[parents] = heap[son]; //son ��λ��������parents
		parents = son;   //����˫�׽��ָ��parents�������Ƚ�
		son = parents * 2;
	}
	heap[parents] = heap[0];  //��ʱ�ռ�heap��0���������������λ��
	return true;
}


void HEAPSORT(ElementType heap[],int heapsize)
{//���öѶ�heap��1��heapsize�������е����ݽ�������
	ElementType temp;
	InitializeMaxHeap(heap,heapsize);         //��ʼ��Ϊ����
	for(int i = heapsize-1; i>=1;i--)//i+1��ֵΪ��ǰ�ѵĴ�С
	{
		DeleteMaxHeap(heap,i+1,temp);
		heap[i+1] = temp; // temp��ɾ���Ѷ����ص�Ԫ�ز��������
	}
}