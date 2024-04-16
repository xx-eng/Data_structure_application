// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binary.h"



char re_choose[]={"\nѡ��Ƿ�����������ȷ�ı��...\n"};
ElementType Student[5];
ElementType Student1[10];
BinaryTreeNode *treenode[5];//ϵͳ�Զ��������
BinaryTreeNode *treenode1[10];       //��������
int tree[10]= {0};    //����Ĺ�ϵ
int N;


void Menu_name()
     //������Ϣ
{   
	printf("\n\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                           �������ı���\n\n");
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
	cout <<"\n\t\t"<<"1.��ʾ��������"<<endl;
	cout <<"\t\t2.ǰ�����" << endl;
	cout <<"\t\t3.�������" << endl;
    cout <<"\t\t4.�������"<<endl;
	cout <<"\t\t5.��α������ϵ��£����ң�"<<endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;	


}

//**********************ϵͳ�Զ����� ****************************
void automaking()
{
	char name[10][10]={"����","����","����","����","Ф��"};
	
	int No[5]={1001,1002,1003,1004,1005};
	
	for(int i=0;i<5;i++)
	{
		Student[i].number = No[i];
		strcpy(Student[i].name,name[i]);
		treenode[i] = MakeNode(Student[i]);
	}
	MakeBinaryTree(treenode[0],treenode[1],NULL);
	MakeBinaryTree(treenode[1],treenode[2],treenode[3]);
	MakeBinaryTree(treenode[2],NULL,treenode[4]);
}





void main_switch1(char j)
{
	switch(j)
	{
	case '1'://��ʾ��������
		Display(treenode);
		system("pause");
		break;
	case'2':
		Display(treenode);
		PreRecursive(treenode[0]);
		system("pause");
		system("cls");
		break;
	case'3':
		Display(treenode);
		InRecursive(treenode[0]);
		system("pause");
		system("cls");
		break;
	case'4':
		Display(treenode);
		PostRecursive(treenode[0]);
		system("pause");
		system("cls");
		break;
	case'5':
		Display(treenode);
		Level_L_R_U_D(treenode[0]);
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

void importdata(int N)
{
	int j=1,k=1;
	int x=0;
	for(int i=0;i<N;i++)
	{
		cout<<"��"<<i+1<<"�����ݣ�"<<endl;
		cout<<"ѧ��";
		cin>>Student1[i].number ;
		cout<<"  ����";
		cin>>Student1[i].name;
		cout<<"    ����Ҫ�����������˳��������ķ����������֣�";
		cin>>tree[i];
		cout<<endl<<endl;
	}

	for(i=0;i<N;i++)
	{
		treenode1[i] = MakeNode(Student1[i]);
	}
	for(i=0;i<N;i++)
	{
		x = 2*tree[i];
		if(x <=  tree[N-1])
		{
			for(j = 1;j<N+1;j++)
			{
				if(tree[j-1] == x)      //����
					break;
			}
			if(j == N+1)
				j=0;
		}
		else
			j=0;
		x = 2*tree[i]+1;
		if(x<=tree[N-1])
		{
			for(k=1;k<N+1;k++)
			{
				if(tree[k-1] == x)           //�к���
					break;
			}
			if(k == N+1)
				k=0;
		}
		else
			k=0;

		if(j == 0 && k !=0)
		{
			MakeBinaryTree(treenode1[i],NULL,treenode1[k-1]);
		}
		if(j != 0 && k ==0)
		{
			MakeBinaryTree(treenode1[i],treenode1[j-1],NULL);
		}
		if(j != 0 && k !=0)
		{
			MakeBinaryTree(treenode1[i],treenode1[j-1],treenode1[k-1]);
		}
		j=0;
		k=0;
	}
	
}

void Display1(BinaryTreeNode *treenode[10],int tree[10],int N)
{
	for(int i=0;i<N;i++)
	{
		cout<<"����"<<treenode[i]->data.name<<"  ѧ��"<<treenode[i]->data.number<<endl;
		cout<<"��"<<tree[i]<<"��"<<endl<<endl;
	}
}


void main_switch2(char j,int N)
{
	switch(j)
	{
	case '1'://��ʾ��������
		Display1(treenode1,tree,N);
		system("pause");
		break;
	case'2':
		Display1(treenode1,tree,N);
		PreRecursive(treenode1[0]);
		system("pause");
		system("cls");
		break;
	case'3':
		Display1(treenode1,tree,N);
		InRecursive(treenode1[0]);
		system("pause");
		system("cls");
		break;
	case'4':
		Display1(treenode1,tree,N);
		PostRecursive(treenode1[0]);
		system("pause");
		system("cls");
		break;
	case'5':
		Display1(treenode1,tree,N);
		Level_L_R_U_D(treenode1[0]);
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


//#########################��ѡ��Ҫ�ķ�ʽ########################
void main_putin(char j)
{//�������ݵ�ѡ�񡭡���������������������
	char b[100];
	switch(j)
	{	
		case '1' ://��ʾ���Ա��е�����Ԫ��
			system("cls");
			automaking();
			while(1)
			{
				system("cls");
				Menu();	
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
			cout<<"��Ҫ���뼸�����ݣ�������10�� �ҵ�һ��Ϊ���ڵ㣩��";
			cin>>N;
			cout<<endl;
			
			importdata(N);

			while(1)
			{
				system("cls");
				Menu();	
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
					main_switch2(b[0],N);		
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
//#######################################################





int main(int argc, char* argv[])
{
	Menu_name();
	system("pause");
	system("cls");
	char a[100];

	while(1)
	{
		system("cls");
		printf("\n\tϵͳ�Զ����ɡ���1�������Լ����롪��2, exit--0:");
	
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
			main_putin(a[0]);		
			
		}

	}
	return 0;
}

