// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binary.h"



char re_choose[]={"\n选择非法，请输入正确的编号...\n"};
ElementType Student[5];
ElementType Student1[10];
BinaryTreeNode *treenode[5];//系统自动创建结点
BinaryTreeNode *treenode1[10];       //输入数据
int tree[10]= {0};    //结点间的关系
int N;


void Menu_name()
     //作者信息
{   
	printf("\n\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                           二叉树的遍历\n\n");
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
	cout <<"\n\t\t"<<"1.显示树中数据"<<endl;
	cout <<"\t\t2.前序遍历" << endl;
	cout <<"\t\t3.中序遍历" << endl;
    cout <<"\t\t4.后序遍历"<<endl;
	cout <<"\t\t5.层次遍历（上到下，左到右）"<<endl;
	cout <<"\t\t0.退出.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


}

//**********************系统自动生成 ****************************
void automaking()
{
	char name[10][10]={"彭亮","王明","李智","刘丹","肖象"};
	
	int No[5]={1001,1002,1003,1004,1005};
	
	for(int i=0;i<5;i++)
	{
		Student[i].number = No[i];
		strcpy(Student[i].name,name[i]);
		treenode[i] = MakeNode(Student[i]);
	}
	MakeBinaryTree(treenode[0],treenode[1],NULL);
	MakeBinaryTree(treenode[1],treenode[2],treenode[3]);
	MakeBinaryTree(treenode[2],NULL,treenode[4]);
}





void main_switch1(char j)
{
	switch(j)
	{
	case '1'://显示树中数据
		Display(treenode);
		system("pause");
		break;
	case'2':
		Display(treenode);
		PreRecursive(treenode[0]);
		system("pause");
		system("cls");
		break;
	case'3':
		Display(treenode);
		InRecursive(treenode[0]);
		system("pause");
		system("cls");
		break;
	case'4':
		Display(treenode);
		PostRecursive(treenode[0]);
		system("pause");
		system("cls");
		break;
	case'5':
		Display(treenode);
		Level_L_R_U_D(treenode[0]);
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
//************************************************************

void importdata(int N)
{
	int j=1,k=1;
	int x=0;
	for(int i=0;i<N;i++)
	{
		cout<<"第"<<i+1<<"个数据："<<endl;
		cout<<"学号";
		cin>>Student1[i].number ;
		cout<<"  姓名";
		cin>>Student1[i].name;
		cout<<"    您想要它在哪里（按照顺序二叉树的方法输入数字）";
		cin>>tree[i];
		cout<<endl<<endl;
	}

	for(i=0;i<N;i++)
	{
		treenode1[i] = MakeNode(Student1[i]);
	}
	for(i=0;i<N;i++)
	{
		x = 2*tree[i];
		if(x <=  tree[N-1])
		{
			for(j = 1;j<N+1;j++)
			{
				if(tree[j-1] == x)      //左孩子
					break;
			}
			if(j == N+1)
				j=0;
		}
		else
			j=0;
		x = 2*tree[i]+1;
		if(x<=tree[N-1])
		{
			for(k=1;k<N+1;k++)
			{
				if(tree[k-1] == x)           //有孩子
					break;
			}
			if(k == N+1)
				k=0;
		}
		else
			k=0;

		if(j == 0 && k !=0)
		{
			MakeBinaryTree(treenode1[i],NULL,treenode1[k-1]);
		}
		if(j != 0 && k ==0)
		{
			MakeBinaryTree(treenode1[i],treenode1[j-1],NULL);
		}
		if(j != 0 && k !=0)
		{
			MakeBinaryTree(treenode1[i],treenode1[j-1],treenode1[k-1]);
		}
		j=0;
		k=0;
	}
	
}

void Display1(BinaryTreeNode *treenode[10],int tree[10],int N)
{
	for(int i=0;i<N;i++)
	{
		cout<<"姓名"<<treenode[i]->data.name<<"  学号"<<treenode[i]->data.number<<endl;
		cout<<"第"<<tree[i]<<"个"<<endl<<endl;
	}
}


void main_switch2(char j,int N)
{
	switch(j)
	{
	case '1'://显示树中数据
		Display1(treenode1,tree,N);
		system("pause");
		break;
	case'2':
		Display1(treenode1,tree,N);
		PreRecursive(treenode1[0]);
		system("pause");
		system("cls");
		break;
	case'3':
		Display1(treenode1,tree,N);
		InRecursive(treenode1[0]);
		system("pause");
		system("cls");
		break;
	case'4':
		Display1(treenode1,tree,N);
		PostRecursive(treenode1[0]);
		system("pause");
		system("cls");
		break;
	case'5':
		Display1(treenode1,tree,N);
		Level_L_R_U_D(treenode1[0]);
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


//#########################挑选你要的方式########################
void main_putin(char j)
{//输入数据的选择………………………………
	char b[100];
	switch(j)
	{	
		case '1' ://显示线性表中的数据元素
			system("cls");
			automaking();
			while(1)
			{
				system("cls");
				Menu();	
				printf("\n\t请输入功能编号:");
	
				gets(b);	
	
				if(b[1]!='\0')
				{
					cout <<"\n"<<re_choose<<endl;
					system("pause");
					system("cls");
					continue;
				}
				 else
				{
					if(b[0]=='0') 
					break;	
					main_switch1(b[0]);		
				}

			}
			break;

		case'2':
			cout<<"您要输入几个数据（不超过10个 且第一个为根节点）：";
			cin>>N;
			cout<<endl;
			
			importdata(N);

			while(1)
			{
				system("cls");
				Menu();	
				printf("\n\t请输入功能编号:");
	
				gets(b);	
	
				if(b[1]!='\0')
				{
					cout <<"\n"<<re_choose<<endl;
					system("pause");
					system("cls");
					continue;
				}
				 else
				{
					if(b[0]=='0') 
					break;	
					main_switch2(b[0],N);		
				}


			}

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
//#######################################################





int main(int argc, char* argv[])
{
	Menu_name();
	system("pause");
	system("cls");
	char a[100];

	while(1)
	{
		system("cls");
		printf("\n\t系统自动生成——1，还是自己输入——2, exit--0:");
	
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
			main_putin(a[0]);		
			
		}

	}
	return 0;
}

