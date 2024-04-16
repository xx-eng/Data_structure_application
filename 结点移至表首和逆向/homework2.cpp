// homework2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "common.h"

void main_switch(char j)
  //操作选择函数
{
	unsigned k,searchkey;
	int pos;	//为什么pos不能定义为 unsigned 
    EType x;
    switch(j)
	{
			
			case '1' ://显示线性表中的数据元素
				system("cls");
				//output(L);
				Applist.DisplaySimpleChainList(Applist);
				system("pause");		
				system("cls");
				break;

			case '2' ://结点移至表首运算
				system("cls");
				cout<<"\n\t当前数据元素的下标范围：0---"<<Applist.LengthSimpleChainList()<<endl;
				printf("\n\t请输入要移动点的下标:");				
				scanf("%d",&k);
				fflush(stdin);
				if (k < 0 || k > Applist.LengthSimpleChainList())
				{
					cout <<"\n"<<re_choose<<endl;
					system("pause");
					system("cls");
					break;
				}
				Applist.MovelElementFirstSimpleChainList(k);	
				if(Applist.MovelElementFirstSimpleChainList(k))	
				{
					printf("移动成功!\n\n");
					//output(L);
					Applist.DisplaySimpleChainList(Applist);	
					SavetoFile();
				}
				else
					printf("移动失败!\n\n");
				system("pause");		
				system("cls");
				break;				
				
		case '3'://链表逆运算
				system("cls");
				//output(L);
				Applist.DisplaySimpleChainList(Applist);
				Applist.InvertSimpleChainList();	
				Applist.DisplaySimpleChainList(Applist);
				SavetoFile();
			
				system("pause");
				system("cls");
				break;

		/*	case '4'://查找数据元素
				system("cls");
				//output(L);
				AppList.DisplayLinearList(AppList);	
				printf("\n\t请输入要查找的学生号:");				
				scanf("%d",&searchkey);
				fflush(stdin);
				k = AppList.SearchElementLinearList(searchkey);				
				if(k != -1)//返回x所在的数组位置下标
				{
					printf("查找成功!\n\n");
					AppList.GetElementLinearList(k + 1, result);
				}
				else
					printf("\n查找失败!\n\n");			
				system("pause");
				system("cls");
				break;

			case '5'://取序列第k个元素
				AppList.DisplayLinearList(AppList);
				cout<<"\n\t当前数据元素的下标范围：1---"<<AppList.LengthLinearList()<<endl;
				printf("\n\t请输入要取出数据元素的序号:");				
				scanf("%d",&k);
				fflush(stdin);
				if (k < 1 || k > AppList.LengthLinearList())
				{
					cout <<"\n"<<re_choose<<endl;
					system("pause");
					system("cls");
					break;
				}
				if(AppList.GetElementLinearList(k + 1, result))
				{
					printf("获取成功!\n\n");
					AppList.DisplayElementLinearList(result);
				}
				else
					printf("\n取出失败!\n\n");
				system("pause");
				system("cls");
				break;*/
		
		
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

void Menu()    //菜单函数
{
	

	cout <<"\n\t\t"<<"请选择以下一个功能:"<<endl;
	cout <<"\n\t\t"<<"1.显示线性表中的数据元素."<<endl;
	cout <<"\t\t2.结点移至表头的运算。" << endl;
	cout <<"\t\t3.链表的逆向运算" << endl;
	cout <<"\t\t0.退出.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


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


int main(int argc, char* argv[])
{
	char j;

	char a[100];

	if(Code_Verify())
		return 0;
	Cover();

    system("cls");

	Menu_name();
	system("pause");
	system("cls");
	
	InitWriteRecord(); //为建立数据文件并添加原始记录，只运行一次。
	ReadRecord();

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

