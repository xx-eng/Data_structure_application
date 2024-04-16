// Eight_queens.cpp : Defines the entry point for the console application.
//�Ҳ�֪���ɲ��������е�20�ʺ�(��Ϊ�ҵ�ջ�����ֵΪ20)�����ǾŻʺ���û������ģ�
//1--1  2--0  3--0 4--2  5--10  6--4   7--40 8--92 9--352

#include "stdafx.h"
#include "STACK.h"
#include <iostream>
using namespace std;



bool checkqueen(int N,int r[][20],StackType current)
{
	int row1,col1;
	row1 = current.row;
	col1 = current.col;
	int i = 0;     //��
	int j = 0;     //��
	
	j = current.col;
	for(i = 0 ; i<N ; i++)
	{//ͬһ������û�лʺ�
		if(r[i][j] == 1)
			return false;
	}
	
	for(i = row1,j = col1; i<N && j<N ; i++,j++)
	{//����б��
		if(r[i][j] == 1)
			return false;
	}
	
	for(i = row1,j = col1; i>=0 && j>=0 ;i--,j--)
	{//����б��
		if(r[i][j] == 1)
			return false;
	}

	for(i = row1,j = col1; i>=0 && j<N ;i--,j++)
	{//����б��
		if(r[i][j] == 1)
			return false;
	}

	for(i = row1,j = col1; i<N && j>=0 ;i++,j--)  //ע���ж���������д��
	{//����б��
		if(r[i][j] ==1)
			return false;
	}
	return true;
}

void Display(int N,int r[][20])
{
	/*while(!IsEmpty(S))
	{
		Pop(S,x);
		int i = x.row;
		int j = 0;
		for(j = 0; j<N ;j++)
		{
			if(r[i][j] == 0)
				cout<<"��";
			else
				cout<<"��";
		}
		cout<<endl;
	}*/
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(r[i][j] == 0)
				cout<<"��";
			else
				cout<<"��";
		}
		cout<<endl;
	}
	system("pause");
}


void
  eight_queens(Stack &S,int N)  //�����ܵĸ���,S���ʺ�r[][]��ʾ�����лʺ��λ�ã�1���лʺ�,N�Ǽ����ʺ�
{
	int r[20][20] = {0};
//	int top;
	int total = 0;   //�𰸵ĸ���
	int k = 1;       //�ڼ����ʺ�
	int row = 0;     //��һ���ʺ����
	int col = 0;     //��
	StackType   current;    //��ǰҪ��ջ�Ļʺ������
	current.row = row;
	current.col = col;

	Push(S,current);      //��ջ
	r[current.row][current.col] = 1;       //�ûʺ�ռλ
	k++;                //��һ���ʺ�K��ʾ�ڼ����ʺ���в���					
	current.row = current.row + 1;
	current.col = 0;
	do
	{
		while( k <= N && S.element[0].col < N && k>0 )  //δ��K���������ܻᵼ�¼�ʹû�н⣬K��Ȼ���٣�������ѭ��
		{
			if(checkqueen(N,r,current) && current.col < N)   //���һʺ����������п���,�����Ǹ��ж��������ӵĻ����ڵ�61�����������
			{
				Push(S,current);      //��ջ
				r[current.row][current.col] = 1;       //�ûʺ�ռλ
				k++;                //��һ���ʺ�K��ʾ�ڼ����ʺ���в���					
				current.row = current.row + 1;
				current.col = 0;
			}
			else 
			{
					current.col++;     //��ȡ��һ��
					while(current.col >= N)       //��current���д�����������ʱ����ջ
					{
						if(!IsEmpty(S))  //��ջ����Ҫ�ж�һ�µģ�������
						{
							Pop(S,current);
							k--;
							r[current.row][current.col] = 0;   //�ûʺ��ڸ�λ��
							current.row = current.row;
							current.col = current.col + 1;
						}
						else
							break;
					}
			}

			if(k==1 && current.col >=N)  //����Ǻ����ҵ���������������һ����ѭ��
				break;
		}


		
		if(S.top == N-1 )          //��
		{
			
			total ++ ;
			cout<<"��"<<total<<"���Ϊ"<<endl;         //�����
			Display(N,r);
		                           //�ָ�ջ
			if(!IsEmpty(S))
			{
				Pop(S,current);//���һ���ʺ���һ�е�λ��
				k--;
				r[current.row][current.col] = 0;
				current.row = current.row;
				current.col = current.col++;
			}
			else
				break;
		}
		col = S.element[0].col ;                  //�жϽ���


	}while( col <N  && !IsEmpty(S) && k>=0);
	
	
	
}








int main(int argc, char* argv[])
{
	int N;

	cout<<"�����м����ʺ�(������20������";
	cin>>N;
	cout<<endl;


	
	Stack S;
	createStack(S);
	eight_queens(S,N);

	
	return 0;
}

