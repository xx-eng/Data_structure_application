

#include "simplechainlist.h"
#include <stdio.h>
//#include <iomanip.h>
#include <conio.h>
#include <stdlib.h>
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
typedef  STUDENT  Etype;

char re_choose[]={"\nѡ��Ƿ�����������ȷ�ı��...\n"};

STUDENT student1[4];
STUDENT student2[4];
SimulationChainList   Applist1;
SimulationChainList    Applist2;

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

//-------������봰�ں���----------
int Code_Verify()
{
	char b[10];	
	char c[10]="ygnmf";//�Ѿ����м򵥼���
	char a;	   	
	int i=0,j,k=1,x;
	while(1)
	{
		system("cls");
		//cout<<"\n\n\n\n\n\n\n\n\n\t\t\t������ϵͳ����:";
		printf("\n\n\n\n\n\n\n\n\n\t\t\t������ϵͳ����:");
		for(j=0;j<i;j++)
			//cout<<"��";
			printf("��");
	//	cout<<endl;
		printf("\n");
		a=getch();

		//if(int(a)!=8||int(a)!=13)//�����ڻس����˸��
		if(a!=8||a!=13)//�����ڻس����˸��
			b[i]=a-1;

		if(int(a)==8)
		{
			i-=2;
			system("cls");
		//	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t������ϵͳ����:";
			printf("\n\n\n\n\n\n\n\n\n\t\t\t������ϵͳ����:");
			for(j=0;j<i;j++)
			//	cout<<"��";
			printf("��");
		//	cout<<endl;
			printf("\n");
		}
		if(int(a)==13)
		{
			b[i]='\0';
			if(strcmp(c,b)==0)
				return 0;
			else
			{
				if(k==3)
				{
					while (!kbhit()) 
					{
						system("cls");
						for(x=0;x<100000000;x++);
					cout<<"\n\n\n\n\n\n\n\n\t\t  ����Ȩʹ�ñ�ϵͳ��������˳�ϵͳ..."<<endl;
					for(x=0;x<100000000;x++);}
					return 1;
				}
				cout<<"\n\t\t   ��������㻹��"<<3-k<<"�λ���.����������."<<endl;
				k++;
				getch();
			}
			i=-1;
		}
		i++;
	}
}
//-------�������溯��----------
void Cover()	
{	
	char line[]={"��������������������"};
	char bar[]={"...."};
	int i,j,k=0,x=0,y=0;	
	for(i=1;i<=strlen(line)/2;)
	{
		system("cls");
		for(j=0;j<9;j++)   //�ı�������
			cout<<endl;
		for(j=0;j<(75-strlen(line))/2;j++)  //�ı�������
			cout<<" ";
		for(j=1;j<=i;j++)			//������ʾ��
			cout<<"��";
		for(x=strlen(line)/2;x>i;x--)
			cout<<"��";
		if(k==4)
			i++;
		cout<<endl;	
		for(j=0;j<(75-strlen(line))/2;j++)	//�����궨λ
			cout<<" ";
		cout<<line;			//�������
		cout<<endl;
		for(j=0;j<(65-strlen(bar))/2;j++)
			cout<<" ";
		cout<<(i-1)*10<<"%  Loading";
		cout.write(bar,k);
		cout<<endl;
		for(j=0;j<10;j++)
			cout<<endl;
		for(j=0;j<24;j++)
			cout<<" ";
		cout<<"���ϲƾ�������ѧ��ϢѧԺ��Ѧ������"<<endl;
		for(j=0;j<24;j++)
			cout<<" ";
		for(j=0;j<=12;j++)
			cout<<"��";
		cout<<endl;
		for(j=0;j<10000000;j++);//��ʱЧ��
		k++;
		if(k>4)
			k=0;
	}
}

void InitWriteRecord()
{
	char  name[4][10]={"��ǿ","����","����","����"};
	char  sex[4][10]={"man" , "man", "man" , "female" };
	int   num[4]={1001,1002,1003,1004};
	int   age[4]={18,19,18,19};

	char  name1[4][10]={"Ф��","����","����","��־"};
	char  sex1[4][10]={"man" , "man" , "female" , "female" };
	int   num1[4]={1007,1008,1009,1010};
	int   age1[4]={18,18,18,19};


	
	for(int j=0;j<4;j++)
	{
		strcpy(student1[j].name,name[j]);		
 		strcpy(student1[j].sex,sex[j]);
		student1[j].number = num[j];
		student1[j].age = age[j];
	}

	for(j=0;j<4;j++)
	{
		strcpy(student2[j].name,name1[j]);		
 		strcpy(student2[j].sex,sex1[j]);
		student2[j].number = num1[j];
		student2[j].age = age1[j];
	}


	FILE *f;
	int numwrite;

	f=fopen("һ����Ϣ��.dat","w+");
	if(f==NULL)
	{
		printf("�ļ���ʧ��!");
		return;
	}	
	 for (int i=0;i<4;i++)
		numwrite=fwrite(&student1[i], sizeof(STUDENT),1,f);
	 fclose(f); 

	 FILE *f1;
	 int numwrite1;

	 f1 = fopen("������Ϣ��.dat","w+");
	 if(f1 == NULL)
	 {
		printf("�ļ���ʧ��!");
		return;
	 }
	 for (i=0;i<4;i++)
		numwrite1=fwrite(&student2[i], sizeof(STUDENT),1,f1);
	 fclose(f1); 
}

void ReadRecord()
{
	ElementType newvalue;

	FILE *f;
	f=fopen("һ����Ϣ��.dat","r+");
	if(f==NULL)
	{
		printf("�ļ���ʧ��!");
		return;
	}	
	int i=0;
	
	while(fread(&newvalue, sizeof(newvalue),1,f))
	{
		Applist1.InsertElementSimulationChainList(0,newvalue);
	}
	
	fclose(f);

	FILE *f1;
	f1=fopen("������Ϣ��.dat","r+");
	if(f1==NULL)
	{
		printf("�ļ���ʧ��!");
		return;
	}	
	i=0;
	
	while(fread(&newvalue, sizeof(newvalue),1,f1))
	{
		Applist2.InsertElementSimulationChainList(0,newvalue);
	}
	
	fclose(f1);
}

