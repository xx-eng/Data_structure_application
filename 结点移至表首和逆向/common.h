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

char re_choose[]={"\nѡ��Ƿ�����������ȷ�ı��...\n"};

STUDENT student[4];
SimpleChainList<HeadType,ElementType>  Applist;

void Menu_name()
     //������Ϣ
{   
	printf("\n\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                           ѧ���ɼ��������Ա�˳��洢\n\n");
	printf("                           ����:Ѧ��\n");
	printf("                           �༶:��Ϣ1802��\n");
	printf("                           ѧ��: 201821130093\n");
	printf("                           ָ����ʦ: �����\n");
	printf("              **************************************************\n");
	printf("\n\n\n\t\t");
}

void SavetoFile()
{
	FILE *f;
	int numwrite;
	ElementType		result;
	f=fopen("ѧ���ɼ���.dat","w+");
	if(f==NULL)
	{
		printf("�ļ���ʧ��!");
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
	char  name[10][20]={"����","����","����","����"};
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

	f=fopen("ѧ��ѧ����.dat","w+");
	if(f==NULL)
	{
		printf("�ļ���ʧ��!");
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
	f=fopen("ѧ��ѧ����.dat","r+");
	if(f==NULL)
	{
		printf("�ļ���ʧ��!");
		return;
	}	
	int i=0;
	
	while(fread(&newvalue, sizeof(newvalue),1,f))
	{
		Applist.InsertElementSimpleChainList(0, newvalue);
	}
	
	fclose(f);
}