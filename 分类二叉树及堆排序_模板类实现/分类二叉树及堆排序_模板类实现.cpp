// �����������������_ģ����ʵ��.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "common.h"

void main_switch(char j)
{
	char b[100];
	makeheaptree();
	BTroot = makingtree(AppBT);
	switch(j)
	{	
	case'1':
		
		system("cls");
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
		break;
		
	case'2':
		
		while(1)
		{
			system("cls");
			Menu2();	
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
				main_switch2(b[0]);		
			}
		}
		break;


	case'0':
		exit(0);
		break;
	default  :
		cout <<re_choose<<endl;
		system("pause");
		system("cls");
		break;
	}
}



int main(int argc, char* argv[])
{
	char a[100];

	while(1)
	{
		system("cls");
		cout <<"\n\t\t"<<"��ѡ������һ������:"<<endl;
		cout <<"\n\t\t"<<"1.���������"<<endl;
		cout <<"\t\t2.������" << endl;
		cout <<"\t\t0.exit"<<endl;
		cout <<"\t\t===============================\n"<<endl;
	
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

