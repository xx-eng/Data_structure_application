// ģ������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "common.h"


void main_switch1(char j);
void Menu() ;
void Menu1();
void main_switch(char j,SimulationChainList &AppList);

void Menu()    //�˵�����
{
	

	cout <<"\n\t\t"<<"��ѡ������һ������:"<<endl;
	cout <<"\n\t\t"<<"1.��ʾ����Ԫ��."<<endl;
	cout <<"\t\t2.��������Ԫ��." << endl;
	cout <<"\t\t3.ɾ������Ԫ��." << endl;
    cout <<"\t\t4.��������Ԫ��."<<endl;
	cout <<"\t\t5.ȡѧ��Ϊsearchkey������Ԫ�� "<<endl;
	cout <<"\t\t6.����"<<endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


}
void Menu1()    //�˵�����
{
	

	cout <<"\n\t\t"<<"��ѡ�����µ�����������в���:"<<endl;
	cout <<"\n\t\t"<<"1.Applist1"<<endl;
	cout <<"\t\t2.Applist2" << endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;

}


void main_switch(char j,SimulationChainList  &AppList)
  //����ѡ����
{
	unsigned searchkey;
	int k;
    ElementType x;
	ElementType result;

    switch(j)
	{
			
			case '1' ://��ʾ���Ա��е�����Ԫ��
				system("cls");
				//output(L);
				AppList.DisplaySimulationChainList(AppList);
				system("pause");		
				system("cls");
				break;

			case '2' ://��������Ԫ��
				system("cls");
				AppList.DisplaySimulationChainList(AppList);			
				cout<<"\n\t��ǰ����Ԫ�ص��±귶Χ��0---"<<AppList.LengthSimulationChainList()<<endl;
				printf("\n\t������Ҫ�������±�:");				
				scanf("%d",&k);
				fflush(stdin);
				cout<<"�����ѧ����ѧ��Ϊ��";
				cin>>x.number;
				cout<<"   ������";
				cin>>x.name;
				cout<<"   �Ա�";
				cin>>x.sex;
				cout<<"   ���䣺";
				cin>>x.age;
				cout<<endl;

				if(AppList.InsertElementSimulationChainList(k,x))
				{	
					cout<<"����ɹ�"<<endl;
					AppList.DisplaySimulationChainList(AppList);
				}

				else
					printf("����ʧ��!\n\n");
				system("pause");		
				system("cls");
				break;				
				
			case '3'://ɾ������Ԫ��
				system("cls");
				//output(L);
				AppList.DisplaySimulationChainList(AppList);	
				cout<<"\n\t��ǰ����Ԫ�ص��±귶Χ��1---"<<AppList.LengthSimulationChainList()<<endl;
				printf("\n\t������Ҫɾ������Ԫ�ص��±�:");				
				scanf("%d",&k);
				fflush(stdin);
				
				if(AppList.DeleteElementSimulationChainList(k,result))		
				{
					printf("ɾ���ɹ�!\n\n");
					//output(L);
					AppList.DisplaySimulationChainList(AppList);
				}
				else
					printf("ɾ��ʧ��!\n\n");
				system("pause");
				system("cls");
				break;


				case '4':
				AppList.DisplaySimulationChainList(AppList);
				cout<<"\n\t��ǰ����Ԫ�ص��±귶Χ��1---"<<AppList.LengthSimulationChainList()<<endl;
				printf("\n\t��������ҵڼ���Ԫ��:");				
				scanf("%d",&k);
				cout<<endl;


				fflush(stdin);

				if(AppList.GetElementSimulationChainList(k,result))//����x���ڵ�����λ���±�
				{					
					printf("���ҳɹ�!\n\n");
					AppList.DisplayElementSimulationChainList(result);
					
				}
				else
					printf("\n����ʧ��!\n\n");			
				system("pause");
				system("cls");
				break;
				
				
				system("pause");
				system("cls");
				break;

			case '5'://��������Ԫ��
				system("cls");
				//output(L);
				AppList.DisplaySimulationChainList(AppList);	
				printf("\n\t������Ҫ���ҵ�ѧ����:");				
				scanf("%d",&searchkey);
				fflush(stdin);
								
				if(AppList.SearchElementSimulationChainList(searchkey,result))//����x���ڵ�����λ���±�
				{					
					printf("���ҳɹ�!\n\n");
					AppList.DisplayElementSimulationChainList(result);
					
				}
				else
					printf("\n����ʧ��!\n\n");			
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
					printf("\n\t�����빦�ܱ��:");
	
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
  //����ѡ����
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
					printf("\n\t�����빦�ܱ��:");
	
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
					printf("\n\t�����빦�ܱ��:");
	
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
	
	InitWriteRecord(); //Ϊ���������ļ������ԭʼ��¼��ֻ����һ�Ρ�
	ReadRecord();

	while(1)
	{
		system("cls");
		Menu1();	
		printf("\n\t�����빦�ܱ��:");
	
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

