// ����.cpp : Defines the entry point for the console application.
//

/*1--��  
2--����                     3--��Դ
4--�ִ���                   5--�ִ���
6--�־�                  7--����          8--����                                            
9--����                  10--����    11--����  12--�ֱ���  13--�ֻ�   
14--����               */
#include "stdafx.h"
#include "TREE.h"
#include <stdlib.h>

ElementType  member[14];
BinaryTreeNode *treenode[14];

char re_choose[]={"\nѡ��Ƿ�����������ȷ�ı��...\n"};

void Menu_name()
     //������Ϣ
{   
	printf("\n\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                           ����\n\n");
	printf("                           ����:Ѧ��\n");
	printf("                           �༶:��Ϣ1802��\n");
	printf("                           ѧ��: 201821130093\n");
	printf("                           ָ����ʦ: �����\n");
	printf("              **************************************************\n");
	printf("\n\n\n\t\t");
}


void Menu()    //�˵�����
{
	

	cout <<"\n\t\t"<<"��ѡ������һ������:"<<endl;
	cout <<"\n\t\t"<<"1.��ʾ���г�Ա"<<endl;
	cout <<"\t\t2.���Һ���" << endl;
	cout <<"\t\t3.�����ֵ�" << endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


}

void maketree()
{
	for(int i=0;i<14;i++)
		member[i] = i+1;
	for(i=0;i<14;i++)
		treenode[i] = MakeNode(member[i]);
	MakeBinaryTree(treenode[0],treenode[1],NULL);
	MakeBinaryTree(treenode[1],treenode[3],treenode[2]);
	MakeBinaryTree(treenode[3],treenode[5],NULL);
	MakeBinaryTree(treenode[2],treenode[4],NULL);
	MakeBinaryTree(treenode[5],treenode[8],NULL);
	MakeBinaryTree(treenode[4],treenode[6],NULL);
	MakeBinaryTree(treenode[8],treenode[13],NULL);
	MakeBinaryTree(treenode[6],treenode[9],treenode[7]);
	MakeBinaryTree(treenode[7],treenode[10],NULL);
	MakeBinaryTree(treenode[10],NULL,treenode[11]);
	MakeBinaryTree(treenode[11],NULL,treenode[12]);
}

void foundbrothers(int searchkey)
{
	BinaryTreeNode *p = NULL;
	BinaryTreeNode *q = NULL;
	BinaryTreeNode *t = NULL;
	int x = 0;
	int count = 0;
	NodesCount(treenode[0],count);
	QueueType temp;
	Queue Q;
	CreateQueue(Q,count);
	p = treenode[0];
	temp.ptr = p;
	EnQueue(Q,temp);
	while( !IsEmpty(Q))
	{
		DeQueue(Q,temp);      
		p = temp.ptr;
		q = p;
		t = p;
		while(t)
		{
			if(t->data == searchkey)
				break;
			t = t->next;
		}
		if(t)
		{
			while(q)
			{
				Displaynode(q);
				q = q->next;
			}
		}
		while(p)
		{
		//	Displaynode(p);
		//	cout<<endl;

			temp.ptr = p->son;
			if(p->son)   EnQueue(Q,temp);
			
			p = p->next;
		}
	}

	
}


void main_switch(char j)
{
	int searchkey;
	maketree();
	switch(j)
	{
	case '1'://��ʾ��������
		cout<<"                     ��"<<endl;
		cout<<"                �u         �v"<<endl;//�u�v
		cout<<"             ����          ��Դ"<<endl;
		cout<<"             �u            �u"<<endl;
		cout<<"          �ִ���        �ִ���"<<endl;
		cout<<"          �u            �u  �v"<<endl;
		cout<<"        �־�         ����  ����"<<endl;
		cout<<"       �u           �u     �u   ��  �v"<<endl;
		cout<<"     ����         ����  ���� �ֱ��� �ֻ�"<<endl;
		cout<<"     �u "<<endl;
		cout<<"   ����"<<endl;
		system("pause");
		system("cls");
		break;

	case'2':
		cout<<"                     ��"<<endl;
		cout<<"                �u         �v"<<endl;//�u�v
		cout<<"             ����          ��Դ"<<endl;
		cout<<"             �u            �u"<<endl;
		cout<<"          �ִ���        �ִ���"<<endl;
		cout<<"          �u            �u  �v"<<endl;
		cout<<"        �־�         ����  ����"<<endl;
		cout<<"       �u           �u     �u   ��  �v"<<endl;
		cout<<"     ����         ����  ���� �ֱ��� �ֻ�"<<endl;
		cout<<"     �u "<<endl;
		cout<<"   ����"<<endl;
		cout<<"��������Ҫ�����ĺ��ӵ��ˣ�\n\n";
		cout<<"1--��  2--����  3--��Դ  4--�ִ���  5--�ִ���"<<endl;
		cout<<"6--�־�  7--����  8--���� 9--���� 10--����  11--����"<<endl;  
		cout<<"12--�ֱ���  13--�ֻ�  14--���� "<<endl;
		cin>>searchkey;
		Degree(treenode[searchkey-1]);
		system("pause");
		system("cls");
		break;

	case'3':
		cout<<"                     ��"<<endl;
		cout<<"                �u         �v"<<endl;//�u�v
		cout<<"             ����          ��Դ"<<endl;
		cout<<"             �u            �u"<<endl;
		cout<<"          �ִ���        �ִ���"<<endl;
		cout<<"          �u            �u  �v"<<endl;
		cout<<"        �־�         ����  ����"<<endl;
		cout<<"       �u           �u     �u   ��  �v"<<endl;
		cout<<"     ����         ����  ���� �ֱ��� �ֻ�"<<endl;
		cout<<"     �u "<<endl;
		cout<<"   ����"<<endl;
		cout<<"��������Ҫ�������ֵܵ��ˣ�\n\n";
		cout<<"1--��  2--����  3--��Դ  4--�ִ���  5--�ִ���"<<endl;
		cout<<"6--�־�  7--����  8--���� 9--���� 10--����  11--����"<<endl;  
		cout<<"12--�ֱ���  13--�ֻ�  14--���� "<<endl;
		cin>>searchkey;
		cout<<"�ֵ���"<<endl;
		foundbrothers(searchkey);

		system("pause");
		system("cls");
		break;

	case'0':
		exit(0);
		break;
	default  :
		cout <<re_choose<<endl;
		system("pause");
		system("cls");
		break;
	}
}



int main(int argc, char* argv[])
{

	Menu_name();
	system("pause");
	system("cls");
	char a[100];

	while(1)
	{
		system("cls");
		Menu();	
		printf("\n\t�����빦�ܱ��:");
	
		gets(a);	
	
       if(a[1]!='\0')
		{
			cout <<"\n"<<re_choose<<endl;
			system("pause");
			system("cls");
			continue;
		}
        else
		{
			if(a[0]=='0') 
				break;	
			main_switch(a[0]);		
			
		}

	}
	

	
	return 0;
}

