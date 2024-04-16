
#include "travehead.h"

#define MaxStackSize 7


typedef struct
{	
	SType			*element;
	int				top;
	int				MaxSize;
} Stack;

void CreatStack (Stack &S) 
{// ����һ���������ΪMaxStackSize �Ķ�ջS
   	S.MaxSize = MaxStackSize;
   	S.element = new SType[S.MaxSize];
  	 S.top = -1;
}

bool IsEmpty(Stack &S)
{// �ж϶�ջS�Ƿ�Ϊ��
	if (S.top == -1)   
		return true;
	return  false;
}
bool IsFull(Stack &S)
{// �ж϶�ջS�Ƿ�Ϊ��
	if (S.top >= S.MaxSize-1)  
		return true;
	return  false;
}


bool Push(Stack &S , SType &x)
{// x��sջ�����ؽ�ջ���״ֵ̬
	if (IsFull(S))   
		return false;
	S.top++;
	S.element[S.top] =x;
   	return true;
}


bool Pop(Stack &S , SType &x)
{// ��sջ����ֵȡ��x�У����س�ջ���״ֵ̬
	if (IsEmpty(S))   
		return false;
	x = S.element[S.top];
	S.top--;
   return true;
}