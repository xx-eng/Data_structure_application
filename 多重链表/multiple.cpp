// multiple.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "common.h"

void main_switch(char j)
  //����ѡ����
{
	//unsigned k,searchkey;
	//int pos;	//Ϊʲôpos���ܶ���Ϊ unsigned 
    //Etype x;

	char n[10];
	char s,par,car;
	//MultipleChainNode<ElementType>  *result1;

    switch(j)
	{
			
			case '1' ://��ʾ���Ա��е�����Ԫ��
				system("cls");
				//output(L);
				Applist.DisplayMultipleChainList(Applist);
				system("pause");		
				system("cls");
				break;

			case '2' ://������
				system("cls");
				cout<<"����Ҫ�����˵�����,δ֪������0 : ";
				cin>>n;
				cout<<"\n����Ҫ�����˵��Ա�,��Ϊm��ŮΪf,δ֪������0��";
				cin>>s;
				cout<<"\n����Ҫ�����˵ĵ���,������Ϊc��������Ϊd,�޵���Ϊn,δ֪������0��";
				cin>>par;
				cout<<"\n����Ҫ�����˵�ְ��,����Ϊp��������Ϊa,��ʦΪl,����Ϊt,�̸�Ϊs��δ֪������0��";
				cin>>car;
				cout<<"���ҽ�����£�"<<endl;
				fflush(stdin);
				

				if(Applist.SearchElement(n,s,par,car))	
				{
					printf("���ҳɹ�!\n\n");

				}
				else
					printf("���޴���!\n\n");
				system("pause");		
				system("cls");
				break;				
				
	/*	case '3'://����������
				system("cls");
				//output(L);
				Applist.DisplaySimpleChainList(Applist);
				Applist.InvertSimpleChainList();	
				Applist.DisplaySimpleChainList(Applist);
				SavetoFile();
			
				system("pause");
				system("cls");
				break;*/

		/*	case '4'://��������Ԫ��
				system("cls");
				//output(L);
				AppList.DisplayLinearList(AppList);	
				printf("\n\t������Ҫ���ҵ�ѧ����:");				
				scanf("%d",&searchkey);
				fflush(stdin);
				k = AppList.SearchElementLinearList(searchkey);				
				if(k != -1)//����x���ڵ�����λ���±�
				{
					printf("���ҳɹ�!\n\n");
					AppList.GetElementLinearList(k + 1, result);
				}
				else
					printf("\n����ʧ��!\n\n");			
				system("pause");
				system("cls");
				break;

			case '5'://ȡ���е�k��Ԫ��
				AppList.DisplayLinearList(AppList);
				cout<<"\n\t��ǰ����Ԫ�ص��±귶Χ��1---"<<AppList.LengthLinearList()<<endl;
				printf("\n\t������Ҫȡ������Ԫ�ص����:");				
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
					printf("��ȡ�ɹ�!\n\n");
					AppList.DisplayElementLinearList(result);
				}
				else
					printf("\nȡ��ʧ��!\n\n");
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

void Menu()    //�˵�����
{
	

	cout <<"\n\t\t"<<"��ѡ������һ������:"<<endl;
	cout <<"\n\t\t"<<"1.��ʾ���Ա��е�����Ԫ��."<<endl;
	cout <<"\t\t2.��������Ԫ��" << endl;
	//cout <<"\t\t3.�������������" << endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
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
	
	InitWriteRecord(); //Ϊ���������ļ������ԭʼ��¼��ֻ����һ�Ρ�
	ReadRecord();

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
			main_switch(a[0]);		
		}

	}


	return 0;
}

