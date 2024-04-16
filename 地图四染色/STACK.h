#include "applist.h"
#include <iostream>
using namespace std;


template<class StackType>
class Stack
{//顺序存储结构堆栈模板Stack的定义
public:
	Stack(int MaxStackSize = 20);					//构造函数
	~Stack() {delete [] element;}					//析构函数(释放空间)
	int GetTopAddress()  {return top;}				//获取堆栈栈顶指针
	bool IsEmpty();									//判断堆栈空
	bool IsFull();									//判断堆栈满
	bool GetTop(StackType &result);					//获取栈顶元素值，存放到result
	bool Push(StackType  &newvalue);				//进栈：newvalue值进栈
	bool Pop(StackType  &result);					//出栈：出栈值存放到result
	
private:
	int top;        //堆栈栈顶指针
	int MaxSpaceSize ;  //堆栈空间大小
	StackType  *element;   //堆栈数据元素存放空间
};


template<class StackType>
Stack<StackType>::
Stack(int MaxStackSize)
{//构造函数，堆栈数据元素存放于element[0..MaxSpaceSize]
	MaxSpaceSize = MaxStackSize;
	element = new StackType[MaxSpaceSize];
	top = -1;
}

template<class StackType>
bool Stack<StackType>::
IsEmpty()
{//判断堆栈是否为空
	if(top == -1) return true;   //如果为空则返回真值
	return false;
}

template<class StackType>
bool Stack<StackType>::
IsFull()
{//判断堆栈是否为满
	if(top>= MaxSpaceSize-1)  return true;
	return false;
}

template<class StackType>
bool Stack<StackType>::
GetTop(StackType &result)
{//获取栈顶元素值
	if(IsEmpty())  return false;
	result = element[top];
	return true;
}

template<class StackType>
bool Stack<StackType>::
Pop(StackType &result)
{//出栈
	if(IsEmpty())  return false;
	result = element[top--];
	return true;
}


template<class StackType>
bool Stack<StackType>::
Push(StackType  &newvalue)
{//进栈
	if(IsFull())  return false;
	element[++top] = newvalue;
	return true;
}













