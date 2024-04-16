

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

char re_choose[]={"\n选择非法，请输入正确的编号...\n"};

STUDENT student1[4];
STUDENT student2[4];
SimulationChainList   Applist1;
SimulationChainList    Applist2;

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

//-------密码登入窗口函数----------
int Code_Verify()
{
	char b[10];	
	char c[10]="ygnmf";//已经进行简单加密
	char a;	   	
	int i=0,j,k=1,x;
	while(1)
	{
		system("cls");
		//cout<<"\n\n\n\n\n\n\n\n\n\t\t\t请输入系统密码:";
		printf("\n\n\n\n\n\n\n\n\n\t\t\t请输入系统密码:");
		for(j=0;j<i;j++)
			//cout<<"●";
			printf("●");
	//	cout<<endl;
		printf("\n");
		a=getch();

		//if(int(a)!=8||int(a)!=13)//不等于回车或退格键
		if(a!=8||a!=13)//不等于回车或退格键
			b[i]=a-1;

		if(int(a)==8)
		{
			i-=2;
			system("cls");
		//	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t请输入系统密码:";
			printf("\n\n\n\n\n\n\n\n\n\t\t\t请输入系统密码:");
			for(j=0;j<i;j++)
			//	cout<<"●";
			printf("●");
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
					cout<<"\n\n\n\n\n\n\n\n\t\t  你无权使用本系统，任意键退出系统..."<<endl;
					for(x=0;x<100000000;x++);}
					return 1;
				}
				cout<<"\n\t\t   密码错误，你还有"<<3-k<<"次机会.请重新输入."<<endl;
				k++;
				getch();
			}
			i=-1;
		}
		i++;
	}
}
//-------启动画面函数----------
void Cover()	
{	
	char line[]={"━━━━━━━━━━"};
	char bar[]={"...."};
	int i,j,k=0,x=0,y=0;	
	for(i=1;i<=strlen(line)/2;)
	{
		system("cls");
		for(j=0;j<9;j++)   //改变行坐标
			cout<<endl;
		for(j=0;j<(75-strlen(line))/2;j++)  //改变列坐标
			cout<<" ";
		for(j=1;j<=i;j++)			//进度显示器
			cout<<"■";
		for(x=strlen(line)/2;x>i;x--)
			cout<<"□";
		if(k==4)
			i++;
		cout<<endl;	
		for(j=0;j<(75-strlen(line))/2;j++)	//行坐标定位
			cout<<" ";
		cout<<line;			//输出线条
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
		cout<<"中南财经政法大学信息学院：薛莉·制作"<<endl;
		for(j=0;j<24;j++)
			cout<<" ";
		for(j=0;j<=12;j++)
			cout<<"─";
		cout<<endl;
		for(j=0;j<10000000;j++);//延时效果
		k++;
		if(k>4)
			k=0;
	}
}

void InitWriteRecord()
{
	char  name[4][10]={"黄强","李永","周明","张玉"};
	char  sex[4][10]={"man" , "man", "man" , "female" };
	int   num[4]={1001,1002,1003,1004};
	int   age[4]={18,19,18,19};

	char  name1[4][10]={"肖象","李明","刘辉","赵志"};
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

	f=fopen("一班信息表.dat","w+");
	if(f==NULL)
	{
		printf("文件打开失败!");
		return;
	}	
	 for (int i=0;i<4;i++)
		numwrite=fwrite(&student1[i], sizeof(STUDENT),1,f);
	 fclose(f); 

	 FILE *f1;
	 int numwrite1;

	 f1 = fopen("二班信息表.dat","w+");
	 if(f1 == NULL)
	 {
		printf("文件打开失败!");
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
	f=fopen("一班信息表.dat","r+");
	if(f==NULL)
	{
		printf("文件打开失败!");
		return;
	}	
	int i=0;
	
	while(fread(&newvalue, sizeof(newvalue),1,f))
	{
		Applist1.InsertElementSimulationChainList(0,newvalue);
	}
	
	fclose(f);

	FILE *f1;
	f1=fopen("二班信息表.dat","r+");
	if(f1==NULL)
	{
		printf("文件打开失败!");
		return;
	}	
	i=0;
	
	while(fread(&newvalue, sizeof(newvalue),1,f1))
	{
		Applist2.InsertElementSimulationChainList(0,newvalue);
	}
	
	fclose(f1);
}

