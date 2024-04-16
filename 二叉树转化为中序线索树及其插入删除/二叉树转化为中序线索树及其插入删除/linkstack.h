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
{// ����һ����ջ
	ChainStack* S=new ChainStack;
	S->top=NULL;
	return S;
}


bool IsEmpty(ChainStack *S)
{// �ж϶�ջS�Ƿ�Ϊ��
	if (!S->top)    
		return true;
	return  false;
}



bool Push(ChainStack *S , BinaryTreeNode1 *x)
{// x��sջ�����ؽ�ջ���״ֵ̬
	StackNode *q = new StackNode;
	q->element=x;
	q->link=S->top;
	S->top =q;
	return true;
}




BinaryTreeNode1 *Pop(ChainStack *S)
{// ��sջ����ֵȡ��x�У����س�ջ���״ֵ̬
	if (IsEmpty(S))   
		return false;
	StackNode  *p=S->top;
	BinaryTreeNode1 *x = p->element;
	S->top = p ->link;
	delete p;
	return x;
}



