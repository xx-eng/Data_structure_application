#include "multiplechainlist.h"
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
typedef  MEMBER  Etype;

char re_choose[]={"\nѡ��Ƿ�����������ȷ�ı��...\n"};

MEMBER member[5];
MultipleChainList<ElementType>    Applist;

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


void SavetoFile()
{
	FILE *f;
	int numwrite;
	ElementType		result;
	f=fopen("��Ϣ��.dat","w+");
	if(f==NULL)
	{
		printf("�ļ���ʧ��!");
		return;
	}	
	 //for (int i=0;i<L.length;i++)
	for (int i = 1; i <= Applist.LengthNameList(); i++)
	 {
		Applist.GetElementMultipleChainList(i, result);
		
		numwrite=fwrite(&result, sizeof(MEMBER),1,f);
	 }
	 fclose(f);
}


void InitWriteRecord()
{
	char  name[5][10]={"��ǿ","����","����","����","��־"};
	char  sex[5]={'m' , 'm' , 'm' , 'f' , 'f'};
	char  party[5]={'d' , 'n' , 'd' , 'c' , 'c'};
	char  career[5]={'p' , 'l' , 'l' , 'a' , 's'};


	
	for(int i=0;i<5;i++)
	{
		strcpy(member[i].name,name[i]);		
 		member[i].sex = sex[i];
		member[i].party = party[i];
		member[i].career = career[i];

	}
	FILE *f;
	int numwrite;

	f=fopen("��Ϣ��.dat","w+");
	if(f==NULL)
	{
		printf("�ļ���ʧ��!");
		return;
	}	
	 for (i=0;i<5;i++)
		numwrite=fwrite(&member[i], sizeof(MEMBER),1,f);
	 fclose(f);
}

void ReadRecord()
{
	ElementType newvalue;

	FILE *f;
	f=fopen("��Ϣ��.dat","r+");
	if(f==NULL)
	{
		printf("�ļ���ʧ��!");
		return;
	}	
	int i=0;
	
	while(fread(&newvalue, sizeof(newvalue),1,f))
	{
		Applist.InsertElement(newvalue);
	}
	
	fclose(f);
}

