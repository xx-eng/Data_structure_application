// ��������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "APPDATA.h"
#include "QuickSort.h"
#include <string.h>

#define MaxSize 10

STUDENT student[MaxSize];
Sort<ElementType> App;
char re_choose[]={"\nѡ��Ƿ�����������ȷ�ı��...\n"};


void Menu_name()
     //������Ϣ
{   
	printf("\n\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                           ѧ���ɼ����Ŀ�������\n\n");
	printf("                           ����:Ѧ��\n");
	printf("                           �༶:��Ϣ1802��\n");
	printf("                           ѧ��: 201821130093\n");
	printf("                           ָ����ʦ: �����\n");
	printf("              **************************************************\n");
	printf("\n\n\n\t\t");
}

/*struct STUDENT
{
	int 	No;		//ѧ��
	char 	Name[10];//	����
	float 	CPMark;//���������
	float 	DSMark;	//���ݽṹ
	float 	PGMark;//�������
	float 	Average;//ƽ���ɼ�
};*/
void Menu()    //�˵�����
{
	

	cout <<"\n\t\t"<<"��ѡ������һ������:"<<endl;
	cout <<"\n\t\t"<<"1.��ʾ����"<<endl;
	cout <<"\t\t2.�Լ���������ɼ�����" << endl;
	cout <<"\t\t3.�����ݽṹ�ɼ�����" << endl;
    cout <<"\t\t4.�Գ�����Ƴɼ�����"<<endl;
	cout <<"\t\t5.��ƽ���ɼ����� "<<endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


}

void making(Sort<ElementType> &App)
{
	char name[10][10]={"����","����","����","����","Ф��"};

	float CPMark[4]={84.0,75.0,90.0,80.0};
	float DSMark[4]={70.0,88.0,84.0,95.0};
	float PGMark[4]={78.0,92.0,66.0,77.0};
	float Average[4]={77.3,85.0,80.0,84.0};
	
	int No[4]={1004,1002,1012,1008};
	
	for(int i=0;i<4;i++)
	{
		strcpy(student[i].Name,name[i]);		
 		student[i].CPMark=CPMark[i];	
		student[i].DSMark=DSMark[i];
		student[i].PGMark=PGMark[i];
		student[i].Average=Average[i];
		student[i].No=No[i];

	}
	for(i=0;i<4;i++)
	{
		App.InsertElementSort(student[i]);
	}
}


void main_switch(char j)
{
	switch(j)
	{
	case'1':
		App.DisplaySort();
		system("pause");
		system("cls");
		break;
	case'2':
		App.QuickSort(j);
		App.DisplaySort();
		system("pause");
		system("cls");
		break;
	case'3':
		App.QuickSort(j);
		App.DisplaySort();
		system("pause");
		system("cls");
		break;
	case'4':
		App.QuickSort(j);
		App.DisplaySort();
		system("pause");
		system("cls");
		break;
	case'5':
		App.QuickSort(j);
		App.DisplaySort();
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


	}

}

int main(int argc, char* argv[])
{
	char a[100];
	Menu_name();
	system("pause");
	system("cls");
	making(App);
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

