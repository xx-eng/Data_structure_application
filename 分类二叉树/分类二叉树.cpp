// ���������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SortBT.h"
#include <string.h>
#include <stdlib.h>

Student student[10];
ElementType heap[20];
BinaryTreeNode *BT = NULL;
#define  HeapSize 10           //������տ�ʼ��̫������Ĵ�С
char re_choose[]={"\nѡ��Ƿ�����������ȷ�ı��...\n"};

void Menu_name()
     //������Ϣ
{   
	printf("\n\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                           ���������\n\n");
	printf("                           ����:Ѧ��\n");
	printf("                           �༶:��Ϣ1802��\n");
	printf("                           ѧ��: 201821130093\n");
	printf("                           ָ����ʦ: �����\n");
	printf("              **************************************************\n");
	printf("\n\n\n\t\t");
}

//****************************************************

void Menu1()    //�˵�����
{
	cout <<"\n\t\t"<<"��ѡ������һ������:"<<endl;
	cout <<"\n\t\t"<<"1.��ʾ��������"<<endl;
	cout <<"\t\t2.�����ݽ�������" << endl;
	cout <<"\t\t3.����" << endl;
    cout <<"\t\t4.ɾ��"<<endl;
	cout <<"\t\t5.����"<<endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;

}


BinaryTreeNode *makingtree()
{

	char name[10][10]={"����","����","����","����","����","Ф��","��ǿ","����","��־","��־"};
	float CPMark[10]={78.0, 84.0 ,75.0, 90.0, 80.0, 85.0 ,94.0, 81.0, 85.0, 83.0};
	float DSMark[10]={82.0, 70.0 ,88.0 ,84.0 ,95.0, 83.0, 88.0 ,84.0, 88.0, 78.0};
	float PGMark[10]={90.0, 78.0, 92.0 ,66.0 ,77.0, 85.0, 89.0 ,79.0, 95.0, 87.0};
	float Average[10]={83.0, 78.0, 86.0, 80.0 ,84.0, 85.0, 90.0, 82.0, 91.0, 87.0};
	int No[10]={1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
	for(int i=0;i<10;i++)
	{
		strcpy(student[i].Name,name[i]);		
 		student[i].CPMark=CPMark[i];	
		student[i].DSMark=DSMark[i];
		student[i].PGMark=PGMark[i];
		student[i].Average=Average[i];
		student[i].No=No[i];

	}
	BinaryTreeNode *BT = MakeNode(student[0]);
	for(i=0;i<10;i++)
	{
		Insert(BT,student[i]);
	}
	return BT;
}

void Display(BinaryTreeNode *BT)
{
	cout<<"********************************************************"<<endl;
	cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<"  "<<student[i].No<<"  "<<student[i].Name<<"      "
			<<student[i].CPMark<<"        "<<student[i].DSMark<<"         "
			<<student[i].PGMark<<"       "<<student[i].key<<endl;
	}
	cout<<"********************************************************"<<endl;
	
}

void main_switch1(char j)
{
	ElementType result;
	ElementType newvalue;
	int SearchKey;
	switch(j)
	{
	case '1'://��ʾ��������
		BT = makingtree();
		Display(BT);
		system("pause");
		system("cls");
		break;
	case'2':
		BT = makingtree();
		cout<<"��ƽ���ɼ�����"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		InOrderRecurseive(BT);
		system("pause");
		system("cls");
		break;
	case'3':
		BT = makingtree();
		cout<<"��ƽ���ɼ�����"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		InOrderRecurseive(BT);

		cout<<"Ҫ���ҵ��˵�ƽ���ɼ�";
		cin>>SearchKey;
		cout<<endl;
		if(Search(BT,result,SearchKey))
		{
			cout<<"ѧ��"<<result.No<<"  ����"<<result.Name<<endl;
			cout<<"  ���������"<<result.CPMark<<"  ���ݽṹ"<<result.DSMark
			<<"  �������"<<result.PGMark<<"  ƽ��"<<result.key<<endl;
		}
		else
			cout<<"δ�ҵ�����"<<endl;
		system("pause");
		system("cls");
		break;
	case'4':
		BT = makingtree();
		cout<<"��ƽ���ɼ�����"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		InOrderRecurseive(BT);

		cout<<"Ҫɾ�����˵�ƽ���ɼ�";
		cin>>SearchKey;
		cout<<endl;
		Delete(BT,SearchKey);
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		InOrderRecurseive(BT);
		system("pause");
		system("cls");
		break;
	case'5':
		BT = makingtree();
		cout<<"��ƽ���ɼ�����"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		InOrderRecurseive(BT);
		
		cout<<"Ҫ������˵�ѧ��";
		cin>>newvalue.No ;
		cout<<"   ����";
		cin>>newvalue.Name;
		cout<<"   ���������";
		cin>>newvalue.CPMark;
		cout<<"   ���ݽṹ";
		cin>>newvalue.DSMark;
		cout<<"   �������";
		cin>>newvalue.PGMark;
		cout<<"   ƽ���ɼ�";
		cin>>newvalue.key;
		cout<<endl;
		Insert(BT,newvalue);
		cout<<"��ƽ���ɼ�����"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		InOrderRecurseive(BT);
		system("pause");
		system("cls");
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
//************************************************************

void makeheaptree()
{
	char name[11][10]={"����","����","����","����","����","����","Ф��","��ǿ","����","��־","��־"};
	float CPMark[11]={0.0 ,78.0, 84.0 ,75.0, 90.0, 80.0, 85.0 ,94.0, 81.0, 85.0, 83.0};
	float DSMark[11]={0.0 ,82.0, 70.0 ,88.0 ,84.0 ,95.0, 83.0, 88.0 ,84.0, 88.0, 78.0};
	float PGMark[11]={0.0 ,90.0, 78.0, 92.0 ,66.0 ,77.0, 85.0, 89.0 ,79.0, 95.0, 87.0};
	float Average[11]={0.0 ,83.0, 78.0, 86.0, 80.0 ,84.0, 85.0, 90.0, 82.0, 91.0, 87.0};
	int No[11]={0000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
	for(int i=0;i<11;i++)
	{
		strcpy(heap[i].Name ,name[i]);		
 		heap[i].CPMark=CPMark[i];	
		heap[i].DSMark=DSMark[i];
		heap[i].PGMark=PGMark[i];
		heap[i].Average=Average[i];
		heap[i].No=No[i];
	}

}

void Displayheap(ElementType heap[20],int size)
{
	cout<<"********************************************************"<<endl;
	cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
	for(int i=1;i<size+1;i++)
	{
		cout<<"  "<<heap[i].No<<"  "<<heap[i].Name<<"      "
			<<heap[i].CPMark<<"        "<<heap[i].DSMark<<"         "
			<<heap[i].PGMark<<"       "<<heap[i].key<<endl;
	}
	cout<<"********************************************************"<<endl;
	
}

void Menu2()    //�˵�����
{
	cout <<"\n\t\t"<<"��ѡ������һ������:"<<endl;
	cout <<"\n\t\t"<<"1.��ʾ��������"<<endl;
	cout <<"\t\t2.�����ݽ�������" << endl;
	cout <<"\t\t3.����" << endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;

}

void main_switch2(char j)
{
	ElementType newvalue;
	switch(j)
	{
	case '1'://��ʾ��������
		InitializeMaxHeap(heap,HeapSize);
		Displayheap(heap,HeapSize);
		system("pause");
		system("cls");
		break;
	case'2':
		Displayheap(heap,HeapSize);
		HEAPSORT(heap,HeapSize);
		cout<<"��ƽ���ɼ�����"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		Displayheap(heap,HeapSize);
		system("pause");
		system("cls");
		break;
	case'3':
		InitializeMaxHeap(heap,HeapSize);
		Displayheap(heap,HeapSize);
		cout<<"Ҫ������˵�ѧ��";
		cin>>newvalue.No ;
		cout<<"   ����";
		cin>>newvalue.Name;
		cout<<"   ���������";
		cin>>newvalue.CPMark;
		cout<<"   ���ݽṹ";
		cin>>newvalue.DSMark;
		cout<<"   �������";
		cin>>newvalue.PGMark;
		cout<<"   ƽ���ɼ�";
		cin>>newvalue.key;
		cout<<endl;
		InsertMaxHeap(heap,HeapSize,newvalue);
		Displayheap(heap,HeapSize+1);
		system("pause");
		system("cls");
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



void main_switch(char j)
{
	char b[100];
	switch(j)
	{	
	case'1':
		BT = makingtree();
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
		makeheaptree();
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
	
	Menu_name();
	system("pause");
	system("cls");
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

