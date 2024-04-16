// 二叉树.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binary.h"
#include <string.h>


char re_choose[]={"\n选择非法，请输入正确的编号...\n"};
void Menu()    //菜单函数
{
	

	cout <<"\n\t\t"<<"请选择以下一个功能:"<<endl;
	cout <<"\n\t\t"<<"1.求树的深度"<<endl;
	cout <<"\t\t2.二叉树中结点的个数" << endl;
	cout <<"\t\t3.前序递归遍历" << endl;
	cout <<"\t\t4.中序递归遍历" << endl;
    cout <<"\t\t5.后序递归遍历"<<endl;
	cout <<"\t\t6.前序非递归遍历" << endl;
	cout <<"\t\t7.中序非递归遍历" << endl;
    cout <<"\t\t8.后序非递归遍历"<<endl;
	cout <<"\t\t9.层次遍历（上到下，左到右）"<<endl;
	cout <<"\t\t0.退出.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


}

void Display()
{//显示
	cout<<"        "<<"彭亮"<<endl;
	cout<<"         "<<"╱"<<endl;    //╲
	cout<<"      "<<"王明"<<endl;
	cout<<"       "<<"╱"<<" ╲"<<endl;
	cout<<"    "<<"李智"<<" "<<"刘丹"<<endl;
	cout<<"      "<<"╲"<<endl;
	cout<<"      "<<"肖象"<<endl;
	
}


int main(int argc, char* argv[])
{
	int choice;
	int High,count;
	BinaryTreeNode *BTroot,*pp[10];
	ElementType newvalue;
	BinaryTree<ElementType> AppBT;

	char name[10][10]={"彭亮","王明","李智","刘丹","肖象"};
	int No[5]={1001,1002,1003,1004,1005};
	for(int i=0;i<5;i++)
	{
		newvalue.number = No[i];
		strcpy(newvalue.name,name[i]);
		pp[i] = AppBT.MakeNode(newvalue);
	}
	AppBT.MakeBinaryTree(pp[0],pp[1],NULL);
	AppBT.MakeBinaryTree(pp[1],pp[2],pp[3]);
	AppBT.MakeBinaryTree(pp[2],NULL,pp[4]);
	BTroot = pp[0];

	while(true)
	{
		Menu();
		cout<<"请选择处理功能：";
		cin>>choice;
		cout<<endl;
		system("cls");
		Display();
		switch(choice)
		{
			case 1:
				{
					High = AppBT.Height(BTroot);
					cout<<"树高"<<High<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 2:
				{
					count = 0;
					AppBT.NodesCount(BTroot,count);
					cout<<"二叉树中结点个数"<<count<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 3:
				{
					cout<<"       二叉树的前序递归遍历结果："<<endl;
					AppBT.PreOrderRecursive(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 4:
				{
					cout<<"       二叉树的中序递归遍历结果："<<endl;
					AppBT.InOrderRecursive(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 5:
				{
					cout<<"       二叉树的后序递归遍历结果："<<endl;
					AppBT.PostOrderRecursive(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 6:
				{
					cout<<"       二叉树的前序非递归遍历结果："<<endl;
					AppBT.PreOrderNoRecursive(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 7:
				{
					cout<<"       二叉树的中序非递归遍历结果："<<endl;
					AppBT.InOrderNoRecursive(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 8:
				{
					cout<<"       二叉树的后序非递归遍历结果："<<endl;
					AppBT.PostOrderNoRecursive(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 9:
				{
					cout<<"       二叉树的层次遍历结果："<<endl;
					AppBT.LevelOrder_LtoR_UtoD(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 0:
				{
					return 0;
					break;
				}
				system("pause");
				system("cls");

		}
		

	}
	

	return 0;
}

