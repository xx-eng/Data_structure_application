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

char re_choose[]={"\nѡ��Ƿ�����������ȷ�ı��...\n"};

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


void Menu()    //�˵�����
{
	

	cout <<"\n\t\t"<<"��ѡ������һ������:"<<endl;
	cout <<"\n\t\t"<<"1.��ʾ���Ա��е�����Ԫ��."<<endl;
	cout <<"\t\t2.��������Ԫ��." << endl;
	cout <<"\t\t3.ɾ������Ԫ��." << endl;
    cout <<"\t\t4.��������Ԫ��."<<endl;
	cout <<"\t\t5.ȡѧ��Ϊx��Ԫ�ص�ǰi���ͺ�j��Ԫ�� "<<endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


}


void main_switch(char j,DoubleChainList<HeadType,ElementType>  &AppList)
  //����ѡ����
{
	unsigned searchkey;
	int pos,k;	//Ϊʲôpos���ܶ���Ϊ unsigned 
    ElementType x;
	DoubleChainNode<ElementType>   *pt;
	int searchkey1;
	int xx,yy;

    switch(j)
	{
			
			case '1' ://��ʾ���Ա��е�����Ԫ��
				system("cls");
				//output(L);
				AppList.DisplayDoubleChainList(AppList);
				system("pause");		
				system("cls");
				break;

			case '2' ://��������Ԫ��
				system("cls");
				AppList.DisplayDoubleChainList(AppList);			
				cout<<"\n\t��ǰ����Ԫ�ص��±귶Χ��0---"<<AppList.LengthDoubleChainList()<<endl;
				printf("\n\t������Ҫ�������±�:");				
				scanf("%d",&k);
				fflush(stdin);
				cout<<"�����ѧ����ѧ��Ϊ��";
				cin>>x.num;
				cout<<"   ������";
				cin>>x.name;
				cout<<endl;

				if(AppList.InsertElementDoubleChainList(k,x))
					cout<<"����ɹ�"<<endl;
				else
					printf("����ʧ��!\n\n");
				system("pause");		
				system("cls");
				break;				
				
			case '3'://ɾ������Ԫ��
				system("cls");
				//output(L);
				AppList.DisplayDoubleChainList(AppList);	
				cout<<"\n\t��ǰ����Ԫ�ص��±귶Χ��1---"<<AppList.LengthDoubleChainList()<<endl;
				printf("\n\t������Ҫɾ������Ԫ�ص��±�:");				
				scanf("%d",&k);
				fflush(stdin);
				
				if(AppList.DeleteElementDoubleChainList(k))		
				{
					printf("ɾ���ɹ�!\n\n");
					//output(L);
					AppList.DisplayDoubleChainList(AppList);
				}
				else
					printf("ɾ��ʧ��!\n\n");
				system("pause");
				system("cls");
				break;

			case '4'://��������Ԫ��
				system("cls");
				//output(L);
				AppList.DisplayDoubleChainList(AppList);	
				printf("\n\t������Ҫ���ҵ�ѧ����:");				
				scanf("%d",&searchkey);
				fflush(stdin);
				pt = AppList.GetElementDoubleChainList(searchkey);				
				if(pt)//����x���ڵ�����λ���±�
				{
					ElementType ele = pt->data;
					
					printf("���ҳɹ�!\n\n");
					AppList.DisplayDoubleChainNode(ele);
					
				}
				else
					printf("\n����ʧ��!\n\n");			
				system("pause");
				system("cls");
				break;

			case '5':
			//����ĳһѧ��x����ͬʱ�ҵ���ѧ����i��ǰ����ѧ����Ϣ���Լ���ѧ����j����̵�ѧ����Ϣ
				AppList.DisplayDoubleChainList(AppList);
				cout<<"\n\t��ǰ����Ԫ�ص��±귶Χ��1---"<<AppList.LengthDoubleChainList()<<endl;
				printf("\n\t������ѧ����ѧ��:");				
				scanf("%d",&searchkey1);
				cout<<"\n\tҪ�Ҹ�Ԫ�ص�ǰ";
				cin>>xx;
				cout<<"��Ԫ��";
				cout<<"\n\tҪ�Ҹ�Ԫ�صĺ�";
				cin>>yy;
				cout<<"��Ԫ��";
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
	HeadType		ClassInformation = {40,"�Ź�1111"};


	//A-------���������
	DoubleChainList<HeadType,ElementType>  AppList;

	HeadPtr=AppList.GetHeadPtrDoubleChainList();
	AppList.PutValueDoubleChainHeadNode(ClassInformation);//��ͷ���������ֵ

	cout<<"�����ĸ�ѧ����ѧ�ż�������"<<endl;


	for(int i=0;i<4;i++)
	{
		cout<<"��"<<i+1<<"��ѧ��:"<<"  ѧ��:";
		cin>>app[i].num;
		cout<<"    ����:";
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
			main_switch(a[0],AppList);		
			
		}

	}

	return 0;
}

