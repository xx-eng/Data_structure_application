// 模拟链表.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "common.h"


void main_switch1(char j);
void Menu() ;
void Menu1();
void main_switch(char j,SimulationChainList &AppList);

void Menu()    //菜单函数
{
	

	cout <<"\n\t\t"<<"请选择以下一个功能:"<<endl;
	cout <<"\n\t\t"<<"1.显示数据元素."<<endl;
	cout <<"\t\t2.插入数据元素." << endl;
	cout <<"\t\t3.删除数据元素." << endl;
    cout <<"\t\t4.查找数据元素."<<endl;
	cout <<"\t\t5.取学号为searchkey的数据元素 "<<endl;
	cout <<"\t\t6.返回"<<endl;
	cout <<"\t\t0.退出.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


}
void Menu1()    //菜单函数
{
	

	cout <<"\n\t\t"<<"请选择以下的两个链表进行操作:"<<endl;
	cout <<"\n\t\t"<<"1.Applist1"<<endl;
	cout <<"\t\t2.Applist2" << endl;
	cout <<"\t\t0.退出.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;

}


void main_switch(char j,SimulationChainList  &AppList)
  //操作选择函数
{
	unsigned searchkey;
	int k;
    ElementType x;
	ElementType result;

    switch(j)
	{
			
			case '1' ://显示线性表中的数据元素
				system("cls");
				//output(L);
				AppList.DisplaySimulationChainList(AppList);
				system("pause");		
				system("cls");
				break;

			case '2' ://插入数据元素
				system("cls");
				AppList.DisplaySimulationChainList(AppList);			
				cout<<"\n\t当前数据元素的下标范围：0---"<<AppList.LengthSimulationChainList()<<endl;
				printf("\n\t请输入要插入点的下标:");				
				scanf("%d",&k);
				fflush(stdin);
				cout<<"插入的学生的学号为：";
				cin>>x.number;
				cout<<"   姓名：";
				cin>>x.name;
				cout<<"   性别：";
				cin>>x.sex;
				cout<<"   年龄：";
				cin>>x.age;
				cout<<endl;

				if(AppList.InsertElementSimulationChainList(k,x))
				{	
					cout<<"插入成功"<<endl;
					AppList.DisplaySimulationChainList(AppList);
				}

				else
					printf("插入失败!\n\n");
				system("pause");		
				system("cls");
				break;				
				
			case '3'://删除数据元素
				system("cls");
				//output(L);
				AppList.DisplaySimulationChainList(AppList);	
				cout<<"\n\t当前数据元素的下标范围：1---"<<AppList.LengthSimulationChainList()<<endl;
				printf("\n\t请输入要删除数据元素的下标:");				
				scanf("%d",&k);
				fflush(stdin);
				
				if(AppList.DeleteElementSimulationChainList(k,result))		
				{
					printf("删除成功!\n\n");
					//output(L);
					AppList.DisplaySimulationChainList(AppList);
				}
				else
					printf("删除失败!\n\n");
				system("pause");
				system("cls");
				break;


				case '4':
				AppList.DisplaySimulationChainList(AppList);
				cout<<"\n\t当前数据元素的下标范围：1---"<<AppList.LengthSimulationChainList()<<endl;
				printf("\n\t请输入查找第几个元素:");				
				scanf("%d",&k);
				cout<<endl;


				fflush(stdin);

				if(AppList.GetElementSimulationChainList(k,result))//返回x所在的数组位置下标
				{					
					printf("查找成功!\n\n");
					AppList.DisplayElementSimulationChainList(result);
					
				}
				else
					printf("\n查找失败!\n\n");			
				system("pause");
				system("cls");
				break;
				
				
				system("pause");
				system("cls");
				break;

			case '5'://查找数据元素
				system("cls");
				//output(L);
				AppList.DisplaySimulationChainList(AppList);	
				printf("\n\t请输入要查找的学生号:");				
				scanf("%d",&searchkey);
				fflush(stdin);
								
				if(AppList.SearchElementSimulationChainList(searchkey,result))//返回x所在的数组位置下标
				{					
					printf("查找成功!\n\n");
					AppList.DisplayElementSimulationChainList(result);
					
				}
				else
					printf("\n查找失败!\n\n");			
				system("pause");
				system("cls");
				break;
			
			case '6':
				system("cls");
				char b[100];
				while(1)
				{
					system("cls");
					Menu1();	
					printf("\n\t请输入功能编号:");
	
					gets(b);	
	
					if(b[1]!='\0')
					{
						cout <<"\n"<<re_choose<<endl;
						system("pause");
						system("cls");
						continue;
				}
				else
				{
					if(b[0]=='0') 
					break;	
				main_switch1(b[0]);		
			
				}

	}
		
		
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



void main_switch1(char j)
  //操作选择函数
{
	//unsigned searchkey;
	//int pos;	

    switch(j)
	{
			
			case '1' :
				system("cls");
				char a[100];
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
						main_switch(a[0],Applist1);		
					}

				}
				system("pause");		
				system("cls");
				break;

			case '2' :
				system("cls");
				char a1[100];
				while(1)
				{
					system("cls");
					Menu();	
					printf("\n\t请输入功能编号:");
	
					gets(a1);	
	
					if(a1[1]!='\0')
						{
							cout <<"\n"<<re_choose<<endl;
							system("pause");
							system("cls");
							continue;
						}
					else
					{
						if(a1[0]=='0') 
						break;	
						main_switch(a1[0],Applist2);		
					}

				}
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
		Menu1();	
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
			main_switch1(a[0]);		
			
		}

	}
	
	return 0;
}

