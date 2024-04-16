

typedef struct TreeNode//二叉树结点
{	
	char 		data;
	TreeNode	*LChild;
	TreeNode	*RChild;	
}BinaryTreeNode;


/*******************************************************/

typedef struct	//后序遍历非递归算法
{
	BinaryTreeNode	*ptr;
	bool			B;//B为false时，表示第一次进栈；B为true时，表示第二次进栈
}SType;

/*******************************************************/

typedef struct	TreeNode1//线索二叉树结点
{	
	char 		data;
	TreeNode1	*LChild; 
	bool		Lflag;
	TreeNode1	*RChild;
	bool		Rflag;
} BinaryTreeNode1;

/*******************************************************/

//二叉树结点

typedef struct	
{
	int 	key;	//数据元素的关键字
	char	name;//设为数据元素的名字数据项
}EType;

typedef struct TreeNode2//二叉树结点
{	
	EType 		data;
	TreeNode2	*LChild;
	TreeNode2	*RChild;
}BinaryTreeNode2;

/*******************************************************/

int  BinaryHeight(BinaryTreeNode  *BT) 
{// 返回二叉树的高度
   if (!BT) return 0;
   int HighL = BinaryHeight(BT->LChild);
   int HighR = BinaryHeight(BT->RChild); 
   if (HighL > HighR)  
		return ++HighL;
   else 
		return ++HighR;
}



//构造二叉树一个结点的算法（MakeNode）
BinaryTreeNode   *MakeNode(char &x)	
{
	//构造结点

	BinaryTreeNode	*ptr;

	ptr=new BinaryTreeNode;
	if(!ptr)		
		return NULL;

	ptr ->data = x ;
	ptr ->LChild=NULL;
	ptr ->RChild=NULL;
	return	  ptr;
}



void MakeBinaryTree(BinaryTreeNode *root,
          BinaryTreeNode *left, BinaryTreeNode *right)
{
	// 联接root，left, right所指的结点指针为二叉树
	root ->LChild=left;	
	root ->RChild=right;
	
}


void MakeBinaryTree1(BinaryTreeNode1 *root,
          BinaryTreeNode1 *left, BinaryTreeNode1 *right)
{
	// 联接root，left, right所指的结点指针为二叉树
	root ->LChild=left;
	root ->RChild=right;	
}

BinaryTreeNode1   *MakeNode1(char &x)	
{
	//构造结点

	BinaryTreeNode1	*ptr;

	ptr=new BinaryTreeNode1;
	if(!ptr)		
		return NULL;

	ptr->data=x ;
	ptr ->LChild=NULL;
	ptr ->RChild=NULL;
	return	  ptr;
}


//打印线索树中各个结点中数据元素的信息
void prinfThreadInOrder(BinaryTreeNode1 *BT)
{
	BinaryTreeNode1	*p=BT;	

	printf("结点：%c, ",p->data);

	printf("Lflag:%d, ",p->Lflag);
	if(p->LChild!=NULL)
		printf("LChild: %c,    ",p->LChild->data);
	else
		printf("LChild: NULL, ");

	printf("Rflag:%d, ",p->Rflag);
	if(p->RChild!=NULL)
		printf("RChild: %c,    \n",p->RChild->data);
	else
		printf("LChild: NULL, \n");

}

void InOrder(BinaryTreeNode2 *BT)
{//二叉树的中序遍历递归算法
	if (BT) 
	{
		InOrder(BT->LChild);
		printf("%d   ",BT->data.key);		//访问二叉树的结点
		InOrder(BT->RChild);
	}
}




