

typedef struct TreeNode//���������
{	
	char 		data;
	TreeNode	*LChild;
	TreeNode	*RChild;	
}BinaryTreeNode;


/*******************************************************/

typedef struct	//��������ǵݹ��㷨
{
	BinaryTreeNode	*ptr;
	bool			B;//BΪfalseʱ����ʾ��һ�ν�ջ��BΪtrueʱ����ʾ�ڶ��ν�ջ
}SType;

/*******************************************************/

typedef struct	TreeNode1//�������������
{	
	char 		data;
	TreeNode1	*LChild; 
	bool		Lflag;
	TreeNode1	*RChild;
	bool		Rflag;
} BinaryTreeNode1;

/*******************************************************/

//���������

typedef struct	
{
	int 	key;	//����Ԫ�صĹؼ���
	char	name;//��Ϊ����Ԫ�ص�����������
}EType;

typedef struct TreeNode2//���������
{	
	EType 		data;
	TreeNode2	*LChild;
	TreeNode2	*RChild;
}BinaryTreeNode2;

/*******************************************************/

int  BinaryHeight(BinaryTreeNode  *BT) 
{// ���ض������ĸ߶�
   if (!BT) return 0;
   int HighL = BinaryHeight(BT->LChild);
   int HighR = BinaryHeight(BT->RChild); 
   if (HighL > HighR)  
		return ++HighL;
   else 
		return ++HighR;
}



//���������һ�������㷨��MakeNode��
BinaryTreeNode   *MakeNode(char &x)	
{
	//������

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
	// ����root��left, right��ָ�Ľ��ָ��Ϊ������
	root ->LChild=left;	
	root ->RChild=right;
	
}


void MakeBinaryTree1(BinaryTreeNode1 *root,
          BinaryTreeNode1 *left, BinaryTreeNode1 *right)
{
	// ����root��left, right��ָ�Ľ��ָ��Ϊ������
	root ->LChild=left;
	root ->RChild=right;	
}

BinaryTreeNode1   *MakeNode1(char &x)	
{
	//������

	BinaryTreeNode1	*ptr;

	ptr=new BinaryTreeNode1;
	if(!ptr)		
		return NULL;

	ptr->data=x ;
	ptr ->LChild=NULL;
	ptr ->RChild=NULL;
	return	  ptr;
}


//��ӡ�������и������������Ԫ�ص���Ϣ
void prinfThreadInOrder(BinaryTreeNode1 *BT)
{
	BinaryTreeNode1	*p=BT;	

	printf("��㣺%c, ",p->data);

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
{//����������������ݹ��㷨
	if (BT) 
	{
		InOrder(BT->LChild);
		printf("%d   ",BT->data.key);		//���ʶ������Ľ��
		InOrder(BT->RChild);
	}
}




