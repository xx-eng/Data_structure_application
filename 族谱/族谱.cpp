// 族谱.cpp : Defines the entry point for the console application.
//

/*1--贾  
2--贾演                     3--贾源
4--贾代化                   5--贾代善
6--贾敬                  7--贾赦          8--贾政                                            
9--贾珍                  10--贾琏    11--贾珠  12--贾宝玉  13--贾环   
14--贾蓉               */
#include "stdafx.h"
#include "TREE.h"
#include <stdlib.h>

ElementType  member[14];
BinaryTreeNode *treenode[14];

char re_choose[]={"\n选择非法，请输入正确的编号...\n"};

void Menu_name()
     //作者信息
{   
	printf("\n\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                           族谱\n\n");
	printf("                           制作:薛利\n");
	printf("                           班级:信息1802班\n");
	printf("                           学号: 201821130093\n");
	printf("                           指导老师: 孙夫雄\n");
	printf("              **************************************************\n");
	printf("\n\n\n\t\t");
}


void Menu()    //菜单函数
{
	

	cout <<"\n\t\t"<<"请选择以下一个功能:"<<endl;
	cout <<"\n\t\t"<<"1.显示所有成员"<<endl;
	cout <<"\t\t2.查找孩子" << endl;
	cout <<"\t\t3.查找兄弟" << endl;
	cout <<"\t\t0.退出.\n"<<endl;
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
	case '1'://显示树中数据
		cout<<"                     贾"<<endl;
		cout<<"                ╱         ╲"<<endl;//╱╲
		cout<<"             贾演          贾源"<<endl;
		cout<<"             ╱            ╱"<<endl;
		cout<<"          贾代化        贾代善"<<endl;
		cout<<"          ╱            ╱  ╲"<<endl;
		cout<<"        贾敬         贾赦  贾政"<<endl;
		cout<<"       ╱           ╱     ╱   ｜  ╲"<<endl;
		cout<<"     贾珍         贾琏  贾珠 贾宝玉 贾环"<<endl;
		cout<<"     ╱ "<<endl;
		cout<<"   贾蓉"<<endl;
		system("pause");
		system("cls");
		break;

	case'2':
		cout<<"                     贾"<<endl;
		cout<<"                ╱         ╲"<<endl;//╱╲
		cout<<"             贾演          贾源"<<endl;
		cout<<"             ╱            ╱"<<endl;
		cout<<"          贾代化        贾代善"<<endl;
		cout<<"          ╱            ╱  ╲"<<endl;
		cout<<"        贾敬         贾赦  贾政"<<endl;
		cout<<"       ╱           ╱     ╱   ｜  ╲"<<endl;
		cout<<"     贾珍         贾琏  贾珠 贾宝玉 贾环"<<endl;
		cout<<"     ╱ "<<endl;
		cout<<"   贾蓉"<<endl;
		cout<<"请输入你要找他的孩子的人：\n\n";
		cout<<"1--贾  2--贾演  3--贾源  4--贾代化  5--贾代善"<<endl;
		cout<<"6--贾敬  7--贾赦  8--贾政 9--贾珍 10--贾琏  11--贾珠"<<endl;  
		cout<<"12--贾宝玉  13--贾环  14--贾蓉 "<<endl;
		cin>>searchkey;
		Degree(treenode[searchkey-1]);
		system("pause");
		system("cls");
		break;

	case'3':
		cout<<"                     贾"<<endl;
		cout<<"                ╱         ╲"<<endl;//╱╲
		cout<<"             贾演          贾源"<<endl;
		cout<<"             ╱            ╱"<<endl;
		cout<<"          贾代化        贾代善"<<endl;
		cout<<"          ╱            ╱  ╲"<<endl;
		cout<<"        贾敬         贾赦  贾政"<<endl;
		cout<<"       ╱           ╱     ╱   ｜  ╲"<<endl;
		cout<<"     贾珍         贾琏  贾珠 贾宝玉 贾环"<<endl;
		cout<<"     ╱ "<<endl;
		cout<<"   贾蓉"<<endl;
		cout<<"请输入你要找他的兄弟的人：\n\n";
		cout<<"1--贾  2--贾演  3--贾源  4--贾代化  5--贾代善"<<endl;
		cout<<"6--贾敬  7--贾赦  8--贾政 9--贾珍 10--贾琏  11--贾珠"<<endl;  
		cout<<"12--贾宝玉  13--贾环  14--贾蓉 "<<endl;
		cin>>searchkey;
		cout<<"兄弟有"<<endl;
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
		printf("\n\t请输入功能编号:");
	
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

