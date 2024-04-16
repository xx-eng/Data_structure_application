
#include <iostream>
using namespace std;
#define StackType QueueType

typedef struct
{
	int number;
	char name[20];
}ElementType;

typedef struct  TreeNode
{
	ElementType data;
	TreeNode *LChild;
	TreeNode *RChild;
}BinaryTreeNode;


typedef struct
{
	BinaryTreeNode  *ptr;
	bool            flag;
}StackType;

typedef struct 
{
	int top;
	int MaxSpaceSize;
	StackType *element;
}Stack;


typedef struct
{
	QueueType *element;
	int front;
	int rear;
	int MaxSpaceSize;
}Queue;



void createStack(Stack &S,int MaxSize)
{//构造栈,不需要之后再删除这个NEW 出来的区域吗
	S.top = -1;
	S.MaxSpaceSize = MaxSize;
	S.element = new StackType[S.MaxSpaceSize];
}

bool IsEmpty(Stack &S)
{//empty
	if(S.top == -1)
		return true;
	return false;
}

bool IsFull(Stack &S)
{//full
	if (S.top >= S.MaxSpaceSize-1)  
		return true;
	return  false;
}

bool Push(Stack &S,StackType &x)
{//put in
	if(IsFull(S))  
		return false;
	S.top++;
	S.element[S.top] = x;
   	return true;
}

bool Pop(Stack &S,StackType &x)
{
	if(IsEmpty(S))
		return false;
	x = S.element[S.top];
	S.top--;
	return true;
}

void DisplayStack(Stack S)
{
	StackType x;
	while(!IsEmpty(S))
	{
		if(!IsEmpty(S))
		{
			Pop(S,x);
			cout<<"学号"<<x.ptr ->data .number <<"\t姓名"<<x.ptr ->data .name <<endl;
		}
	}
}







void CreateQueue(Queue &Q,int MaxSize)
{
	Q.MaxSpaceSize  = MaxSize;
	Q.element = new QueueType[MaxSize + 1];
	Q.front = 0;
	Q.rear = 0;
}

bool IsEmpty(Queue &Q)
{
	if(Q.front == Q.rear)
		return true;
	return false;
}

bool IsFull(Queue &Q)
{
	if(Q.front == (Q.rear + 1)%(Q.MaxSpaceSize + 1))
		return true;
	return false;
}

bool EnQueue(Queue &Q,QueueType newvalue)
{
	if(IsFull(Q)) return false;
	Q.rear = (Q.rear + 1)%(Q.MaxSpaceSize+1);
	Q.element[Q.rear] = newvalue;
	return true;
}

bool DeQueue(Queue &Q,QueueType &result)
{
	if(IsEmpty(Q))  return false;
	Q.front = (Q.front + 1) % (Q.MaxSpaceSize + 1);
	result = Q.element[Q.front];  
	return true;
}


bool GetFront(Queue &Q,QueueType &result)
{
	if(IsEmpty(Q))
		return false;
	result = Q.element[(Q.front+1) % (Q.MaxSpaceSize + 1)];
	return true;
}

bool GetRear(Queue &Q,QueueType &result)
{
	if(IsEmpty(Q)) 
		return false;
	result = Q.element[ (Q.rear) % (Q.MaxSpaceSize + 1)];
	return true;
}








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
{
	if(BTroot)
	{
		count++;
		NodesCount(BTroot->LChild,count);
		NodesCount(BTroot->RChild,count);
	}
}




void Display(BinaryTreeNode *treenode[5])
{//显示
	cout<<"        "<<treenode[0]->data.name<<endl;
	cout<<"         "<<"╱"<<endl;    //╲
	cout<<"      "<<treenode[1]->data.name<<endl;
	cout<<"       "<<"╱"<<" ╲"<<endl;
	cout<<"    "<<treenode[2]->data.name<<" "<<treenode[3]->data.name<<endl;
	cout<<"      "<<"╲"<<endl;
	cout<<"      "<<treenode[4]->data.name<<endl;
	
}

int Height(BinaryTreeNode *BTroot)
{
	if(!BTroot) return 0;
	int HighL = Height(BTroot->LChild);
	int HighR = Height(BTroot->RChild);
	if(HighL>HighR)
		return ++HighL;
	else
		return ++HighR;
}

//delete , 结点个数



//遍历算法，
//进栈往左走，出栈往右走
void PreRecursive(BinaryTreeNode *BTroot)
{//前序遍历非递归算法
	BinaryTreeNode *p = BTroot;
	StackType temp;
	int MaxStackSize = Height(BTroot);
	Stack S;
	createStack(S,MaxStackSize);
	while(p || !IsEmpty(S))
	{
		if(p)
		{
			cout<<"学号"<<p->data.number<<"\t姓名"<<p->data.name<<endl ;
			temp.ptr = p;
			Push(S,temp);
			p = p->LChild;
		}
		else
			if(!IsEmpty(S))
			{
				Pop(S,temp);
				p = temp.ptr;
				p = p->RChild;
			}
	}
}

void InRecursive(BinaryTreeNode *BTroot)
{//中序遍历非递归算法
	BinaryTreeNode *p = BTroot;
	StackType temp;
	int MaxStackSize = Height(BTroot);
	Stack S;
	createStack(S,MaxStackSize);
	while(p || !IsEmpty(S))
	{
		if(p)
		{
			
			temp.ptr = p;
			Push(S,temp);
			p = p->LChild;
		}
		else
			if(!IsEmpty(S))
			{
				Pop(S,temp);
				p = temp.ptr;
				cout<<"学号"<<p->data.number<<"\t姓名"<<p->data.name <<endl;
				p = p->RChild;
			}
	}
}

void PostRecursive(BinaryTreeNode *BTroot)
{//后序遍历非递归算法
	BinaryTreeNode *p = BTroot;
	StackType temp;
	int MaxStackSize = Height(BTroot);
	Stack S;
	createStack(S,MaxStackSize);
	while(p || !IsEmpty(S))
	{
		if(p)
		{
			temp.flag = false;	
			temp.ptr = p;
			Push(S,temp);
			p = p->LChild;
		}
		else
			if(!IsEmpty(S))
			{
				Pop(S,temp);
				p = temp.ptr;
				if(temp.flag)
				{
					cout<<"学号"<<p->data.number<<"\t姓名"<<p->data.name<<endl ;
					p = NULL;
				}
				else
				{
					temp.flag = true;
					Push(S,temp);
					p = p->RChild;
				}
			}
	}
}

void Level_L_R_U_D(BinaryTreeNode *BTroot)
{//层次遍历算法上至下，左至右
	Queue	Q;
	BinaryTreeNode 	 *p;
	int count = 0;
	NodesCount(BTroot,count);
	CreateQueue(Q,count);//产生一个空队列，这一过程函数可以不在这里进行
	p=BTroot;
	QueueType temp;
	temp.ptr = p;
	EnQueue(Q,temp);
	while (p)
	{
		if(!DeQueue(Q,temp)) return; //队空，结束
		p = temp.ptr;
		cout<<"学号"<<p->data.number<<"\t姓名"<<p->data.name<<endl ;
		if(p->LChild)
		{
			temp.ptr = p->LChild ;
			EnQueue(Q,temp);
		}
		if(p->RChild)
		{
			temp.ptr = p->RChild ;
			EnQueue(Q,temp);
		}
	}
}


/*void Level_R_L_U_D(BinaryTreeNode *BTroot)
{//层次遍历算法上至下，从右至左
	BinaryTreeNode *p;
	int count = 0;
	NodesCount(BTroot,count);
	QueueType temp;
	int MaxStackSize = count;
	Queue Q;
	CreateQueue(Q,count);
	p = BTroot;
	temp.ptr = p;
	EnQueue(Q,temp);
	while(p)
	{
		if(!DeQueue(Q,temp)) return;
		p = temp.ptr;
		cout<<"学号"<<p->data.number<<"\t姓名"<<p->data.name<<endl ;
		if(p->LChild)
		{
			temp.ptr = p->RChild ;
			EnQueue(Q,temp);
		}
		if(p->RChild)
		{
			temp.ptr = p->LChild ;
			EnQueue(Q,temp);
		}
	}
}*/

void Level_R_L_D_U(BinaryTreeNode *BTroot)
{
	BinaryTreeNode *p;
	int count;
	NodesCount(BTroot,count);
	Queue Q;
	CreateQueue(Q,count);
	QueueType temp;
	Stack S;
	createStack(S,count);
	p = BTroot;
	temp.ptr = p;
	EnQueue(Q,temp);
	while(p)
	{
		if(!DeQueue(Q,temp))  break;//队空，退出循环
		Push(S,temp);
		p = temp.ptr;
		if(p->LChild )
		{
			temp.ptr = p->LChild ;
			EnQueue(Q,temp);
		}
		if(p->RChild )
		{
			temp.ptr = p->RChild ;
			EnQueue(Q,temp);
		}
	}
	DisplayStack(S); 
}
