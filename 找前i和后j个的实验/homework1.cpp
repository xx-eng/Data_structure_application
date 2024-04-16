// homework1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <conio.h>

using namespace std;

#include "doublechainlist.h"

char re_choose[]={"\n选择非法，请输入正确的编号...\n"};

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
		cout<<"中南财经政法大学信息学院：XXX·制作"<<endl;
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


void Menu_name()
     //作者信息
{   
	printf("\n\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                           学生成绩单的线性表顺序存储\n\n");
	printf("                           制作:薛利\n");
	printf("                           班级:信息1802班\n");
	printf("                           学号: 201821130093\n");
	printf("                           指导老师: 孙夫雄\n");
	printf("              **************************************************\n");
	printf("\n\n\n\t\t");
}


void Menu()    //菜单函数
{
	

	cout <<"\n\t\t"<<"请选择以下一个功能:"<<endl;
	cout <<"\n\t\t"<<"1.显示线性表中的数据元素."<<endl;
	cout <<"\t\t2.插入数据元素." << endl;
	cout <<"\t\t3.删除数据元素." << endl;
    cout <<"\t\t4.查找数据元素."<<endl;
	cout <<"\t\t5.取学号为x的元素的前i个和后j个元素 "<<endl;
	cout <<"\t\t0.退出.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


}


void main_switch(char j,DoubleChainList<HeadType,ElementType>  &AppList)
  //操作选择函数
{
	unsigned searchkey;
	int pos,k;	//为什么pos不能定义为 unsigned 
    ElementType x;
	DoubleChainNode<ElementType>   *pt;
	int searchkey1;
	int xx,yy;

    switch(j)
	{
			
			case '1' ://显示线性表中的数据元素
				system("cls");
				//output(L);
				AppList.DisplayDoubleChainList(AppList);
				system("pause");		
				system("cls");
				break;

			case '2' ://插入数据元素
				system("cls");
				AppList.DisplayDoubleChainList(AppList);			
				cout<<"\n\t当前数据元素的下标范围：0---"<<AppList.LengthDoubleChainList()<<endl;
				printf("\n\t请输入要插入点的下标:");				
				scanf("%d",&k);
				fflush(stdin);
				cout<<"插入的学生的学号为：";
				cin>>x.num;
				cout<<"   姓名：";
				cin>>x.name;
				cout<<endl;

				if(AppList.InsertElementDoubleChainList(k,x))
					cout<<"插入成功"<<endl;
				else
					printf("插入失败!\n\n");
				system("pause");		
				system("cls");
				break;				
				
			case '3'://删除数据元素
				system("cls");
				//output(L);
				AppList.DisplayDoubleChainList(AppList);	
				cout<<"\n\t当前数据元素的下标范围：1---"<<AppList.LengthDoubleChainList()<<endl;
				printf("\n\t请输入要删除数据元素的下标:");				
				scanf("%d",&k);
				fflush(stdin);
				
				if(AppList.DeleteElementDoubleChainList(k))		
				{
					printf("删除成功!\n\n");
					//output(L);
					AppList.DisplayDoubleChainList(AppList);
				}
				else
					printf("删除失败!\n\n");
				system("pause");
				system("cls");
				break;

			case '4'://查找数据元素
				system("cls");
				//output(L);
				AppList.DisplayDoubleChainList(AppList);	
				printf("\n\t请输入要查找的学生号:");				
				scanf("%d",&searchkey);
				fflush(stdin);
				pt = AppList.GetElementDoubleChainList(searchkey);				
				if(pt)//返回x所在的数组位置下标
				{
					ElementType ele = pt->data;
					
					printf("查找成功!\n\n");
					AppList.DisplayDoubleChainNode(ele);
					
				}
				else
					printf("\n查找失败!\n\n");			
				system("pause");
				system("cls");
				break;

			case '5':
			//给定某一学号x，能同时找到该学生第i个前驱的学生信息，以及该学生第j个后继的学生信息
				AppList.DisplayDoubleChainList(AppList);
				cout<<"\n\t当前数据元素的下标范围：1---"<<AppList.LengthDoubleChainList()<<endl;
				printf("\n\t请输入学生的学号:");				
				scanf("%d",&searchkey1);
				cout<<"\n\t要找该元素的前";
				cin>>xx;
				cout<<"个元素";
				cout<<"\n\t要找该元素的后";
				cin>>yy;
				cout<<"个元素";
				cout<<endl;


				fflush(stdin);

				AppList.findbeforeAndAfter(searchkey1,xx,yy);
				
				
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
		
			}//end switch
}




int main(int argc, char* argv[])
{
	char a[100];
	

	if(Code_Verify())
		return 0;
	Cover();

	system("cls");
	Menu_name();
	system("pause");
	system("cls");


	DoubleChainNode<ElementType>	*pl;
	DoubleHeadNode<HeadType>	*HeadPtr;
	ElementType		newvalue,result,app[4];
	HeadType		ClassInformation = {40,"信管1111"};


	//A-------构造简单链表
	DoubleChainList<HeadType,ElementType>  AppList;

	HeadPtr=AppList.GetHeadPtrDoubleChainList();
	AppList.PutValueDoubleChainHeadNode(ClassInformation);//表头结点数据域赋值

	cout<<"输入四个学生的学号及其姓名"<<endl;


	for(int i=0;i<4;i++)
	{
		cout<<"第"<<i+1<<"个学生:"<<"  学号:";
		cin>>app[i].num;
		cout<<"    姓名:";
		cin>>app[i].name;
		cout<<endl;

	}

	for(i=3;i>=0;i--)
	{
		newvalue.num = app[i].num ;
		strcpy(newvalue.name,app[i].name);
		AppList.InsertElementDoubleChainList(0,newvalue);
	}





	while(true)
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
			main_switch(a[0],AppList);		
			
		}

	}

	return 0;
}

