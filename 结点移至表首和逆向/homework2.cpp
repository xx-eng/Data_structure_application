// homework2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "common.h"

void main_switch(char j)
  //����ѡ����
{
	unsigned k,searchkey;
	int pos;	//Ϊʲôpos���ܶ���Ϊ unsigned 
    EType x;
    switch(j)
	{
			
			case '1' ://��ʾ���Ա��е�����Ԫ��
				system("cls");
				//output(L);
				Applist.DisplaySimpleChainList(Applist);
				system("pause");		
				system("cls");
				break;

			case '2' ://���������������
				system("cls");
				cout<<"\n\t��ǰ����Ԫ�ص��±귶Χ��0---"<<Applist.LengthSimpleChainList()<<endl;
				printf("\n\t������Ҫ�ƶ�����±�:");				
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
					printf("�ƶ��ɹ�!\n\n");
					//output(L);
					Applist.DisplaySimpleChainList(Applist);	
					SavetoFile();
				}
				else
					printf("�ƶ�ʧ��!\n\n");
				system("pause");		
				system("cls");
				break;				
				
		case '3'://����������
				system("cls");
				//output(L);
				Applist.DisplaySimpleChainList(Applist);
				Applist.InvertSimpleChainList();	
				Applist.DisplaySimpleChainList(Applist);
				SavetoFile();
			
				system("pause");
				system("cls");
				break;

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
	cout <<"\t\t2.���������ͷ�����㡣" << endl;
	cout <<"\t\t3.�������������" << endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


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
		cout<<"���ϲƾ�������ѧ��ϢѧԺ��XXX������"<<endl;
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

