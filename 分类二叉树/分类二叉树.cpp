// 分类二叉树.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SortBT.h"
#include <string.h>
#include <stdlib.h>

Student student[10];
ElementType heap[20];
BinaryTreeNode *BT = NULL;
#define  HeapSize 10           //这个，刚开始不太清楚它的大小
char re_choose[]={"\n选择非法，请输入正确的编号...\n"};

void Menu_name()
     //作者信息
{   
	printf("\n\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                           分类二叉树\n\n");
	printf("                           制作:薛莉\n");
	printf("                           班级:信息1802班\n");
	printf("                           学号: 201821130093\n");
	printf("                           指导老师: 孙夫雄\n");
	printf("              **************************************************\n");
	printf("\n\n\n\t\t");
}

//****************************************************

void Menu1()    //菜单函数
{
	cout <<"\n\t\t"<<"请选择以下一个功能:"<<endl;
	cout <<"\n\t\t"<<"1.显示树中数据"<<endl;
	cout <<"\t\t2.对数据进行排序" << endl;
	cout <<"\t\t3.查找" << endl;
    cout <<"\t\t4.删除"<<endl;
	cout <<"\t\t5.插入"<<endl;
	cout <<"\t\t0.退出.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;

}


BinaryTreeNode *makingtree()
{

	char name[10][10]={"穆兰","彭亮","王明","李智","刘丹","肖象","王强","李明","张志","赵志"};
	float CPMark[10]={78.0, 84.0 ,75.0, 90.0, 80.0, 85.0 ,94.0, 81.0, 85.0, 83.0};
	float DSMark[10]={82.0, 70.0 ,88.0 ,84.0 ,95.0, 83.0, 88.0 ,84.0, 88.0, 78.0};
	float PGMark[10]={90.0, 78.0, 92.0 ,66.0 ,77.0, 85.0, 89.0 ,79.0, 95.0, 87.0};
	float Average[10]={83.0, 78.0, 86.0, 80.0 ,84.0, 85.0, 90.0, 82.0, 91.0, 87.0};
	int No[10]={1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
	for(int i=0;i<10;i++)
	{
		strcpy(student[i].Name,name[i]);		
 		student[i].CPMark=CPMark[i];	
		student[i].DSMark=DSMark[i];
		student[i].PGMark=PGMark[i];
		student[i].Average=Average[i];
		student[i].No=No[i];

	}
	BinaryTreeNode *BT = MakeNode(student[0]);
	for(i=0;i<10;i++)
	{
		Insert(BT,student[i]);
	}
	return BT;
}

void Display(BinaryTreeNode *BT)
{
	cout<<"********************************************************"<<endl;
	cout<<"  学号  姓名  计算机基础  数据结构  程序设计  平均成绩  "<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<"  "<<student[i].No<<"  "<<student[i].Name<<"      "
			<<student[i].CPMark<<"        "<<student[i].DSMark<<"         "
			<<student[i].PGMark<<"       "<<student[i].key<<endl;
	}
	cout<<"********************************************************"<<endl;
	
}

void main_switch1(char j)
{
	ElementType result;
	ElementType newvalue;
	int SearchKey;
	switch(j)
	{
	case '1'://显示树中数据
		BT = makingtree();
		Display(BT);
		system("pause");
		system("cls");
		break;
	case'2':
		BT = makingtree();
		cout<<"按平均成绩排序"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  学号  姓名  计算机基础  数据结构  程序设计  平均成绩  "<<endl;
		InOrderRecurseive(BT);
		system("pause");
		system("cls");
		break;
	case'3':
		BT = makingtree();
		cout<<"按平均成绩排序"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  学号  姓名  计算机基础  数据结构  程序设计  平均成绩  "<<endl;
		InOrderRecurseive(BT);

		cout<<"要查找的人的平均成绩";
		cin>>SearchKey;
		cout<<endl;
		if(Search(BT,result,SearchKey))
		{
			cout<<"学号"<<result.No<<"  姓名"<<result.Name<<endl;
			cout<<"  计算机基础"<<result.CPMark<<"  数据结构"<<result.DSMark
			<<"  程序设计"<<result.PGMark<<"  平均"<<result.key<<endl;
		}
		else
			cout<<"未找到该人"<<endl;
		system("pause");
		system("cls");
		break;
	case'4':
		BT = makingtree();
		cout<<"按平均成绩排序"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  学号  姓名  计算机基础  数据结构  程序设计  平均成绩  "<<endl;
		InOrderRecurseive(BT);

		cout<<"要删除的人的平均成绩";
		cin>>SearchKey;
		cout<<endl;
		Delete(BT,SearchKey);
		cout<<"********************************************************"<<endl;
		cout<<"  学号  姓名  计算机基础  数据结构  程序设计  平均成绩  "<<endl;
		InOrderRecurseive(BT);
		system("pause");
		system("cls");
		break;
	case'5':
		BT = makingtree();
		cout<<"按平均成绩排序"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  学号  姓名  计算机基础  数据结构  程序设计  平均成绩  "<<endl;
		InOrderRecurseive(BT);
		
		cout<<"要插入的人的学号";
		cin>>newvalue.No ;
		cout<<"   姓名";
		cin>>newvalue.Name;
		cout<<"   计算机基础";
		cin>>newvalue.CPMark;
		cout<<"   数据结构";
		cin>>newvalue.DSMark;
		cout<<"   程序设计";
		cin>>newvalue.PGMark;
		cout<<"   平均成绩";
		cin>>newvalue.key;
		cout<<endl;
		Insert(BT,newvalue);
		cout<<"按平均成绩排序"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  学号  姓名  计算机基础  数据结构  程序设计  平均成绩  "<<endl;
		InOrderRecurseive(BT);
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

void makeheaptree()
{
	char name[11][10]={"姓名","穆兰","彭亮","王明","李智","刘丹","肖象","王强","李明","张志","赵志"};
	float CPMark[11]={0.0 ,78.0, 84.0 ,75.0, 90.0, 80.0, 85.0 ,94.0, 81.0, 85.0, 83.0};
	float DSMark[11]={0.0 ,82.0, 70.0 ,88.0 ,84.0 ,95.0, 83.0, 88.0 ,84.0, 88.0, 78.0};
	float PGMark[11]={0.0 ,90.0, 78.0, 92.0 ,66.0 ,77.0, 85.0, 89.0 ,79.0, 95.0, 87.0};
	float Average[11]={0.0 ,83.0, 78.0, 86.0, 80.0 ,84.0, 85.0, 90.0, 82.0, 91.0, 87.0};
	int No[11]={0000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
	for(int i=0;i<11;i++)
	{
		strcpy(heap[i].Name ,name[i]);		
 		heap[i].CPMark=CPMark[i];	
		heap[i].DSMark=DSMark[i];
		heap[i].PGMark=PGMark[i];
		heap[i].Average=Average[i];
		heap[i].No=No[i];
	}

}

void Displayheap(ElementType heap[20],int size)
{
	cout<<"********************************************************"<<endl;
	cout<<"  学号  姓名  计算机基础  数据结构  程序设计  平均成绩  "<<endl;
	for(int i=1;i<size+1;i++)
	{
		cout<<"  "<<heap[i].No<<"  "<<heap[i].Name<<"      "
			<<heap[i].CPMark<<"        "<<heap[i].DSMark<<"         "
			<<heap[i].PGMark<<"       "<<heap[i].key<<endl;
	}
	cout<<"********************************************************"<<endl;
	
}

void Menu2()    //菜单函数
{
	cout <<"\n\t\t"<<"请选择以下一个功能:"<<endl;
	cout <<"\n\t\t"<<"1.显示树中数据"<<endl;
	cout <<"\t\t2.对数据进行排序" << endl;
	cout <<"\t\t3.插入" << endl;
	cout <<"\t\t0.退出.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;

}

void main_switch2(char j)
{
	ElementType newvalue;
	switch(j)
	{
	case '1'://显示树中数据
		InitializeMaxHeap(heap,HeapSize);
		Displayheap(heap,HeapSize);
		system("pause");
		system("cls");
		break;
	case'2':
		Displayheap(heap,HeapSize);
		HEAPSORT(heap,HeapSize);
		cout<<"按平均成绩排序"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  学号  姓名  计算机基础  数据结构  程序设计  平均成绩  "<<endl;
		Displayheap(heap,HeapSize);
		system("pause");
		system("cls");
		break;
	case'3':
		InitializeMaxHeap(heap,HeapSize);
		Displayheap(heap,HeapSize);
		cout<<"要插入的人的学号";
		cin>>newvalue.No ;
		cout<<"   姓名";
		cin>>newvalue.Name;
		cout<<"   计算机基础";
		cin>>newvalue.CPMark;
		cout<<"   数据结构";
		cin>>newvalue.DSMark;
		cout<<"   程序设计";
		cin>>newvalue.PGMark;
		cout<<"   平均成绩";
		cin>>newvalue.key;
		cout<<endl;
		InsertMaxHeap(heap,HeapSize,newvalue);
		Displayheap(heap,HeapSize+1);
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



void main_switch(char j)
{
	char b[100];
	switch(j)
	{	
	case'1':
		BT = makingtree();
		system("cls");
		while(1)
		{
			system("cls");
			Menu1();	
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
		makeheaptree();
		while(1)
		{
			system("cls");
			Menu2();	
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
				main_switch2(b[0]);		
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






int main(int argc, char* argv[])
{
	
	Menu_name();
	system("pause");
	system("cls");
	char a[100];

	while(1)
	{
		system("cls");
		cout <<"\n\t\t"<<"请选择以下一个功能:"<<endl;
		cout <<"\n\t\t"<<"1.分类二叉树"<<endl;
		cout <<"\t\t2.堆排序" << endl;
		cout <<"\t\t0.exit"<<endl;
		cout <<"\t\t===============================\n"<<endl;
	
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

