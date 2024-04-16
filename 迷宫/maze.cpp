// maze.cpp : Defines the entry point for the console application.
//����Թ����ֻ����һ�֣�δ��Թ��������߷�

#include "stdafx.h"
#include "STACK.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;


#define N  10
void printmaze(int r[N][N]);

/* ����������srand()��������rand()���������ʱ����������ӣ�����seed������������ͨ��������time(0)�ķ���ֵ��Ϊseed.
���ÿ��seed��������ͬ��ֵ��rand()�����������ֵÿ�ζ�һ����
 srand(unsigned)time(NULL))ʹ��ϵͳ��ʱ/��������ֵ��Ϊ�������ÿ�����Ӷ�Ӧһ������㷨Ԥ�����ɵ��������
��������ͬƽ̨�Ļ����£���ͬʱ�������������ǲ�ͬ�ģ�
��Ӧ������srand(unsigned)tima(NULL)��Ϊ��һ������
�����ۺ�ʱ���У����ж��ٴεõ������������һ���ض������У�
����srand���ɵ��������α�������*/


/*��Ҫ����[m,n]��Χ�ڵ������num�����ã�
int num=rand()%(n-m+1)+m;*/



Stack   S;      //��·����ջ



bool nextposition(StackType current,StackType  &nextp,int r[N][N])
{//˳ʱ�뷽������һ��
	if(r[current.row][current.col + 1] == 0)
	{//EAST
		nextp.row = current.row;
		nextp.col = current.col +1;
		return true;
	}
	else if(r[current.row - 1][current.col] == 0)
	{//NORTH
		nextp.row = current.row - 1;
		nextp.col = current.col;
		return true;
	}
	else if(r[current.row][current.col - 1] == 0)
	{//WEST
		nextp.row = current.row ;
		nextp.col = current.col - 1;
		return true;
	}
	else if(r[current.row + 1][current.col] == 0)
	{//SOURTH
		nextp.row = current.row + 1 ;
		nextp.col = current.col;
		return true;
	}
	else 
		return false;
}

void MazePath(Stack &S,int r[N][N], StackType entrance,StackType exit)  
//S�����ҳ�·��r[10][10]���Թ���entrance����ڵ�λ�ã�exit�ǳ��ڵ�λ��
//0��ͨ--δ��������1����ͨ,ջ��λ��Ϊ2

{
	int top;
	StackType  current;
	StackType  temp;
	StackType  nextp;
	current.row = entrance.row;
	current.col = entrance.col;
	do
	{
		if(S.element[S.top].row== exit.row && S.element[S.top].col == exit.col)  //�ж��Ƿ�Ϊ����
			break;	
		if(r[current.row][current.col] == 0)//��ǰ��ͨ��δ̽Ѱ��
		{
			Push(S,current);    //��ջ
			r[current.row][current.col] = 2;   //ջ��Ԫ��Ϊ2����ֹ��ѭ������������
			if(current.row == exit.row && current.col == exit.col)
			{//��·��ֹͣѭ��
				break;
			}
			else
			{   //��ǰ��Ϊ����
				current.row = current.row;
				current.col = current.col + 1;       //���ٷ���̽��
			}
		}
		else
		{//��ǰ����ͨ
			top = S.top;
			Pop(S,temp);
			if(!IsEmpty(S) && nextposition(temp,nextp,r))
			{//ջ���գ����ҵ�ǰλ�õ�����������δ̽��
				S.top = top;  //�ָ�ջ��
				current = nextp;   //currentָ���̽���ĵط�
				//Push(S,current);       
				//r[current.row][current.col] = 2;
			}
			else if(!IsEmpty(S) && !nextposition(temp,nextp,r))
			{//��ջ���գ��ҵ���λ�����ܾ���ͨ
				current = temp;
				r[current.row][current.col] = 1;  //�õ㲻��ͨ
				//Pop(S,current);          //�ص���һ���㣬�����ó�ջ��ǰ���Ѿ�����һ������
			}
		}
	}while(!IsEmpty(S));//��������������
}


void playmaze(int r[N][N],int n,Stack &Skeep,int rn[N][N])
{//����ķ��� 0--��������   1--��������  2--��������  3--�ϣ�����
	int top = Skeep.top;
	StackType  walk;
	Pop(Skeep,walk);
	if(n==0)
	//east
	{
		if(r[walk.row][walk.col + 1] == 1)
		{
			Skeep.top = top;
			cout<<"��·��ͨ!"<<endl;
			system("pause");
		}

		else
		{
			Skeep.top = top;  //�ָ�ջ��
			walk.row = walk.row;
			walk.col = walk.col + 1;
			Push(Skeep,walk);  //�ߵ�����һ��,��ջ
			r[walk.row][walk.col] = 3;  //����ߵ�λ��
		}
	}
	else if(n==1)
	//north
	{
		if(r[walk.row - 1][walk.col] == 1)
		{
			Skeep.top = top;
			cout<<"��·��ͨ!"<<endl;
			system("pause");
		}
		else
		{
			Skeep.top = top;
			walk.row = walk.row - 1;
			walk.col = walk.col;
			Push(Skeep,walk);
			r[walk.row][walk.col] = 3;
		}
	}
	else if(n==2)
	//west
	{
		if(r[walk.row ][walk.col - 1] == 1)
		{
			Skeep.top = top;
			cout<<"��·��ͨ!"<<endl;
			system("pause");
		}

		else
		{
			Skeep.top = top;
			walk.row = walk.row;
			walk.col = walk.col - 1;
			Push(Skeep,walk);
			r[walk.row][walk.col] = 3;
		}
	}
	else if(n==3)
	//south
	{
		if(r[walk.row +1][walk.col] == 1)
		{
			Skeep.top = top;
			cout<<"��·��ͨ!"<<endl;
			system("pause");
		}
		else
		{
			Skeep.top = top;
			walk.row = walk.row + 1;
			walk.col = walk.col;
			Push(Skeep,walk);
			r[walk.row][walk.col] = 3;
		}
	}
	else if(n==4)
	{
		r[walk.row][walk.col] = 0;
	}
	else if(n==5)
	{
		Skeep.top = top;
		printmaze(rn);
		system("pause");
	}
}

void printmaze(int r[N][N])
{
	int i=0;
	int j=0;
	for(i = 0; i<N;i++)
	{
		for(j = 0;j<N;j++)
		{
			if(r[i][j] == 1)
				cout<<"��";
			else if(r[i][j] == 0)
				cout<<"��";
			else if(r[i][j] == 2)
				cout<<"��";
			else if(r[i][j] == 3)
				cout<<"��";
		}
		cout<<endl;
	}
	cout<<endl<<endl<<endl;
}




int main(int argc, char* argv[])
{
	Stack Skeep;
	StackType entrance;
	StackType exit;

	entrance.row = 3;
	entrance.col = 0;
	exit.row = 3;
	exit.col = 9;
	createStack(Skeep);
	createStack(S);
	int n;//ѡ����

	int i = 0;
	int j = 0;	
    int r[N][N]= {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,1,0,1,1},
		{1,0,0,0,1,0,1,0,0,1},
		{0,0,1,0,1,0,1,0,0,0},
		{1,0,0,0,1,0,1,0,1,1},
		{1,1,0,0,1,0,0,0,0,1},
		{1,0,1,0,1,0,1,1,1,1},
		{1,0,0,0,0,0,0,1,0,1},
		{1,1,0,1,1,1,0,1,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};
	int r1[N][N],r2[N][N];


	/*srand((unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i == 0  || j == 0  || i == N-1 || j == N-1)
				r[i][j] = 1;
			else
				r[i][j] = rand()%2 + 0;
			if(i == entrance.row && j == entrance.col )
				r[i][j] = 0;
			if(i == exit.row && j == exit.col )
				r[i][j] = 0;
		}
	}
	cout<<"�������λ��:  row:";
	cin>>entrance.row;
	cout<<"\tcol:";
	cin>>entrance.col;
	cout<<"�������λ��:  row:";
	cin>>entrance.row;
	cout<<"\tcol:";
	cin>>entrance.col;
	*/          
	//������������ø÷�ʽ��Ϊ����û�г�·������ֱ�Ӷ�����һ���Թ����������
	//������������Թ�����Ҫ������ڼ����



	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			r1[i][j] = r[i][j];
			r2[i][j] = r[i][j];
		}
	}

	Push(Skeep,entrance);
	r2[entrance.row][entrance.col] = 3;
	printmaze(r);

	MazePath(S,r1,entrance,exit);
	//printmaze(r1);


	while(!IsEmpty(Skeep))
	{
		cout<<"�������ߣ�(0:�� 1:�� 2:�� 3:�� 4:return  5:����):";
		cin>>n;
		cout<<endl;
		playmaze(r2,n,Skeep,r1);
		
		system("cls");
		printmaze(r2);
		if(Skeep.element[Skeep.top].row == exit.row  && Skeep.element[Skeep.top].col == exit.col)
			break;
	}
	cout<<"��ϲ!"<<endl;

	return 0;
}

