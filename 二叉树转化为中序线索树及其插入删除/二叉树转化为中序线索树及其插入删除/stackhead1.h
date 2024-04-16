
#include "travehead.h"

#define MaxStackSize 7


typedef struct
{	
	BinaryTreeNode1		*element;
	int				top;
	int				MaxSize;
} Stack;

void CreatStack (Stack &S) 
{// 构造一个最大容量为MaxStackSize 的堆栈S
   	S.MaxSize = MaxStackSize;
   	S.element=new BinaryTreeNode1[S.MaxSize];
  	S.top = -1;
}

bool IsEmpty(Stack &S)
{// 判断堆栈S是否为空
	if (S.top == -1)   
		return true;
	return  false;
}
bool IsFull(Stack &S)
{// 判断堆栈S是否为满
	if (S.top >= S.MaxSize-1)  
		return true;
	return  false;
}


bool Push(Stack &S , BinaryTreeNode1 &x)
{// x进s栈，返回进栈后的状态值
	if (IsFull(S))   
		return false;
	S.top++;
	S.element[S.top]=x;	
   	return true;
}



bool Pop(Stack &S , BinaryTreeNode1 &x)
{// 将s栈顶的值取至x中，返回出栈后的状态值
	if (IsEmpty(S))   
		return false;
	x=S.element[S.top];
	S.top--;
   return true;
}

BinaryTreeNode1 *Pop1(Stack &S)
{// 将s栈顶的值取至x中，返回出栈后的状态值
	if (IsEmpty(S))   
		return false;
	BinaryTreeNode1 *x;
	x=&S.element[S.top];	
	S.top--;
   return x;
}

BinaryTreeNode1 *Pop2(Stack &S)
{// 将s栈顶的值取至x中，返回出栈后的状态值
	if (IsEmpty(S))   
		return false;
	BinaryTreeNode1 *x;
	x=new BinaryTreeNode1;
	x->data=S.element[S.top].data;
	x->LChild=S.element[S.top].LChild;
	x->Lflag=S.element[S.top].Lflag;
	x->RChild=S.element[S.top].RChild;
	x->Rflag=S.element[S.top].Rflag;
	S.top--;
   return x;
}

