/*
					A
				____|____
	    		|		 |
				B        C
			 ___|____    |____
	    	 |		 |        |
			 D		 E        F
				     |____
	    		          |
				          G

  */


#include <stdlib.h>
#include <stdio.h>


#include "linkstack.h"



void ThreadInOrder(BinaryTreeNode1 *BT)
{//二叉树转化为前序线索树算法
	ChainStack		*S;		//构造链式栈
	BinaryTreeNode1	*p=BT;
	BinaryTreeNode1	*q=NULL;		//q始终指在p结点前驱


	S=CreatStack();		//产生一个空栈，这一过程函数可以不在这里进行

	while (p||!IsEmpty(S))
	{
		while (p)
		{
		//	p->Lflag=0;
			Push(S,p);				//根结点指针（未访问）进栈，以后回朔时再退栈
			if (p->LChild)				//如果p仍有左子树继续向左推进
			{			
				p->Lflag=0;  
				p=p->LChild;  
			}
			else			
			{//如果p没有左子树，p的左链接域指向前驱；并准备退栈
				p->Lflag = 1;   
				p->LChild= q; 	
				q=p; 	
				p=NULL;			//p设为NULL为的是强制退栈
			}
		}
	
		if (!IsEmpty(S))
		 {		
			p=Pop(S); 	

			p->Rflag=0;
			printf("%c  ",p->data);						
		//	if (!q->RChild&&q->data!=p->data)	
			if (!q->RChild&&q!=p)
			{
				q->RChild=p;
				q->Rflag=1;	
				q=p; 
			}
			p=p->RChild;
		}
	}
	q->Rflag=1;	
	p=BT;

}


void InOrderThread (BinaryTreeNode1 *BT)
{//中序二叉线索树的遍历
	BinaryTreeNode1	*p=BT;
	bool 	flag=false;

	while(p)	
	{
		while(!p->Lflag) 		//查找一棵子树的最左子孙
			p=p->LChild;
		
		
		flag=true;
		while(flag&&p)
		{ 
			printf("%c  ",p->data); //访问结点
			p=p->RChild;				//查找p的右子树的根或后继结点

			if (p&&!p->Rflag)				//p结点存在右子树时，为强制退出作准备
			{
				printf("%c  ",p->data);
				flag =NULL;
				p=p->RChild;
			}
		}
	}
}

void InOrderThreadInsertLeft(BinaryTreeNode1 *S, BinaryTreeNode1 *T ) 
{//中序线索树中插入的新结点T作为S的左孩子算法
	BinaryTreeNode1	*q;
	T->LChild = S->LChild;
	T-> Lflag = S-> Lflag;
	T-> RChild = S;
	T-> Rflag = 1;
	S-> LChild = T;
	S-> Lflag = 0;
	if ( ! T-> Lflag )				//找S左子树中的最右子孙
	{
		q = T-> LChild;
		while (!q-> Rflag)
			q = q-> RChild;
		q-> RChild =T;
	}
}


//中序线索树中插入的新结点T作为S的右孩子算法（InOrderThreadInsertRight）
                                                                                 
void InOrderThreadInsertRight(BinaryTreeNode1 *S, BinaryTreeNode1 *T ) 
{//中序线索树中插入的新结点T作为S的左孩子算法
	BinaryTreeNode1	*q;
	T->RChild = S->RChild;
	T-> Rflag = S->Rflag;
	T-> LChild = S;
	T-> Lflag = 1;
	S-> RChild = T;
	S-> Rflag = 0;
	if ( ! T-> Rflag )				//找S右子树中的最左子孙
	{
		q = T-> RChild;
		while (!q-> Lflag)
		q = q-> LChild;
		q-> LChild = T;
	}
}


void main()
{    
	
	BinaryTreeNode1 *treeNode[7];
	char a='A';

	for(int i=0;i<7;i++)
	{
		treeNode[i]=MakeNode1(a);
		a++;
	}
	printf("二叉树的结构:\n");

	printf("\t\tA\n");
	printf("\t\t├──────┐\n");
	printf("\t\tB              C\n");
	printf("\t\t├───┐     └─┐\n");
	printf("\t\tD       E           F\n");
	printf("\t\t        └─┐\n");
	printf("\t\t             G\n");

	MakeBinaryTree1(treeNode[0],treeNode[1],treeNode[2]);//A:B(L) ,	C(R)
	MakeBinaryTree1(treeNode[1],treeNode[3],treeNode[4]);//B:D(L) ,	E(R)
	MakeBinaryTree1(treeNode[2],NULL,treeNode[5]);		//C:NULL(L) ,F(R)
	MakeBinaryTree1(treeNode[4],NULL,treeNode[6]);		//E:NULL(L) ,G(R)

	
	printf("中序非递归方式遍历二叉树的结果:\n");

	ThreadInOrder(treeNode[0]);//二叉树转化为前序线索树算法
	printf("\n\n中序二叉线索树的各个结点信息:\n");

	//打印线索树中各个结点中数据元素的信息
	prinfThreadInOrder(treeNode[3]);
	prinfThreadInOrder(treeNode[1]);
	prinfThreadInOrder(treeNode[6]);
	prinfThreadInOrder(treeNode[4]);
	prinfThreadInOrder(treeNode[0]);
	prinfThreadInOrder(treeNode[2]);
	prinfThreadInOrder(treeNode[5]);

	printf("\n\n中序二叉线索树的遍历结果:\n");
	InOrderThread(treeNode[0]);//中序二叉线索树的遍历算法

	printf("\n*****************************\n\n");
	system("pause");
	
	//C无左孩子
	//中序线索树中插入的新结点H作为C的左孩子
	printf("\n*中序线索树中插入的新结点H作为C的左孩子,**C无左孩子**\n\n");
	printf("预期结果如下\n\n");
	printf("\t\tA\n");
	printf("\t\t├────────┐\n");
	printf("\t\tB                  C\n");
	printf("\t\t├───┐    ┌─┷─┐\n");
	printf("\t\tD       E     H        F\n");
	printf("\t\t        └─┐\n");
	printf("\t\t             G\n");
	system("pause");

	a='H';
	BinaryTreeNode1 *H=MakeNode1(a);

	printf("\n插入前结点C中数据元素的信息:\n");
	prinfThreadInOrder(treeNode[2]);

	InOrderThreadInsertLeft(treeNode[2],H);

	printf("\n插入后结点C和H中数据元素的信息:\n");
	prinfThreadInOrder(treeNode[2]);
	prinfThreadInOrder(H);
	printf("\n\n插入后二叉线索树的遍历结果:\n");
	InOrderThread(treeNode[0]);//中序二叉线索树的遍历算法

	//A有左孩子
	//中序线索树中插入的新结点J作为A的左孩子
	
	printf("\n*****************************\n\n");
	system("pause");
	printf("\n*中序线索树中插入的新结点J作为A的左孩子,**A有左孩子**\n\n");

	printf("预期结果如下\n\n");
	printf("\t\tA\n");
	printf("\t\t├────────┐\n");
	printf("\t\tJ                  C\n");
	printf("\t\t│                │\n");
	printf("\t\tB                 │\n");
	printf("\t\t├───┐    ┌─┷─┐\n");
	printf("\t\tD       E     H        F\n");
	printf("\t\t        └─┐\n");
	printf("\t\t             G\n");
	system("pause");

	a='J';
	BinaryTreeNode1 *J=MakeNode1(a);
	printf("\n插入前结点A和E中数据元素的信息:\n");
	prinfThreadInOrder(treeNode[0]);
	prinfThreadInOrder(treeNode[6]);
	
	InOrderThreadInsertLeft(treeNode[0],J);
	printf("\n插入后结点A，E和J中数据元素的信息:\n");
	prinfThreadInOrder(treeNode[0]);
	prinfThreadInOrder(treeNode[6]);
	prinfThreadInOrder(J);

	printf("\n\n插入后二叉线索树的遍历结果:\n");
	InOrderThread(treeNode[0]);//中序二叉线索树的遍历算法

	//D没有右孩子
	//中序线索树中插入的新结点K作为D的右孩子
	
	printf("\n*****************************\n\n");
	system("pause");

	printf("\n*中序线索树中插入的新结点K作为D的右孩子,**D没有右孩子**\n\n");
	printf("预期结果如下\n\n");
	printf("\t\tA\n");
	printf("\t\t├────────┐\n");
	printf("\t\tJ                  C\n");
	printf("\t\t│                │\n");
	printf("\t\tB                 │\n");
	printf("\t\t├───┐    ┌─┷─┐\n");
	printf("\t\tD       E     H        F\n");
	printf("\t\t└─┐  └─┐\n");
	printf("\t\t     K       G\n");
	system("pause");

	a='K';
	BinaryTreeNode1 *K=MakeNode1(a);
	printf("\n插入前结点D中数据元素的信息:\n");
	prinfThreadInOrder(treeNode[3]);
	
	InOrderThreadInsertRight(treeNode[3],K);
	printf("\n插入后结点A，E和J中数据元素的信息:\n");
	prinfThreadInOrder(treeNode[3]);
	prinfThreadInOrder(K);

	printf("\n\n插入后二叉线索树的遍历结果:\n");
	InOrderThread(treeNode[0]);//中序二叉线索树的遍历算法

	//C有右孩子
	//中序线索树中插入的新结点M作为C的右孩子
	
	printf("\n*****************************\n\n");
	system("pause");

	printf("\n*中序线索树中插入的新结点M作为C的右孩子,**C有右孩子**\n\n");
	printf("预期结果如下\n\n");
	printf("\t\tA\n");
	printf("\t\t├────────┐\n");
	printf("\t\tJ                  C\n");
	printf("\t\t│                ├──┐\n");
	printf("\t\tB                 │    M\n");
	printf("\t\t├───┐        │    └─┐\n");
	printf("\t\tD       E         H          F\n");
	printf("\t\t└─┐  └─┐\n");
	printf("\t\t     K       G\n");
	system("pause");

	a='M';
	BinaryTreeNode1 *M=MakeNode1(a);
	printf("\n插入前结点C,F中数据元素的信息:\n");
	prinfThreadInOrder(treeNode[2]);
	prinfThreadInOrder(treeNode[5]);

	
	InOrderThreadInsertRight(treeNode[2],M);
	printf("\n插入后结点C，F和M中数据元素的信息:\n");
	prinfThreadInOrder(treeNode[2]);
	prinfThreadInOrder(treeNode[5]);
	prinfThreadInOrder(M);

	printf("\n\n插入后二叉线索树的遍历结果:\n");
	InOrderThread(treeNode[0]);//中序二叉线索树的遍历算法

	printf("\n");
	system("pause");

	 return;
     
} 