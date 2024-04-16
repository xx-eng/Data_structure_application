#include "travehead.h"




typedef struct StackNode
{	
	BinaryTreeNode1 *element;
	StackNode	*link;
} StackNode;


typedef struct
{	
	int 		Hdata;
	StackNode		*top;
} ChainStack;



ChainStack *CreatStack()
{// 构造一个空栈
	ChainStack* S=new ChainStack;
	S->top=NULL;
	return S;
}


bool IsEmpty(ChainStack *S)
{// 判断堆栈S是否为空
	if (!S->top)    
		return true;
	return  false;
}



bool Push(ChainStack *S , BinaryTreeNode1 *x)
{// x进s栈，返回进栈后的状态值
	StackNode *q = new StackNode;
	q->element=x;
	q->link=S->top;
	S->top =q;
	return true;
}




BinaryTreeNode1 *Pop(ChainStack *S)
{// 将s栈顶的值取至x中，返回出栈后的状态值
	if (IsEmpty(S))   
		return false;
	StackNode  *p=S->top;
	BinaryTreeNode1 *x = p->element;
	S->top = p ->link;
	delete p;
	return x;
}



