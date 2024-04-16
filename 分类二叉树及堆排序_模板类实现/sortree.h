

#include <iostream>
using namespace std;

class BinaryTreeNode
{
public:
	ElementType data;
	BinaryTreeNode *LChild;
	BinaryTreeNode *RChild;
};


template<class ElementType>
class BinaryTree
{
public:
	BinaryTree() {BTroot = NULL;};
	~BinaryTree() {};
	bool IsEmpty();
	

	//�����㷨���ݹ�
	void PreOrderRecursive(BinaryTreeNode *BTroot);
	void InOrderRecursive(BinaryTreeNode *BTroot);
	void PostOrderRecursive(BinaryTreeNode *BTroot);
	
	BinaryTreeNode *MakeNode(ElementType& newvalue);  //������
	BinaryTreeNode *DeleteBinaryTree(BinaryTreeNode *BTroot);  
	void MakeBinaryTree(BinaryTreeNode *root,
						BinaryTreeNode *left, 
						BinaryTreeNode *right);//����һ�ö������� 
	void NodesCount(BinaryTreeNode *BTroot,int&count);  //�������Ľ�����
	int  Height(BinaryTreeNode  *BTroot); //����������߶�


	bool SearchElementSortBinaryTree(BinaryTreeNode *BTroot,ElementType &result, int &SearchKey);
	//����ҹؼ���ΪSearchKey�Ľ��ֵresult
	bool InsertElementSortBinaryTree (BinaryTreeNode *BTroot,ElementType &newvalue);
	//��������ظ����֣��������x
	BinaryTreeNode *DeleteElementSortBinaryTree_FromLeftTreeUpMaxNode (BinaryTreeNode *BTroot,int &SearchKey);
	
	
    void DisplayNode(BinaryTreeNode  *BTroot);

   private:
		BinaryTreeNode 	*BTroot;//ָ������������<ElementType>


};

template<class ElementType>
BinaryTreeNode* BinaryTree<ElementType>::
MakeNode(ElementType& newvalue)
{// ������
	BinaryTreeNode	*ptr;
	ptr = new BinaryTreeNode;
	if  (!ptr)		return NULL;
	ptr ->data = newvalue ;
	ptr -> LChild = NULL;
	ptr -> RChild = NULL;
	return	  ptr;
}

template<class ElementType>
void  BinaryTree<ElementType>::
MakeBinaryTree(BinaryTreeNode *root, BinaryTreeNode *left, BinaryTreeNode *right)
{// ����root��left, right��ָ�Ľ��ָ��Ϊ������
	root ->LChild=left;
	root ->RChild=right;
}

template<class ElementType>
int  BinaryTree<ElementType>::
Height(BinaryTreeNode  *BTroot) 
{// ���ض������ĸ߶�
   if (!BTroot) return 0;
   int HighL = Height(BTroot ->LChild);
   int HighR = Height(BTroot ->RChild); 
   if (HighL > HighR)  
		return ++HighL;
   else 
		return ++HighR;
}

template<class ElementType>
void BinaryTree<ElementType>::
NodesCount(BinaryTreeNode *BTroot,int &count)
{//�������Ľ�����
	if (BTroot) 
	{
		count++;		//�������Ľ�����
		NodesCount(BTroot->LChild,count);
		NodesCount(BTroot->RChild,count);
	}
}


template<class ElementType>
BinaryTreeNode * BinaryTree<ElementType>::
DeleteBinaryTree(BinaryTreeNode *BTroot)
{
	if(BTroot)
	{
		DeleteBinaryTree(BTroot->LChild);
		DeleteBinaryTree(BTroot->RChild);
		delete BTroot;
	}
	BTroot = NULL;
	return BTroot;
}

template<class ElementType>
void  BinaryTree<ElementType>::
DisplayNode(BinaryTreeNode  *BTroot)
{
	cout<<"  "<<BTroot->data.No<<"  "<<BTroot->data.Name;
	cout<<"        "<<BTroot->data.CPMark<<"        "<<BTroot->data.DSMark
			<<"        "<<BTroot->data.PGMark<<"        "<<BTroot->data.key<<endl;
}

//�����㷨�����ݹ�
template<class ElementType>
void BinaryTree<ElementType>::
PreOrderRecursive(BinaryTreeNode *BTroot)
{//��������ǰ������ݹ��㷨
	if (BTroot) 
	{
//		Visit(BTroot); 		//���ʶ������Ľ��
		DisplayNode(BTroot);
		PreOrderRecursive(BTroot->LChild);
		PreOrderRecursive(BTroot->RChild);
	}
}

template<class ElementType>
void BinaryTree<ElementType>::
InOrderRecursive(BinaryTreeNode *BTroot)
{//����������������ݹ��㷨
	if (BTroot) 
	{
		InOrderRecursive(BTroot->LChild);
//		Visit(BTroot); 		//���ʶ������Ľ��
		DisplayNode(BTroot);
		InOrderRecursive(BTroot->RChild);
	}
}

template<class ElementType>
void BinaryTree<ElementType>::
PostOrderRecursive(BinaryTreeNode *BTroot)
{//�������ĺ�������ݹ��㷨
	if (BTroot) 
	{
		PostOrderRecursive(BTroot->LChild);
		PostOrderRecursive(BTroot->RChild);
//		Visit(BTroot); 		//���ʶ������Ľ��
		DisplayNode(BTroot);
	}
}


template<class ElementType>
bool BinaryTree<ElementType>::
SearchElementSortBinaryTree(BinaryTreeNode *BTroot,ElementType &result, int &SearchKey)
{//����ҹؼ���ΪSearchKey�Ľ��ֵresult
	BinaryTreeNode  *p = BTroot;
	while (p) 
		if (SearchKey < p->data.key) 
			p = p->LChild;
		else 
			if (SearchKey > p->data.key) 
				p = p->RChild;
			else 
			{ 
				result = p->data;
				return true;
			}
	return false;
}

template<class ElementType>
bool BinaryTree<ElementType>::
InsertElementSortBinaryTree (BinaryTreeNode *BTroot,ElementType &newvalue)
{//��������ظ����֣��������x
	BinaryTreeNode  *p = BTroot;
	BinaryTreeNode  *parent = NULL;		//ָ��p��˫��
	while (p) 
	{
		parent = p;
		if (newvalue.key< p->data.key) 
			p = p->LChild;
		else 
		if (newvalue.key > p->data.key) 
			p = p->RChild;
		else 
			return false;			//�ظ����֣������ֵ������
	}

	// �ҵ�����㣬Ϊnewvalue����һ���ռ�������ֵ�������ý�������� parent 
	BinaryTreeNode  *q = new BinaryTreeNode;
	q ->data = newvalue;
	q->LChild=NULL;
	q->RChild=NULL;
	if (BTroot) 
	{// ԭ���ǿ�
		if (newvalue.key < parent ->data.key)
			parent ->LChild = q;
		else 
			parent ->RChild = q;
	}
	else // ���뵽������
		BTroot = q;
	return true;
}

template<class ElementType>
BinaryTreeNode * BinaryTree<ElementType>::
DeleteElementSortBinaryTree_FromLeftTreeUpMaxNode (BinaryTreeNode *BTroot,
 int &SearchKey)
{// ɾ���ؼ���ֵΪSearchKey �Ľ��
	BinaryTreeNode    *p = BTroot, 	*parent = NULL; // parentָ��p��˫��
	BinaryTreeNode    *son, 	*ps;  				// psָ��son��˫��
	while (p && p->data.key != SearchKey)
	{// ����ɾ�����p
		parent = p;
		if (SearchKey < p->data.key) 
			p = p->LChild;
		else 
			p = p->RChild;
	}
	if (!p)								 // pΪ��ʱ��������ɾ�����
	{
		cout<<"****û��ɾ�����!******"<<endl;
		return  BTroot; 
	}
	// �Է���������ع�
	if (p->LChild && p->RChild) 
	{// ��ɾ����������������,��p���������в������Ԫ�أ����������
// ���ô˽��ֵ�滻��ɾ������ֵ��
	 // �滻�󣬽�ɾ�������ı�Ϊɾ���ҵ������Ԫ�أ����������
		son = p->LChild;
		ps = p;
		while (son->RChild) 
		{// son�ƽ���p�������������Ԫ�أ��������
			 ps = son;
			 son = son->RChild;
		}
		p->data = son->data; 	//�����������Ԫ�أ��������ֵ�Ƶ�p
		p = son;
		parent = ps;				
		//��ɾ���ת��Ϊ�����������Ԫ�أ�
//����pָ�������������Ԫ��, parentָ��son��˫��
	}
	if (p->LChild)  					// p���ֻ��һ������
		son = p->LChild;
	else								//��ɾ���p�����Һ��ӻ���Ҷ�ӽ��
		son = p->RChild;				//��ɾ���p��Ҷ�ӽ��ʱ��sonֵΪ��
	if (p == BTroot)					//��ɾ���p�Ǹ�
		BTroot = son;
	else 
	{// �ж�p��parent���ӣ������Һ���
		if (p == parent->LChild)
			parent->LChild = son;
		else 
			parent->RChild = son;
	}
	delete p;
	return BTroot;
}


