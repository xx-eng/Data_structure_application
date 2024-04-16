// 快速排序.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "APPDATA.h"
#include "QuickSort.h"
#include <string.h>

#define MaxSize 10

STUDENT student[MaxSize];
Sort<ElementType> App;
char re_choose[]={"\n选择非法，请输入正确的编号...\n"};


void Menu_name()
     //作者信息
{   
	printf("\n\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                           学生成绩单的快速排序\n\n");
	printf("                           制作:薛莉\n");
	printf("                           班级:信息1802班\n");
	printf("                           学号: 201821130093\n");
	printf("                           指导老师: 孙夫雄\n");
	printf("              **************************************************\n");
	printf("\n\n\n\t\t");
}

/*struct STUDENT
{
	int 	No;		//学号
	char 	Name[10];//	姓名
	float 	CPMark;//计算机基础
	float 	DSMark;	//数据结构
	float 	PGMark;//程序设计
	float 	Average;//平均成绩
};*/
void Menu()    //菜单函数
{
	

	cout <<"\n\t\t"<<"请选择以下一个功能:"<<endl;
	cout <<"\n\t\t"<<"1.显示数据"<<endl;
	cout <<"\t\t2.对计算机基础成绩排序" << endl;
	cout <<"\t\t3.对数据结构成绩排序" << endl;
    cout <<"\t\t4.对程序设计成绩排序"<<endl;
	cout <<"\t\t5.对平均成绩排序 "<<endl;
	cout <<"\t\t0.退出.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


}

void making(Sort<ElementType> &App)
{
	char name[10][10]={"彭亮","王明","李智","刘丹","肖象"};

	float CPMark[4]={84.0,75.0,90.0,80.0};
	float DSMark[4]={70.0,88.0,84.0,95.0};
	float PGMark[4]={78.0,92.0,66.0,77.0};
	float Average[4]={77.3,85.0,80.0,84.0};
	
	int No[4]={1004,1002,1012,1008};
	
	for(int i=0;i<4;i++)
	{
		strcpy(student[i].Name,name[i]);		
 		student[i].CPMark=CPMark[i];	
		student[i].DSMark=DSMark[i];
		student[i].PGMark=PGMark[i];
		student[i].Average=Average[i];
		student[i].No=No[i];

	}
	for(i=0;i<4;i++)
	{
		App.InsertElementSort(student[i]);
	}
}


void main_switch(char j)
{
	switch(j)
	{
	case'1':
		App.DisplaySort();
		system("pause");
		system("cls");
		break;
	case'2':
		App.QuickSort(j);
		App.DisplaySort();
		system("pause");
		system("cls");
		break;
	case'3':
		App.QuickSort(j);
		App.DisplaySort();
		system("pause");
		system("cls");
		break;
	case'4':
		App.QuickSort(j);
		App.DisplaySort();
		system("pause");
		system("cls");
		break;
	case'5':
		App.QuickSort(j);
		App.DisplaySort();
		system("pause");
		system("cls");
		break;
	case '0': 
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
	char a[100];
	Menu_name();
	system("pause");
	system("cls");
	making(App);
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

