
#include <iostream>
using namespace std;
#define Average key          //把平均成绩作为了查找、删除关键字

typedef struct 
{
	int 	No;		//学号
	char 	Name[10];//	姓名
	float 	CPMark;//计算机基础
	float 	DSMark;	//数据结构
	float 	PGMark;//程序设计
	float 	Average;//平均成绩
}Student;

typedef Student ElementType;




//************分类二叉树******************
typedef struct  TreeNode
{
	ElementType data;
	TreeNode *LChild;
	TreeNode *RChild;
}BinaryTreeNode;

BinaryTreeNode *MakeNode(ElementType &newvalue)
{//构造二叉树结点
	BinaryTreeNode *ptr;
	ptr = new BinaryTreeNode;
	if(!ptr) return NULL;
	ptr->data = newvalue;
	ptr->LChild = NULL;
	ptr->RChild = NULL;
	return ptr;
}

void MakeBinaryTree(BinaryTreeNode *root,BinaryTreeNode *left,BinaryTreeNode *right)
{//构造二叉树
	root->LChild = left;
	root->RChild = right;
}

void NodesCount(BinaryTreeNode *BTroot,int &count)
{//二叉树共有几个结点
	if(BTroot)
	{
		count++;
		NodesCount(BTroot->LChild,count);
		NodesCount(BTroot->RChild,count);
	}
}

int Height(BinaryTreeNode *BTroot)
{//二叉树的高度
	if(!BTroot) return 0;
	int HighL = Height(BTroot->LChild);
	int HighR = Height(BTroot->RChild);
	if(HighL>HighR)
		return ++HighL;
	else
		return ++HighR;
}

void InOrderRecurseive(BinaryTreeNode *BTroot)
{//中序遍历
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
{//查找关键字为SearKey的结点值result,定义平均成绩为查找对象
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
{//插入函数，要求出现不同的值，插入结点X
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
				return false;        //重复出现，即相同值结点出现
	}

	//找到插入点，为newvalue申请一个空间填入其值，并将该结点链接至parent
	BinaryTreeNode *q = new BinaryTreeNode;
	q->data = newvalue;
	q->LChild = NULL;
	q->RChild = NULL;
	if(BTroot)
	{//原树非空
		if(newvalue.key < parent->data.key)
			parent->LChild = q;
		else
			parent->RChild = q;
	}
	else
		BTroot = q;  //插入到空树中
	return true;
}


BinaryTreeNode *Delete(BinaryTreeNode *BTroot,int &SearchKey)
{//删除关键字为SearchKey的结点
	BinaryTreeNode *p = BTroot, *parent = NULL;
	BinaryTreeNode *son,  *ps;  //*ps指向son 的双亲
	while(p && p->data.key != SearchKey)
	{//查找删除结点p
		parent = p;
		if(SearchKey < p->data.key)
			p = p->LChild;
		else 
			p = p->RChild;
	}
	if(!p)         //P为空时，不存在删除结点
	{
		cout<<"****木有删除的结点！*****"<<endl;
		return BTroot;
	}
	//重构分类二叉树
	if(p->LChild && p->RChild )
	{//被删除结点存在两个子树，在P的左子树中查找最大元素（最右子孙）【也可以在右子树中查找最小元素（最左子孙）】
	 //并用此结点值替换被删除结点的值
		//替换后，将删除操作改变为删除找到的最大元素（最右子孙）
		son = p->LChild ;
		ps = p;
		while(son->RChild )
		{//son推进到P左子树中最大元素（最右子孙）
			ps = son;
			son = son->RChild ;
		}
		p->data = son->data;  //左子树中最大元素（最右子孙）移植到P
		p = son;   
		parent = ps;
		//被删除结点转化为左子树中的最大元素
		//所以P指向左子树中的最大元素，parent指向son的双亲
	}
	if(p->LChild )   //P最多只有一个孩子
		son = p->LChild;
	else                      //被删结点P存在右孩子或叶子结点
		son = p->RChild;      //被删结点P是叶子结点时，son的值为空
	if(p == BTroot)
		BTroot = son;
	else             
	{//判断P是parent左孩子还是右孩子
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
{//将堆中数据初始化为一个最大堆
	for(int i=HeapSize/2; i>=1; i--)
	{//从最后一个结点的根开始，直到第一个结点
		heap[0] = heap[i];       //将子树根节点复制到工作区间HEAP【0】中
		int son = 2*i;    //son首先指向I的左孩子
		while(son <= HeapSize)
		{//找到左右孩子中较大的结点
			if(son < HeapSize && heap[son].key < heap[son+1].key )
				son++;
			//son < HeapSize时，存在右孩子，如左孩子小于右孩子，son指向右孩子
			if(heap[0].key >= heap[son].key )
				break;
			//大孩子再与工作中结点值再作比较
			heap[son/2] = heap[son];  //将大孩子移至双亲的位置
			son *= 2;   //son 下移一层到上移的结点（大孩子）位置
		}
		heap[son/2] = heap[0];
	}
	return true;
}

bool InsertMaxHeap(ElementType heap[],int HeapSize,ElementType &newvalue)
{//插入值为X的结点到最大堆中，MaxSize是数组空间最大容量
//if(HeapSize == MaxSize)
	//return false            ?????????????
	int i = ++HeapSize;         //i 的初值设为堆的元素个数
	while(i != 1 && newvalue.key > heap[i/2].key)
	{//寻找NEWVALUE的插入点
		heap[i] = heap[i/2];  //i位置的双亲i/2的结点下移
		i = i/2;               //i 指向i的双亲的i/2的位置,i上移
	}
	heap[i] = newvalue;  //newvalue存入找到的插入位置
	return true;
}


bool DeleteMaxHeap(ElementType heap[],int HeapSize,ElementType &result)
{//删除最大堆中栈顶
	int parents,son;
	if(HeapSize == 0) return false;  //堆空，返回
	result = heap[1];        //堆顶最大结点存放到result带出
	heap[0] = heap[HeapSize--];       //最后一个结点存放到heap[0]，调整堆中元素的个数
	parents = 1;    //parents首先指向堆顶
	son = 2*parents;   //son指向parents 的左孩子
	while(son <= HeapSize)
	{
		if(son < HeapSize && heap[son].key < heap[son+1].key)
			son++;
		if(heap[0].key >= heap[son].key)
			break;
		heap[parents] = heap[son]; //son 的位置上升到parents
		parents = son;   //下移双亲结点指针parents，继续比较
		son = parents * 2;
	}
	heap[parents] = heap[0];  //临时空间heap【0】存入调整出来的位置
	return true;
}


void HEAPSORT(ElementType heap[],int heapsize)
{//利用堆对heap【1：heapsize】数组中的数据进行排序
	ElementType temp;
	InitializeMaxHeap(heap,heapsize);         //初始化为最大堆
	for(int i = heapsize-1; i>=1;i--)//i+1的值为当前堆的大小
	{
		DeleteMaxHeap(heap,i+1,temp);
		heap[i+1] = temp; // temp是删除堆顶带回的元素并存入最后
	}
}