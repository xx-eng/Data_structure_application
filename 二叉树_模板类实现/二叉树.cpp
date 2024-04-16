// ������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binary.h"
#include <string.h>


char re_choose[]={"\nѡ��Ƿ�����������ȷ�ı��...\n"};
void Menu()    //�˵�����
{
	

	cout <<"\n\t\t"<<"��ѡ������һ������:"<<endl;
	cout <<"\n\t\t"<<"1.���������"<<endl;
	cout <<"\t\t2.�������н��ĸ���" << endl;
	cout <<"\t\t3.ǰ��ݹ����" << endl;
	cout <<"\t\t4.����ݹ����" << endl;
    cout <<"\t\t5.����ݹ����"<<endl;
	cout <<"\t\t6.ǰ��ǵݹ����" << endl;
	cout <<"\t\t7.����ǵݹ����" << endl;
    cout <<"\t\t8.����ǵݹ����"<<endl;
	cout <<"\t\t9.��α������ϵ��£����ң�"<<endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


}

void Display()
{//��ʾ
	cout<<"        "<<"����"<<endl;
	cout<<"         "<<"�u"<<endl;    //�v
	cout<<"      "<<"����"<<endl;
	cout<<"       "<<"�u"<<" �v"<<endl;
	cout<<"    "<<"����"<<" "<<"����"<<endl;
	cout<<"      "<<"�v"<<endl;
	cout<<"      "<<"Ф��"<<endl;
	
}


int main(int argc, char* argv[])
{
	int choice;
	int High,count;
	BinaryTreeNode *BTroot,*pp[10];
	ElementType newvalue;
	BinaryTree<ElementType> AppBT;

	char name[10][10]={"����","����","����","����","Ф��"};
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
		cout<<"��ѡ�����ܣ�";
		cin>>choice;
		cout<<endl;
		system("cls");
		Display();
		switch(choice)
		{
			case 1:
				{
					High = AppBT.Height(BTroot);
					cout<<"����"<<High<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 2:
				{
					count = 0;
					AppBT.NodesCount(BTroot,count);
					cout<<"�������н�����"<<count<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 3:
				{
					cout<<"       ��������ǰ��ݹ���������"<<endl;
					AppBT.PreOrderRecursive(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 4:
				{
					cout<<"       ������������ݹ���������"<<endl;
					AppBT.InOrderRecursive(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 5:
				{
					cout<<"       �������ĺ���ݹ���������"<<endl;
					AppBT.PostOrderRecursive(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 6:
				{
					cout<<"       ��������ǰ��ǵݹ���������"<<endl;
					AppBT.PreOrderNoRecursive(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 7:
				{
					cout<<"       ������������ǵݹ���������"<<endl;
					AppBT.InOrderNoRecursive(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 8:
				{
					cout<<"       �������ĺ���ǵݹ���������"<<endl;
					AppBT.PostOrderNoRecursive(BTroot);
					cout<<endl<<endl;
					system("pause");
					system("cls");
					break;
				}
			case 9:
				{
					cout<<"       �������Ĳ�α��������"<<endl;
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

