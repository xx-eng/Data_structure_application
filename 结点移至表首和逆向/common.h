#include <stdio.h>
//#include <iomanip.h>
#include <conio.h>
#include <stdlib.h>

#include "simplechainlist.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>


using namespace std;

#define  TRUE   1
#define  FALSE  0
#define  OK     1
#define  ERROR  0

typedef  bool  Status;
typedef STUDENT EType;

char re_choose[]={"\n选择非法，请输入正确的编号...\n"};

STUDENT student[4];
SimpleChainList<HeadType,ElementType>  Applist;

void Menu_name()
     //作者信息
{   
	printf("\n\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                           学生成绩单的线性表顺序存储\n\n");
	printf("                           制作:薛莉\n");
	printf("                           班级:信息1802班\n");
	printf("                           学号: 201821130093\n");
	printf("                           指导老师: 孙夫雄\n");
	printf("              **************************************************\n");
	printf("\n\n\n\t\t");
}

void SavetoFile()
{
	FILE *f;
	int numwrite;
	ElementType		result;
	f=fopen("学生成绩表.dat","w+");
	if(f==NULL)
	{
		printf("文件打开失败!");
		return;
	}	
	 //for (int i=0;i<L.length;i++)
	for (int i = 1; i <= Applist.LengthSimpleChainList(); i++)
	 {
		Applist.GetElementSimpleChainList(i, result);
		
		numwrite=fwrite(&result, sizeof(STUDENT),1,f);
	 }
	 fclose(f);
}

void InitWriteRecord()
{
	char  number[4][8]={"1001","1002","1003","1004"};
	char  name[10][20]={"彭亮","王明","李智","刘丹"};
	char  sex[4][3]={"m","m","m","f"};
	int age[4]={18,19,19,20};


	
	for(int i=0;i<4;i++)
	{
		strcpy(student[i].number,number[i]);		
 		strcpy(student[i].name,name[i]);
		strcpy(student[i].sex,sex[i]);
		student[i].age = age[i];

	}
	FILE *f;
	int numwrite;

	f=fopen("学生学籍表.dat","w+");
	if(f==NULL)
	{
		printf("文件打开失败!");
		return;
	}	
	 for (i=0;i<4;i++)
		numwrite=fwrite(&student[i], sizeof(STUDENT),1,f);
	 fclose(f);
}

void ReadRecord()
{
	ElementType newvalue;

	FILE *f;
	f=fopen("学生学籍表.dat","r+");
	if(f==NULL)
	{
		printf("文件打开失败!");
		return;
	}	
	int i=0;
	
	while(fread(&newvalue, sizeof(newvalue),1,f))
	{
		Applist.InsertElementSimpleChainList(0, newvalue);
	}
	
	fclose(f);
}