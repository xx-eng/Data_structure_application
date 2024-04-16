
#define MaxSize 50;

typedef struct
{
	int row;      //行
	int col;      //列
}StackType;

typedef struct 
{
	int top;
	int MaxSpaceSize;
	StackType *element;
}Stack;

void createStack(Stack &S)
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

