#include "applist.h"
#include <iostream>
using namespace std;


template<class StackType>
class Stack
{//˳��洢�ṹ��ջģ��Stack�Ķ���
public:
	Stack(int MaxStackSize = 20);					//���캯��
	~Stack() {delete [] element;}					//��������(�ͷſռ�)
	int GetTopAddress()  {return top;}				//��ȡ��ջջ��ָ��
	bool IsEmpty();									//�ж϶�ջ��
	bool IsFull();									//�ж϶�ջ��
	bool GetTop(StackType &result);					//��ȡջ��Ԫ��ֵ����ŵ�result
	bool Push(StackType  &newvalue);				//��ջ��newvalueֵ��ջ
	bool Pop(StackType  &result);					//��ջ����ջֵ��ŵ�result
	
private:
	int top;        //��ջջ��ָ��
	int MaxSpaceSize ;  //��ջ�ռ��С
	StackType  *element;   //��ջ����Ԫ�ش�ſռ�
};


template<class StackType>
Stack<StackType>::
Stack(int MaxStackSize)
{//���캯������ջ����Ԫ�ش����element[0..MaxSpaceSize]
	MaxSpaceSize = MaxStackSize;
	element = new StackType[MaxSpaceSize];
	top = -1;
}

template<class StackType>
bool Stack<StackType>::
IsEmpty()
{//�ж϶�ջ�Ƿ�Ϊ��
	if(top == -1) return true;   //���Ϊ���򷵻���ֵ
	return false;
}

template<class StackType>
bool Stack<StackType>::
IsFull()
{//�ж϶�ջ�Ƿ�Ϊ��
	if(top>= MaxSpaceSize-1)  return true;
	return false;
}

template<class StackType>
bool Stack<StackType>::
GetTop(StackType &result)
{//��ȡջ��Ԫ��ֵ
	if(IsEmpty())  return false;
	result = element[top];
	return true;
}

template<class StackType>
bool Stack<StackType>::
Pop(StackType &result)
{//��ջ
	if(IsEmpty())  return false;
	result = element[top--];
	return true;
}


template<class StackType>
bool Stack<StackType>::
Push(StackType  &newvalue)
{//��ջ
	if(IsFull())  return false;
	element[++top] = newvalue;
	return true;
}













