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

char re_choose[]={"\n选择非法，请输入正确的编号...\n"};

MEMBER member[5];
MultipleChainList<ElementType>    Applist;

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


void SavetoFile()
{
	FILE *f;
	int numwrite;
	ElementType		result;
	f=fopen("信息表.dat","w+");
	if(f==NULL)
	{
		printf("文件打开失败!");
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
	char  name[5][10]={"黄强","李永","周明","张玉","赵志"};
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

	f=fopen("信息表.dat","w+");
	if(f==NULL)
	{
		printf("文件打开失败!");
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
	f=fopen("信息表.dat","r+");
	if(f==NULL)
	{
		printf("文件打开失败!");
		return;
	}	
	int i=0;
	
	while(fread(&newvalue, sizeof(newvalue),1,f))
	{
		Applist.InsertElement(newvalue);
	}
	
	fclose(f);
}

