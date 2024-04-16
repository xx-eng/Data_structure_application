// elect.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "STACK.h"
#include "division.h"
#include <iostream>
using namespace std;

//*****************���￪ʼ�ǵڶ���*********************
Stack  W;	   //���ܵ�ѡ����ʽ��ʱ���ã�����һ�������ˣ��������ø���


int ww[50][6] = {0};
float poll[50] = {0.0};

constituency element1[14];

void Menu_name()
     //������Ϣ
{   
	printf("\n\n\n\n\n\n\n");
	printf("              *************************************************\n");
	printf("                           ѡ������\n\n");
	printf("                           ����:����꿡�����Ƽ����躡�Ѧ��\n");
	printf("                           �༶:��Ϣ1802��\n");
	printf("                           ѧ��: 201821130093\n");
	printf("                           ָ����ʦ: �����\n");
	printf("              **************************************************\n");
	printf("\n\n\n\t\t");
}


void changea(int n,int sss[50][5],int a[14])  //a�е�0 ��Ϊ1
{
	int i=0,k=0;
	for(i=0;i<5;i++)
	{
		k = sss[n][i];
		if(k != 0)
			a[k-1] = 1;	
	}
}

bool checkall(int a[14]) //��һ����Ϊ1 ����Ϊ��
{
	for(int i=0;i<14;i++)
	{
		if(a[i] == 0)
			return true;
	}
	return false;
}

bool checkn(int n,int a[14],int sss[50][5]) 
{
	int k = 0;
	int i = 0;
	
	for(i=0;i<5;i++)
	{
		k = sss[n][i];      //ѡ���еĽ���
		if(k != 0)
		{
			if(a[k-1] == 1)
				return false;
		}
	}
	return true;
}

void six_part(int sss[50][5],Stack &W,int N,int ww[50][6])
{
	StackType k = 0;
	int mm = 0;
	int x=0; //X������¼sss[k]�еĽ���
	int j = 0;//sss[n][y]
	int top = 0;
	int n = 0;
	int i = 0;
	int y = 0;//ww[i][j]
	int a[14] = {0};
	do
	{
		while(W.top < 6 && n < N)//a�в�ȫΪ1,��n����49ʱ
		{
			if(checkn(n,a,sss) && n< N)  //������Է�Ϊһ��
			{
				Push(W,n);        //��ջ
				changea(n,sss,a);
			}
			else 
				n++;
		}
		top = W.top;
		if(!checkall(a) && W.top == 5)
		{
			while(!IsEmpty(W))
			{
				Pop(W,k);   //��K�������Ļ��ֽ��
				ww[i][j] = k;   //��I ��ѡ�������е�j�������ǰ����ĸ����ֽ��
				j++;
			}
			i++;
			j = 0;
			W.top = top;
		}
		Pop(W,n);
		for(y=0;y<5;y++)
		{
			k = sss[n][y];
			a[k-1] = 0;
			if(sss[n][y] == 0)
				break;
		}
		n++;
 

	}while(!(n == N-1 && IsEmpty(W)));
}
//*******************************************************************

void diplaydivision(int sss[50][5],float poll[50])
{
	int j=0;
	cout<<"\t����������������������������������������������������������������������������" <<endl;   //�������Щȩ੦
	for(int i=0 ;i<48;i++)
	{
		cout<<"\t ��"<<i+1<<" ��"<<"     ";
		for(j=0;j<5;j++)
		{
			if(sss[i][j] == 0)
				break;
			cout<<sss[i][j]<<" ";
			
		}
		cout<<"    "<<poll[i];
		cout<<endl;
		cout<<"\t����������������������������������������������������������������������������"<<endl;
	}
	
}


void calculate(int ww[50][6],float poll[50],float K,int sss[50][5])
{
	int t[48] = {0};
	int n = 0,on = 0;
	int i = 0 ,j = 0;
	int k = 0,x[10] = {0};//�����Ľ��x[10]
	int y = 0,m = 1;
	int themax = 0;
	for(i = 0;i<36;i++)
	{
		for(j = 0;j<6;j++)
		{
			k = ww[i][j];
			if(poll[k] >= K)
				t[i]++;
		}
	}
	
	for(i=0;i<36;i++)
	{
		cout<<"��"<<i+1<<"�����ֽ��:"<<endl;
		for(j = 0;j<6;j++)
		{
			cout<<"��"<<j+1<<"��ѡ��:";
			k = ww[i][j];
			for(y=0;y<5;y++)
			{
				if(sss[k][y] == 0)
					break;
				cout<<sss[k][y]<<"  ";
			}
			cout<<endl;
		}
		cout<<"��Ӯ��ѡƱ������Ϊ:"<<t[i]<<endl;
		cout<<endl;
	}

	cout<<endl<<endl<<endl;


	for(i = 0;i<36;i++)
	{
		if(t[i]>=themax)
		{
			themax = t[i];
		}
	}
	for(i = 0;i<36;i++)
	{
		if(t[i] == themax)
		{
			x[n] = i;
			n++;
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		if(x[i] == 0)
			break;
		on = x[i];
		cout<<"��Ʊ��ߵ�ѡ�����Ϊ����"<<on<<"���"<<endl;
		for(j = 0;j<6;j++)
		{
			k = ww[on][j];
			cout<<"��"<<m<<"��������";
			m++;
			for(y=0;y<5;y++)
			{
				if(sss[k][y] == 0)
					break;
				cout<<sss[k][y]<<"  ";
			}
			cout<<endl;
		}
	}
	
}

int main(int argc, char* argv[])
{
	int i=0;
	int j=0;
	int totald = 0;
	float K =0;
	float votepoll = 0.0;
	float allpoll = 0.0;
	int x = 0;

	int r[15][15] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,0,1,0,0,0,0,0,0,0,0,0},   //һ��һ��������
	{0,1,0,1,0,1,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
	{0,1,1,1,1,0,1,0,0,0,1,0,0,0,0},
	{0,0,0,0,0,1,0,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,0,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,0,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,1,1,0,0,1,1,0,0},
	{0,0,0,0,1,1,0,0,1,0,0,1,0,1,0},
	{0,0,0,0,0,0,0,0,1,1,1,0,1,1,1},
	{0,0,0,0,0,0,0,0,0,1,0,1,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,1,1,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0}};



	createStack(S);
	createStack(W);

	int vote[14] = {17500,15000,14200,42000,18000,9000,12000,10000,26000,34000,2500,27000,29000,15000};
	int all[14] = {30000,50000,20000,70000,20000,40000,30000,30000,40000,60000,10000,60000,40000,40000};
	
	for(i=0;i<14;i++)
	{   
		element1[i].vote = vote[i];
		element1[i].all = all[i];
	}
	
	Menu_name();
	system("pause");
	system("cls");


	totald = devideblock(S,element1,sss,r);
	cout<<"����"<<totald<<"�ֻ��ַ���"<<endl;
	for(i = 0;i<totald;i++)
	{
		for(j=0;i<totald;j++)
		{
			if(sss[i][j] == 0)
				break;
			x = sss[i][j];
			votepoll = element1[x-1].vote + votepoll;
			allpoll = element1[x-1].all + allpoll;
		}
		poll[i] = votepoll / allpoll;
		votepoll = 0.0;
		allpoll = 0.0;
	}
	diplaydivision(sss,poll);
	six_part(sss,W,totald,ww);

	cout<<"����Ʊ�ı����Ƕ��٣�";
	cin>>K;
	cout<<endl;

	
	calculate(ww,poll,K,sss);
	
	return 0;
}
