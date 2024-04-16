

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
	

	//遍历算法，递归
	void PreOrderRecursive(BinaryTreeNode *BTroot);
	void InOrderRecursive(BinaryTreeNode *BTroot);
	void PostOrderRecursive(BinaryTreeNode *BTroot);
	
	BinaryTreeNode *MakeNode(ElementType& newvalue);  //构造结点
	BinaryTreeNode *DeleteBinaryTree(BinaryTreeNode *BTroot);  
	void MakeBinaryTree(BinaryTreeNode *root,
						BinaryTreeNode *left, 
						BinaryTreeNode *right);//构造一棵二叉子树 
	void NodesCount(BinaryTreeNode *BTroot,int&count);  //二叉树的结点计数
	int  Height(BinaryTreeNode  *BTroot); //计算二叉树高度


	bool SearchElementSortBinaryTree(BinaryTreeNode *BTroot,ElementType &result, int &SearchKey);
	//求查找关键字为SearchKey的结点值result
	bool InsertElementSortBinaryTree (BinaryTreeNode *BTroot,ElementType &newvalue);
	//求如果不重复出现，则插入结点x
	BinaryTreeNode *DeleteElementSortBinaryTree_FromLeftTreeUpMaxNode (BinaryTreeNode *BTroot,int &SearchKey);
	
	
    void DisplayNode(BinaryTreeNode  *BTroot);

   private:
		BinaryTreeNode 	*BTroot;//指向二叉树根结点<ElementType>


};

template<class ElementType>
BinaryTreeNode* BinaryTree<ElementType>::
MakeNode(ElementType& newvalue)
{// 构造结点
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
{// 联接root，left, right所指的结点指针为二叉树
	root ->LChild=left;
	root ->RChild=right;
}

template<class ElementType>
int  BinaryTree<ElementType>::
Height(BinaryTreeNode  *BTroot) 
{// 返回二叉树的高度
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
{//二叉树的结点计数
	if (BTroot) 
	{
		count++;		//二叉树的结点计数
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

//遍历算法——递归
template<class ElementType>
void BinaryTree<ElementType>::
PreOrderRecursive(BinaryTreeNode *BTroot)
{//二叉树的前序遍历递归算法
	if (BTroot) 
	{
//		Visit(BTroot); 		//访问二叉树的结点
		DisplayNode(BTroot);
		PreOrderRecursive(BTroot->LChild);
		PreOrderRecursive(BTroot->RChild);
	}
}

template<class ElementType>
void BinaryTree<ElementType>::
InOrderRecursive(BinaryTreeNode *BTroot)
{//二叉树的中序遍历递归算法
	if (BTroot) 
	{
		InOrderRecursive(BTroot->LChild);
//		Visit(BTroot); 		//访问二叉树的结点
		DisplayNode(BTroot);
		InOrderRecursive(BTroot->RChild);
	}
}

template<class ElementType>
void BinaryTree<ElementType>::
PostOrderRecursive(BinaryTreeNode *BTroot)
{//二叉树的后序遍历递归算法
	if (BTroot) 
	{
		PostOrderRecursive(BTroot->LChild);
		PostOrderRecursive(BTroot->RChild);
//		Visit(BTroot); 		//访问二叉树的结点
		DisplayNode(BTroot);
	}
}


template<class ElementType>
bool BinaryTree<ElementType>::
SearchElementSortBinaryTree(BinaryTreeNode *BTroot,ElementType &result, int &SearchKey)
{//求查找关键字为SearchKey的结点值result
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
{//求如果不重复出现，则插入结点x
	BinaryTreeNode  *p = BTroot;
	BinaryTreeNode  *parent = NULL;		//指向p的双亲
	while (p) 
	{
		parent = p;
		if (newvalue.key< p->data.key) 
			p = p->LChild;
		else 
		if (newvalue.key > p->data.key) 
			p = p->RChild;
		else 
			return false;			//重复出现，即相等值结点出现
	}

	// 找到插入点，为newvalue申请一个空间填入其值，并将该结点连接至 parent 
	BinaryTreeNode  *q = new BinaryTreeNode;
	q ->data = newvalue;
	q->LChild=NULL;
	q->RChild=NULL;
	if (BTroot) 
	{// 原树非空
		if (newvalue.key < parent ->data.key)
			parent ->LChild = q;
		else 
			parent ->RChild = q;
	}
	else // 插入到空树中
		BTroot = q;
	return true;
}

template<class ElementType>
BinaryTreeNode * BinaryTree<ElementType>::
DeleteElementSortBinaryTree_FromLeftTreeUpMaxNode (BinaryTreeNode *BTroot,
 int &SearchKey)
{// 删除关键字值为SearchKey 的结点
	BinaryTreeNode    *p = BTroot, 	*parent = NULL; // parent指向p的双亲
	BinaryTreeNode    *son, 	*ps;  				// ps指向son的双亲
	while (p && p->data.key != SearchKey)
	{// 查找删除结点p
		parent = p;
		if (SearchKey < p->data.key) 
			p = p->LChild;
		else 
			p = p->RChild;
	}
	if (!p)								 // p为空时，不存在删除结点
	{
		cout<<"****没有删除结点!******"<<endl;
		return  BTroot; 
	}
	// 对分类二叉树重构
	if (p->LChild && p->RChild) 
	{// 被删除结点存在两个子树,在p的左子树中查找最大元素（最右子孙），
// 并用此结点值替换被删除结点的值。
	 // 替换后，将删除操作改变为删除找到的最大元素（最右子孙）。
		son = p->LChild;
		ps = p;
		while (son->RChild) 
		{// son推进到p的左子树中最大元素（最右子孙）
			 ps = son;
			 son = son->RChild;
		}
		p->data = son->data; 	//左子树中最大元素（最右子孙）值移到p
		p = son;
		parent = ps;				
		//被删结点转换为左子树中最大元素，
//所以p指向左子树中最大元素, parent指向son的双亲
	}
	if (p->LChild)  					// p最多只有一个孩子
		son = p->LChild;
	else								//被删结点p存在右孩子或是叶子结点
		son = p->RChild;				//被删结点p是叶子结点时，son值为空
	if (p == BTroot)					//被删结点p是根
		BTroot = son;
	else 
	{// 判断p是parent左孩子，还是右孩子
		if (p == parent->LChild)
			parent->LChild = son;
		else 
			parent->RChild = son;
	}
	delete p;
	return BTroot;
}


