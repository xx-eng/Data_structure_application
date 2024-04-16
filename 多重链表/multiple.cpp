// multiple.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "common.h"

void main_switch(char j)
  //操作选择函数
{
	//unsigned k,searchkey;
	//int pos;	//为什么pos不能定义为 unsigned 
    //Etype x;

	char n[10];
	char s,par,car;
	//MultipleChainNode<ElementType>  *result1;

    switch(j)
	{
			
			case '1' ://显示线性表中的数据元素
				system("cls");
				//output(L);
				Applist.DisplayMultipleChainList(Applist);
				system("pause");		
				system("cls");
				break;

			case '2' ://查找人
				system("cls");
				cout<<"输入要查找人的姓名,未知请输入0 : ";
				cin>>n;
				cout<<"\n输入要查找人的性别,男为m，女为f,未知请输入0：";
				cin>>s;
				cout<<"\n输入要查找人的党派,共产党为c，民主党为d,无党派为n,未知请输入0：";
				cin>>par;
				cout<<"\n输入要查找人的职称,教授为p，副教授为a,讲师为l,助教为t,教辅为s，未知请输入0：";
				cin>>car;
				cout<<"查找结果如下："<<endl;
				fflush(stdin);
				

				if(Applist.SearchElement(n,s,par,car))	
				{
					printf("查找成功!\n\n");

				}
				else
					printf("查无此人!\n\n");
				system("pause");		
				system("cls");
				break;				
				
	/*	case '3'://链表逆运算
				system("cls");
				//output(L);
				Applist.DisplaySimpleChainList(Applist);
				Applist.InvertSimpleChainList();	
				Applist.DisplaySimpleChainList(Applist);
				SavetoFile();
			
				system("pause");
				system("cls");
				break;*/

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
	cout <<"\t\t2.查找数据元素" << endl;
	//cout <<"\t\t3.链表的逆向运算" << endl;
	cout <<"\t\t0.退出.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


}


int main(int argc, char* argv[])
{
//	char j;

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

