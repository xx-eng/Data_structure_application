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
{//������ת��Ϊǰ���������㷨
	ChainStack		*S;		//������ʽջ
	BinaryTreeNode1	*p=BT;
	BinaryTreeNode1	*q=NULL;		//qʼ��ָ��p���ǰ��


	S=CreatStack();		//����һ����ջ����һ���̺������Բ����������

	while (p||!IsEmpty(S))
	{
		while (p)
		{
		//	p->Lflag=0;
			Push(S,p);				//�����ָ�루δ���ʣ���ջ���Ժ��˷ʱ����ջ
			if (p->LChild)				//���p�������������������ƽ�
			{			
				p->Lflag=0;  
				p=p->LChild;  
			}
			else			
			{//���pû����������p����������ָ��ǰ������׼����ջ
				p->Lflag = 1;   
				p->LChild= q; 	
				q=p; 	
				p=NULL;			//p��ΪNULLΪ����ǿ����ջ
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
{//��������������ı���
	BinaryTreeNode1	*p=BT;
	bool 	flag=false;

	while(p)	
	{
		while(!p->Lflag) 		//����һ����������������
			p=p->LChild;
		
		
		flag=true;
		while(flag&&p)
		{ 
			printf("%c  ",p->data); //���ʽ��
			p=p->RChild;				//����p���������ĸ����̽��

			if (p&&!p->Rflag)				//p������������ʱ��Ϊǿ���˳���׼��
			{
				printf("%c  ",p->data);
				flag =NULL;
				p=p->RChild;
			}
		}
	}
}

void InOrderThreadInsertLeft(BinaryTreeNode1 *S, BinaryTreeNode1 *T ) 
{//�����������в�����½��T��ΪS�������㷨
	BinaryTreeNode1	*q;
	T->LChild = S->LChild;
	T-> Lflag = S-> Lflag;
	T-> RChild = S;
	T-> Rflag = 1;
	S-> LChild = T;
	S-> Lflag = 0;
	if ( ! T-> Lflag )				//��S�������е���������
	{
		q = T-> LChild;
		while (!q-> Rflag)
			q = q-> RChild;
		q-> RChild =T;
	}
}


//�����������в�����½��T��ΪS���Һ����㷨��InOrderThreadInsertRight��
                                                                                 
void InOrderThreadInsertRight(BinaryTreeNode1 *S, BinaryTreeNode1 *T ) 
{//�����������в�����½��T��ΪS�������㷨
	BinaryTreeNode1	*q;
	T->RChild = S->RChild;
	T-> Rflag = S->Rflag;
	T-> LChild = S;
	T-> Lflag = 1;
	S-> RChild = T;
	S-> Rflag = 0;
	if ( ! T-> Rflag )				//��S�������е���������
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
	printf("�������Ľṹ:\n");

	printf("\t\tA\n");
	printf("\t\t����������������\n");
	printf("\t\tB              C\n");
	printf("\t\t����������     ������\n");
	printf("\t\tD       E           F\n");
	printf("\t\t        ������\n");
	printf("\t\t             G\n");

	MakeBinaryTree1(treeNode[0],treeNode[1],treeNode[2]);//A:B(L) ,	C(R)
	MakeBinaryTree1(treeNode[1],treeNode[3],treeNode[4]);//B:D(L) ,	E(R)
	MakeBinaryTree1(treeNode[2],NULL,treeNode[5]);		//C:NULL(L) ,F(R)
	MakeBinaryTree1(treeNode[4],NULL,treeNode[6]);		//E:NULL(L) ,G(R)

	
	printf("����ǵݹ鷽ʽ�����������Ľ��:\n");

	ThreadInOrder(treeNode[0]);//������ת��Ϊǰ���������㷨
	printf("\n\n��������������ĸ��������Ϣ:\n");

	//��ӡ�������и������������Ԫ�ص���Ϣ
	prinfThreadInOrder(treeNode[3]);
	prinfThreadInOrder(treeNode[1]);
	prinfThreadInOrder(treeNode[6]);
	prinfThreadInOrder(treeNode[4]);
	prinfThreadInOrder(treeNode[0]);
	prinfThreadInOrder(treeNode[2]);
	prinfThreadInOrder(treeNode[5]);

	printf("\n\n��������������ı������:\n");
	InOrderThread(treeNode[0]);//��������������ı����㷨

	printf("\n*****************************\n\n");
	system("pause");
	
	//C������
	//�����������в�����½��H��ΪC������
	printf("\n*�����������в�����½��H��ΪC������,**C������**\n\n");
	printf("Ԥ�ڽ������\n\n");
	printf("\t\tA\n");
	printf("\t\t��������������������\n");
	printf("\t\tB                  C\n");
	printf("\t\t����������    �����۩���\n");
	printf("\t\tD       E     H        F\n");
	printf("\t\t        ������\n");
	printf("\t\t             G\n");
	system("pause");

	a='H';
	BinaryTreeNode1 *H=MakeNode1(a);

	printf("\n����ǰ���C������Ԫ�ص���Ϣ:\n");
	prinfThreadInOrder(treeNode[2]);

	InOrderThreadInsertLeft(treeNode[2],H);

	printf("\n�������C��H������Ԫ�ص���Ϣ:\n");
	prinfThreadInOrder(treeNode[2]);
	prinfThreadInOrder(H);
	printf("\n\n���������������ı������:\n");
	InOrderThread(treeNode[0]);//��������������ı����㷨

	//A������
	//�����������в�����½��J��ΪA������
	
	printf("\n*****************************\n\n");
	system("pause");
	printf("\n*�����������в�����½��J��ΪA������,**A������**\n\n");

	printf("Ԥ�ڽ������\n\n");
	printf("\t\tA\n");
	printf("\t\t��������������������\n");
	printf("\t\tJ                  C\n");
	printf("\t\t��                ��\n");
	printf("\t\tB                 ��\n");
	printf("\t\t����������    �����۩���\n");
	printf("\t\tD       E     H        F\n");
	printf("\t\t        ������\n");
	printf("\t\t             G\n");
	system("pause");

	a='J';
	BinaryTreeNode1 *J=MakeNode1(a);
	printf("\n����ǰ���A��E������Ԫ�ص���Ϣ:\n");
	prinfThreadInOrder(treeNode[0]);
	prinfThreadInOrder(treeNode[6]);
	
	InOrderThreadInsertLeft(treeNode[0],J);
	printf("\n�������A��E��J������Ԫ�ص���Ϣ:\n");
	prinfThreadInOrder(treeNode[0]);
	prinfThreadInOrder(treeNode[6]);
	prinfThreadInOrder(J);

	printf("\n\n���������������ı������:\n");
	InOrderThread(treeNode[0]);//��������������ı����㷨

	//Dû���Һ���
	//�����������в�����½��K��ΪD���Һ���
	
	printf("\n*****************************\n\n");
	system("pause");

	printf("\n*�����������в�����½��K��ΪD���Һ���,**Dû���Һ���**\n\n");
	printf("Ԥ�ڽ������\n\n");
	printf("\t\tA\n");
	printf("\t\t��������������������\n");
	printf("\t\tJ                  C\n");
	printf("\t\t��                ��\n");
	printf("\t\tB                 ��\n");
	printf("\t\t����������    �����۩���\n");
	printf("\t\tD       E     H        F\n");
	printf("\t\t������  ������\n");
	printf("\t\t     K       G\n");
	system("pause");

	a='K';
	BinaryTreeNode1 *K=MakeNode1(a);
	printf("\n����ǰ���D������Ԫ�ص���Ϣ:\n");
	prinfThreadInOrder(treeNode[3]);
	
	InOrderThreadInsertRight(treeNode[3],K);
	printf("\n�������A��E��J������Ԫ�ص���Ϣ:\n");
	prinfThreadInOrder(treeNode[3]);
	prinfThreadInOrder(K);

	printf("\n\n���������������ı������:\n");
	InOrderThread(treeNode[0]);//��������������ı����㷨

	//C���Һ���
	//�����������в�����½��M��ΪC���Һ���
	
	printf("\n*****************************\n\n");
	system("pause");

	printf("\n*�����������в�����½��M��ΪC���Һ���,**C���Һ���**\n\n");
	printf("Ԥ�ڽ������\n\n");
	printf("\t\tA\n");
	printf("\t\t��������������������\n");
	printf("\t\tJ                  C\n");
	printf("\t\t��                ��������\n");
	printf("\t\tB                 ��    M\n");
	printf("\t\t����������        ��    ������\n");
	printf("\t\tD       E         H          F\n");
	printf("\t\t������  ������\n");
	printf("\t\t     K       G\n");
	system("pause");

	a='M';
	BinaryTreeNode1 *M=MakeNode1(a);
	printf("\n����ǰ���C,F������Ԫ�ص���Ϣ:\n");
	prinfThreadInOrder(treeNode[2]);
	prinfThreadInOrder(treeNode[5]);

	
	InOrderThreadInsertRight(treeNode[2],M);
	printf("\n�������C��F��M������Ԫ�ص���Ϣ:\n");
	prinfThreadInOrder(treeNode[2]);
	prinfThreadInOrder(treeNode[5]);
	prinfThreadInOrder(M);

	printf("\n\n���������������ı������:\n");
	InOrderThread(treeNode[0]);//��������������ı����㷨

	printf("\n");
	system("pause");

	 return;
     
} 