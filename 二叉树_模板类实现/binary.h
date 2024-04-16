


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
	

	//�����㷨���ݹ�
	void PreOrderRecursive(BinaryTreeNode *BTroot);
	void InOrderRecursive(BinaryTreeNode *BTroot);
	void PostOrderRecursive(BinaryTreeNode *BTroot);

	//�����㷨���ǵݹ�
	void PreOrderNoRecursive(BinaryTreeNode *BTroot);
	void InOrderNoRecursive(BinaryTreeNode *BTroot) ;
	void PostOrderNoRecursive(BinaryTreeNode *BTroot) ;

	//��α���
	void LevelOrder_LtoR_UtoD(BinaryTreeNode *BTroot);    //�����ң����ϵ���
	void LevelOrder_RtoL_DtoU(BinaryTreeNode *BTroot);   //���ҵ��󣬴��µ���

	BinaryTreeNode *MakeNode(ElementType& newvalue);  //������
	BinaryTreeNode *DeleteBinaryTree(BinaryTreeNode *BTroot);  
	void MakeBinaryTree(BinaryTreeNode *root,
						BinaryTreeNode *left, 
						BinaryTreeNode *right);//����һ�ö������� 
	void NodesCount(BinaryTreeNode *BTroot,int&count);  //�������Ľ�����
	int  Height(BinaryTreeNode  *BTroot); //����������߶�
	int  LeafsCount(BinaryTreeNode  *BTroot); 

    void DisplayNode(BinaryTreeNode  *BTroot);

   private:
		BinaryTreeNode 	*BTroot;//ָ������������<ElementType>


};

template<class ElementType>
BinaryTreeNode* BinaryTree<ElementType>::
MakeNode(ElementType& newvalue)
{// ������
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
{// ����root��left, right��ָ�Ľ��ָ��Ϊ������
	root ->LChild=left;
	root ->RChild=right;
}

template<class ElementType>
int  BinaryTree<ElementType>::
Height(BinaryTreeNode  *BTroot) 
{// ���ض������ĸ߶�
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
{//�������Ľ�����
	if (BTroot) 
	{
		count++;		//�������Ľ�����
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
	cout<<"ѧ��"<<BTroot->data.number<<"\t����"<<BTroot->data.name<<endl;
}



//�����㷨�����ݹ�
template<class ElementType>
void BinaryTree<ElementType>::
PreOrderRecursive(BinaryTreeNode *BTroot)
{//��������ǰ������ݹ��㷨
	if (BTroot) 
	{
//		Visit(BTroot); 		//���ʶ������Ľ��
		DisplayNode(BTroot);
		PreOrderRecursive(BTroot->LChild);
		PreOrderRecursive(BTroot->RChild);
	}
}

template<class ElementType>
void BinaryTree<ElementType>::
InOrderRecursive(BinaryTreeNode *BTroot)
{//����������������ݹ��㷨
	if (BTroot) 
	{
		InOrderRecursive(BTroot->LChild);
//		Visit(BTroot); 		//���ʶ������Ľ��
		DisplayNode(BTroot);
		InOrderRecursive(BTroot->RChild);
	}
}

template<class ElementType>
void BinaryTree<ElementType>::
PostOrderRecursive(BinaryTreeNode *BTroot)
{//�������ĺ�������ݹ��㷨
	if (BTroot) 
	{
		PostOrderRecursive(BTroot->LChild);
		PostOrderRecursive(BTroot->RChild);
//		Visit(BTroot); 		//���ʶ������Ľ��
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
			cout<<"ѧ��"<<x.ptr ->data .number<<"\t����"<<x.ptr ->data .name <<endl;
		}
	}
}



//�������ǵݹ�����㷨
template<class ElementType>
void BinaryTree<ElementType>::
PreOrderNoRecursive(BinaryTreeNode *BTroot)
{//��������ǰ������ǵݹ��㷨
	BinaryTreeNode	*p = BTroot;
	StackType		temp;
	int MaxStackSize=10;
	Stack<StackType>	S(MaxStackSize);//����һ����ջ
	while  ( p || !S.IsEmpty())
	{
		if (p)
		{
//			Visit(BTroot); 		//���ʶ������Ľ��
			DisplayNode(p);
			temp.ptr=p;
			S.Push (temp);					//�����ָ���ջ���Ժ��˷ʱ����ջ
			p = p->LChild;					//ָ��ָ����ʹ���"��"���������
		}
		else								//������Ϊ��ʱ�����ö�ջ��˷
		  if (!S.IsEmpty())
			 {
				S.Pop(temp); 	//�Ӷ�ջ�е�����˷���ָ�루�ý���ѷ��ʹ���
				p=temp.ptr;
				p=p->RChild;				//ָ��ָ���˷����������
			 } 
	}
}

template<class ElementType>
void BinaryTree<ElementType>::
InOrderNoRecursive(BinaryTreeNode *BTroot) 
{//����������������ǵݹ��㷨
	BinaryTreeNode	*p = BTroot;
	StackType		temp;
	int MaxStackSize=10;
	Stack<StackType>	S(MaxStackSize);
	while ((p)|| !S.IsEmpty())
	{
		while (p)				//����������
		{	
			temp.ptr=p;
			S.Push (temp);	//"��"��㣨δ���ʣ�ָ���ջ���Ժ��˷ʱ����ջ
			p = p->LChild;		//ָ��ָ���"��"���������
		}
		if (!S.IsEmpty()) 		//������Ϊ��ʱ�����ö�ջ��˷
		{
			S.Pop(temp); 		//�Ӷ�ջ�е�����˷���ָ�루�ý��δ���ʹ���
			p=temp.ptr;
//			Visit(BTroot); 		//���ʶ������Ľ��
			DisplayNode(p);
			p=p->RChild;		//ָ��ָ���˷����������
		} 
	}
}

template<class ElementType>
void BinaryTree<ElementType>::
PostOrderNoRecursive(BinaryTreeNode *BTroot) 
{//�������ĺ�������ǵݹ��㷨
	BinaryTreeNode	*p = BTroot;
	StackType			temp;
	int MaxStackSize=10;
	Stack<StackType>	S(MaxStackSize);
	while ((p)|| !S.IsEmpty())
	if (p)						//����������
	{
		temp.status = false;	//׼����ջ�Ľ���ջ��־��Ϊ��һ�ν�ջ
		temp.ptr = p;
		S.Push (temp);	//"��"��㣨δ���ʣ�ָ�뼰��־��ջ����˷ʱ����ջ
		p = p->LChild;			//ָ��ָ���"��"���������
	}
	else
	if (!S.IsEmpty()) 			//������Ϊ��ʱ�����ö�ջ��˷
	{
		S.Pop(temp); 	//�Ӷ�ջ�е�����˷���ָ�뼰��־���ý��δ���ʹ���
		p = temp.ptr;	//pָ����ջ��㣬����p��ֵ�ǿ� 
		if (temp.status)
		{
//			Visit(BTroot); 		//���ʶ������Ľ��
			DisplayNode(p);
			p = NULL;			//��p��Ϊ�յ�Ŀ����Ϊǿ����ջ��׼��
		}
		else
		{
			temp.status = true;	//�ı��ջ��־��׼�����½�ջ
			S.Push(temp);
			p= p->RChild;		//ָ��ָ��"��"��������
		}
	} 
}


//��������α���
class QueueType	
{//��������Ԫ���ඨ��
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
	bool IsFull() {return (front == (rear + 1) % (MaxSpaceSize + 1) ?1 : 0 ) ;}  //����ȥ���ɲ�����

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
{//���й����㷨
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
{//ѭ�����н���
	if(IsFull()) return false;
	rear = (rear + 1) % (MaxSpaceSize + 1);
	element[rear] = newvalue;
	return true;
}

template<class QueueType>
bool Queue<QueueType>::
DeQueue(QueueType & result)
{//ѭ�����г���
	if(IsEmpty()) return false;
	front = (front + 1) % (MaxSpaceSize + 1);
	result = element[front];
	return true;
}

template<class ElementType>
void  BinaryTree<ElementType>::
LevelOrder_LtoR_UtoD(BinaryTreeNode *BTroot)
{// ��α������������ң��������°���α���һ�ö�����
	BinaryTreeNode	*p;
	int count=0;
	NodesCount(BTroot,count);
	QueueType	temp;				//QueueType�ĳ�Ա�����Ƕ��������ָ��
	int MaxStackSize=count;
	Queue<QueueType>	Q(MaxStackSize);	//����һ���ն���
	p = BTroot;
	temp.ptr = p;
	Q.EnQueue(temp);				
	while (p)
	{
		if (!Q.DeQueue(temp))	return; 	//�ӿգ�����
		p=temp.ptr;
//		Visit(p); 							//���ʶ������Ľ��
		DisplayNode(p);
		if (p->LChild) 	
		{
			temp.ptr = p->LChild;
			Q.EnQueue(temp);				//���ӽ���
		}
		if (p->RChild) 	
		{
			temp.ptr = p->RChild;
			Q.EnQueue(temp);				//���ӽ���
		}
	}
}

template<class ElementType>
void  BinaryTree<ElementType>::
LevelOrder_RtoL_DtoU(BinaryTreeNode *BTroot)
{// ��α������������󣬴������ϰ���α���һ�ö�������Right_Down��
	BinaryTreeNode	*p ;
	int count=0;
	NodesCount(BTroot,count);
	int MaxQueueSize=count;
	Queue<QueueType>	Q(MaxQueueSize);//����һ���ն���
	QueueType temp;						//QueueType�ĳ�Ա�����Ƕ��������ָ��

	int MaxStackSize=count;
	Stack<ElementType>	S(MaxStackSize);
//����һ���ն�ջ����ջԪ�������Ƕ��������ֵ����

	p = BTroot;
	temp.ptr = p;
	Q.EnQueue(temp);				
	while (p)
	{
		if (!Q.DeQueue(temp))	break; 	//�ӿգ��˳�ѭ��
		S.Push(temp.ptr->data);			//����ָ����ָ���ֵ��ջ
		p=temp.ptr;
		if (p->LChild) 	
		{
			temp.ptr = p->LChild;
			Q.EnQueue(temp);			//���ӽ���
		}
		if (p->RChild) 	
		{
			temp.ptr = p->RChild;
			Q.EnQueue(temp);			//�Һ��ӽ���
		}
	}
	S.DisplayStack();
//��ջ���ǽ��Ӵ������ӦԪ�ص�ֵ����ʾ�����ջ��ֵ���������
}

