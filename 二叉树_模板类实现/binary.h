


#include "APPDATA.h"
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
	BinaryTree() {BTroot = NULL;}
	~BinaryTree() {}
	

	//遍历算法，递归
	void PreOrderRecursive(BinaryTreeNode *BTroot);
	void InOrderRecursive(BinaryTreeNode *BTroot);
	void PostOrderRecursive(BinaryTreeNode *BTroot);

	//遍历算法，非递归
	void PreOrderNoRecursive(BinaryTreeNode *BTroot);
	void InOrderNoRecursive(BinaryTreeNode *BTroot) ;
	void PostOrderNoRecursive(BinaryTreeNode *BTroot) ;

	//层次遍历
	void LevelOrder_LtoR_UtoD(BinaryTreeNode *BTroot);    //从左到右，从上到下
	void LevelOrder_RtoL_DtoU(BinaryTreeNode *BTroot);   //从右到左，从下到上

	BinaryTreeNode *MakeNode(ElementType& newvalue);  //构造结点
	BinaryTreeNode *DeleteBinaryTree(BinaryTreeNode *BTroot);  
	void MakeBinaryTree(BinaryTreeNode *root,
						BinaryTreeNode *left, 
						BinaryTreeNode *right);//构造一棵二叉子树 
	void NodesCount(BinaryTreeNode *BTroot,int&count);  //二叉树的结点计数
	int  Height(BinaryTreeNode  *BTroot); //计算二叉树高度
	int  LeafsCount(BinaryTreeNode  *BTroot); 

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
	cout<<"学号"<<BTroot->data.number<<"\t姓名"<<BTroot->data.name<<endl;
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

class StackType
{
public:
	BinaryTreeNode *ptr;
	bool          status;
};

template<class StackType>
class Stack
{
public:
	Stack(int MaxStackSize = 20);
	~Stack() {delete [] element;}
	int GetTopAddress()  {return top;}
	bool IsEmpty() {return top == -1;}
	bool IsFull() {return top >= MaxSpaceSize;}
	bool GetTop(StackType & result);
	bool Push(StackType & newvalue);
	bool Pop(StackType &result);
	bool DisplayStack();
private:
	int top;
	int MaxSpaceSize;
	StackType *element;
};

template<class StackType>
Stack<StackType>::
Stack(int MaxStackSize)
{
	MaxSpaceSize = MaxStackSize;
	element = new StackType[MaxSpaceSize];
	top = -1;
}

template<class StackType>
bool Stack<StackType>::
GetTop(StackType &result)
{
	if(IsEmpty())  return false;
	result = element[top];
	return true;
}

template<class StackType>
bool Stack<StackType>::
Push(StackType &newvalue)
{
	if(IsFull() ) return false;
	element[++top] = newvalue;
	return true;
}

template<class StackType>
bool Stack<StackType>::
Pop(StackType &result)
{
	if(IsEmpty()) return false;
	result = element[top--];
	return true;
}

template<class StackType>
bool Stack<StackType>::
DisplayStack()
{
	StackType x;
	while(!IsEmpty())
	{
		if(!IsEmpty())
		{
			Pop(x);
			cout<<"学号"<<x.ptr ->data .number<<"\t姓名"<<x.ptr ->data .name <<endl;
		}
	}
}



//二叉树非递归遍历算法
template<class ElementType>
void BinaryTree<ElementType>::
PreOrderNoRecursive(BinaryTreeNode *BTroot)
{//二叉树的前序遍历非递归算法
	BinaryTreeNode	*p = BTroot;
	StackType		temp;
	int MaxStackSize=10;
	Stack<StackType>	S(MaxStackSize);//创建一个空栈
	while  ( p || !S.IsEmpty())
	{
		if (p)
		{
//			Visit(BTroot); 		//访问二叉树的结点
			DisplayNode(p);
			temp.ptr=p;
			S.Push (temp);					//根结点指针进栈，以后回朔时再退栈
			p = p->LChild;					//指针指向访问过的"根"结点左子树
		}
		else								//左子树为空时，利用堆栈回朔
		  if (!S.IsEmpty())
			 {
				S.Pop(temp); 	//从堆栈中弹出回朔结点指针（该结点已访问过）
				p=temp.ptr;
				p=p->RChild;				//指针指向回朔结点的右子树
			 } 
	}
}

template<class ElementType>
void BinaryTree<ElementType>::
InOrderNoRecursive(BinaryTreeNode *BTroot) 
{//二叉树的中序遍历非递归算法
	BinaryTreeNode	*p = BTroot;
	StackType		temp;
	int MaxStackSize=10;
	Stack<StackType>	S(MaxStackSize);
	while ((p)|| !S.IsEmpty())
	{
		while (p)				//找最左子树
		{	
			temp.ptr=p;
			S.Push (temp);	//"根"结点（未访问）指针进栈，以后回朔时再退栈
			p = p->LChild;		//指针指向该"根"结点左子树
		}
		if (!S.IsEmpty()) 		//左子树为空时，利用堆栈回朔
		{
			S.Pop(temp); 		//从堆栈中弹出回朔结点指针（该结点未访问过）
			p=temp.ptr;
//			Visit(BTroot); 		//访问二叉树的结点
			DisplayNode(p);
			p=p->RChild;		//指针指向回朔结点的右子树
		} 
	}
}

template<class ElementType>
void BinaryTree<ElementType>::
PostOrderNoRecursive(BinaryTreeNode *BTroot) 
{//二叉树的后序遍历非递归算法
	BinaryTreeNode	*p = BTroot;
	StackType			temp;
	int MaxStackSize=10;
	Stack<StackType>	S(MaxStackSize);
	while ((p)|| !S.IsEmpty())
	if (p)						//找最左子树
	{
		temp.status = false;	//准备进栈的结点进栈标志设为第一次进栈
		temp.ptr = p;
		S.Push (temp);	//"根"结点（未访问）指针及标志进栈，回朔时再退栈
		p = p->LChild;			//指针指向该"根"结点左子树
	}
	else
	if (!S.IsEmpty()) 			//左子树为空时，利用堆栈回朔
	{
		S.Pop(temp); 	//从堆栈中弹出回朔结点指针及标志（该结点未访问过）
		p = temp.ptr;	//p指向退栈结点，否则p的值是空 
		if (temp.status)
		{
//			Visit(BTroot); 		//访问二叉树的结点
			DisplayNode(p);
			p = NULL;			//将p设为空的目的是为强制退栈作准备
		}
		else
		{
			temp.status = true;	//改变进栈标志，准备重新进栈
			S.Push(temp);
			p= p->RChild;		//指针指向"根"的右子树
		}
	} 
}


//二叉树层次遍历
class QueueType	
{//队列数据元素类定义
   public:
	BinaryTreeNode	*ptr;	
};

template<class QueueType>
class Queue
{
public:
	Queue(int MaxQueueSize);
	~Queue() {delete [] element;}
	bool IsEmpty() {return front == rear;}
	bool IsFull() {return (front == (rear + 1) % (MaxSpaceSize + 1) ?1 : 0 ) ;}  //后面去掉可不可以

	bool GetFront(QueueType &result);
	bool GetRear(QueueType &result);
	bool EnQueue(QueueType &newvalue);
	bool DeQueue(QueueType &result);

private:
	QueueType * element;
	int   front;
	int   rear;
	int   MaxSpaceSize;
};

template<class QueueType>
Queue<QueueType>::
Queue(int MaxQueueSize)
{//队列构造算法
	MaxSpaceSize = MaxQueueSize;
	element = new QueueType[MaxSpaceSize + 1];
	front = 0;
	rear = 0;
}


template<class QueueType>
bool Queue<QueueType>::
GetFront(QueueType & result)
{
	if(IsEmpty()) return false;
	result = element[ (front + 1) % (MaxSpaceSize + 1) ];
	return true;
}

template<class QueueType>
bool Queue<QueueType>::
GetRear(QueueType & result)
{
	if(IsEmpty()) return false;
	result = element[rear];
	return true;
}

template<class QueueType>
bool Queue<QueueType>::
EnQueue(QueueType & newvalue)
{//循环队列进队
	if(IsFull()) return false;
	rear = (rear + 1) % (MaxSpaceSize + 1);
	element[rear] = newvalue;
	return true;
}

template<class QueueType>
bool Queue<QueueType>::
DeQueue(QueueType & result)
{//循环队列出队
	if(IsEmpty()) return false;
	front = (front + 1) % (MaxSpaceSize + 1);
	result = element[front];
	return true;
}

template<class ElementType>
void  BinaryTree<ElementType>::
LevelOrder_LtoR_UtoD(BinaryTreeNode *BTroot)
{// 层次遍历：从左至右，从上至下按层次遍历一棵二叉树
	BinaryTreeNode	*p;
	int count=0;
	NodesCount(BTroot,count);
	QueueType	temp;				//QueueType的成员类型是二叉树结点指针
	int MaxStackSize=count;
	Queue<QueueType>	Q(MaxStackSize);	//产生一个空队列
	p = BTroot;
	temp.ptr = p;
	Q.EnQueue(temp);				
	while (p)
	{
		if (!Q.DeQueue(temp))	return; 	//队空，结束
		p=temp.ptr;
//		Visit(p); 							//访问二叉树的结点
		DisplayNode(p);
		if (p->LChild) 	
		{
			temp.ptr = p->LChild;
			Q.EnQueue(temp);				//左孩子进队
		}
		if (p->RChild) 	
		{
			temp.ptr = p->RChild;
			Q.EnQueue(temp);				//左孩子进队
		}
	}
}

template<class ElementType>
void  BinaryTree<ElementType>::
LevelOrder_RtoL_DtoU(BinaryTreeNode *BTroot)
{// 层次遍历：从右至左，从下至上按层次遍历一棵二叉树（Right_Down）
	BinaryTreeNode	*p ;
	int count=0;
	NodesCount(BTroot,count);
	int MaxQueueSize=count;
	Queue<QueueType>	Q(MaxQueueSize);//产生一个空队列
	QueueType temp;						//QueueType的成员类型是二叉树结点指针

	int MaxStackSize=count;
	Stack<ElementType>	S(MaxStackSize);
//产生一个空堆栈，堆栈元素类型是二叉树结点值类型

	p = BTroot;
	temp.ptr = p;
	Q.EnQueue(temp);				
	while (p)
	{
		if (!Q.DeQueue(temp))	break; 	//队空，退出循环
		S.Push(temp.ptr->data);			//出队指针所指结点值进栈
		p=temp.ptr;
		if (p->LChild) 	
		{
			temp.ptr = p->LChild;
			Q.EnQueue(temp);			//左孩子进队
		}
		if (p->RChild) 	
		{
			temp.ptr = p->RChild;
			Q.EnQueue(temp);			//右孩子进队
		}
	}
	S.DisplayStack();
//堆栈中是进队次序倒序对应元素的值，显示输出堆栈中值，遍历结果
}

