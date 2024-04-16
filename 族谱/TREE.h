
/*1--��  
2--����                     3--��Դ
4--�ִ���                   5--�ִ���
6--�־�                  7--����          8--����                                            
9--����                  10--����    11--����  12--�ֱ���  13--�ֻ�   
14--����               */




#include <iostream>
using namespace std;

typedef int ElementType;

typedef struct  TreeNode
{
	ElementType data;
	TreeNode *son;
	TreeNode *next;
}BinaryTreeNode;
//________________________________
typedef struct
{
	BinaryTreeNode *ptr;
	bool         flag;
}QueueType;

typedef struct
{
	QueueType *element;
	int front;
	int rear;
	int MaxSpaceSize;
}Queue;

typedef struct
{
	BinaryTreeNode *ptr;
}StackType;

typedef struct
{
	StackType *element;
	int top;
	int MaxSpaceSize;
}Stack;

void createStack(Stack &S,int MaxSize)
{//����ջ,����Ҫ֮����ɾ�����NEW ������������
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






//****************����********************
BinaryTreeNode *MakeNode(ElementType &newvalue)
{//������������
	BinaryTreeNode *ptr;
	ptr = new BinaryTreeNode;
	if(!ptr) return NULL;
	ptr->data = newvalue;
	ptr->son = NULL;
	ptr->next = NULL;
	return ptr;
}

void MakeBinaryTree(BinaryTreeNode *root,BinaryTreeNode *left,BinaryTreeNode *right)
{//���������
	root->son = left;
	root->next = right;
}

void NodesCount(BinaryTreeNode *BTroot,int &count)
{//������
	if(BTroot)
	{
		count++;
		NodesCount(BTroot->son,count);
		NodesCount(BTroot->next,count);
	}
}


void Displaynode(BinaryTreeNode *BTroot)
{/*1--��  
2--����                     3--��Դ
4--�ִ���                   5--�ִ���
6--�־�                  7--����          8--����                                            
9--����                  10--����    11--����  12--�ֱ���  13--�ֻ�   
14--����               */
	if(BTroot->data == 2)
		cout<<"����"<<endl;
	else if(BTroot->data == 3)
		cout<<"��Դ"<<endl;
	else if(BTroot->data == 4)
		cout<<"�ִ���"<<endl;
	else if(BTroot->data == 5)
		cout<<"�ִ���"<<endl;
	else if(BTroot->data == 6)
		cout<<"�־�"<<endl;
	else if(BTroot->data == 7)
		cout<<"����"<<endl;
	else if(BTroot->data == 8)
		cout<<"����"<<endl;
	else if(BTroot->data == 9)
		cout<<"����"<<endl;
	else if(BTroot->data == 10)
		cout<<"����"<<endl;
	else if(BTroot->data == 11)
		cout<<"����"<<endl;
	else if(BTroot->data == 12)
		cout<<"�ֱ���"<<endl;
	else if(BTroot->data == 13)
		cout<<"�ֻ�"<<endl;
	else if(BTroot->data == 14)
		cout<<"����"<<endl;

}



int Degree(BinaryTreeNode *BTroot)
{//��BTָ����ָ���Ķȣ������󼸸�����
	int degree = 0;
	if(!BTroot->son ) 
	{
		cout<<"û�к��ӣ�"<<endl;
		return 0;
	}
	degree++;
	BTroot = BTroot->son;
	cout<<"������"<<endl;
	Displaynode(BTroot);
	while(BTroot->next)
	{
		BTroot = BTroot->next;
		Displaynode(BTroot);
		degree++;
	}
	return degree;
}

void Level_LtoR_Uto_D(BinaryTreeNode *BTroot)
{//��α���
	BinaryTreeNode *p;
	int count = 0;
	NodesCount(BTroot,count);
	QueueType temp;
	Queue Q;
	CreateQueue(Q,count);
	p = BTroot;
	temp.ptr = p;
	EnQueue(Q,temp);
	while( !IsEmpty(Q))
	{
		DeQueue(Q,temp);
		p = temp.ptr;
		while(p)
		{
			Displaynode(p);
			temp.ptr = p->son;
			if(p->son)   EnQueue(Q,temp);
			p = p->next;
		}
	}
}