
#include "travehead.h"
#define MaxQueueSize 7


typedef struct
{	
	BinaryTreeNode 	*element;//一维数组 
	int		front;
	int		rear;
	int		MaxSize;
}Queue;



bool IsEmpty(Queue &Q)
{// 判断队列Q是否为空
	if (Q.front == Q.rear)  
		return true;
	return  false;
}

bool IsFull(Queue &Q)
{// 判断队列Q是否为满
	if (Q.front == (Q.rear+1) % (Q.MaxSize+1))  
	 	return true;
	return  false;
} 

void CreatQueue (Queue &Q)
{// 构造一个最大容量为MaxQueueSize 的队列Q
   	Q.MaxSize = MaxQueueSize;
  	Q.element = new BinaryTreeNode[Q.MaxSize+1]; 
  	 Q.front = 0;
   	Q.rear = 0;
}

bool Enqueue(Queue &Q , BinaryTreeNode *x)
{// x进Q队列，返回进队列后的状态值
	if (IsFull(Q))   
		return false;
	Q.rear = (Q.rear+1) % (Q.MaxSize+1);
	Q.element[Q.rear].data=x->data;
	Q.element[Q.rear].LChild=x->LChild;
	Q.element[Q.rear].RChild=x->RChild;
   	return true;
}



bool DeQueue(Queue &Q , BinaryTreeNode *x)
{
	if (IsEmpty(Q))   
		return false;
	Q.front=(Q.front+1)% (Q.MaxSize+1);

	x->data=Q.element[Q.front].data;
	x->LChild=Q.element[Q.front].LChild;
	x->RChild=Q.element[Q.front].RChild;
   	return true;
} 