// Eight_queens.cpp : Defines the entry point for the console application.
//我不知道可不可以运行到20皇后(因为我的栈的最大值为20)，但是九皇后是没有问题的；
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
	int i = 0;     //行
	int j = 0;     //列
	
	j = current.col;
	for(i = 0 ; i<N ; i++)
	{//同一列上有没有皇后
		if(r[i][j] == 1)
			return false;
	}
	
	for(i = row1,j = col1; i<N && j<N ; i++,j++)
	{//右下斜线
		if(r[i][j] == 1)
			return false;
	}
	
	for(i = row1,j = col1; i>=0 && j>=0 ;i--,j--)
	{//左上斜线
		if(r[i][j] == 1)
			return false;
	}

	for(i = row1,j = col1; i>=0 && j<N ;i--,j++)
	{//右上斜线
		if(r[i][j] == 1)
			return false;
	}

	for(i = row1,j = col1; i<N && j>=0 ;i++,j--)  //注意判断条件，易写错
	{//左下斜线
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
				cout<<"○";
			else
				cout<<"●";
		}
		cout<<endl;
	}*/
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(r[i][j] == 0)
				cout<<"○";
			else
				cout<<"●";
		}
		cout<<endl;
	}
	system("pause");
}


void
  eight_queens(Stack &S,int N)  //返回总的个数,S里存皇后，r[][]表示棋盘中皇后的位置，1则有皇后,N是几个皇后
{
	int r[20][20] = {0};
//	int top;
	int total = 0;   //答案的个数
	int k = 1;       //第几个皇后
	int row = 0;     //第一个皇后的行
	int col = 0;     //列
	StackType   current;    //当前要入栈的皇后的行列
	current.row = row;
	current.col = col;

	Push(S,current);      //入栈
	r[current.row][current.col] = 1;       //该皇后占位
	k++;                //下一个皇后，K表示第几个皇后进行测试					
	current.row = current.row + 1;
	current.col = 0;
	do
	{
		while( k <= N && S.element[0].col < N && k>0 )  //未加K的条件可能会导致即使没有解，K仍然减少，不结束循环
		{
			if(checkqueen(N,r,current) && current.col < N)   //当且皇后所在列与行可行,后面那个判断条件忘加的话会在第61个解里出问题
			{
				Push(S,current);      //入栈
				r[current.row][current.col] = 1;       //该皇后占位
				k++;                //下一个皇后，K表示第几个皇后进行测试					
				current.row = current.row + 1;
				current.col = 0;
			}
			else 
			{
					current.col++;     //列取下一列
					while(current.col >= N)       //当current的列大于棋盘列数时，出栈
					{
						if(!IsEmpty(S))  //出栈还是要判断一下的！！！！
						{
							Pop(S,current);
							k--;
							r[current.row][current.col] = 0;   //该皇后不在该位上
							current.row = current.row;
							current.col = current.col + 1;
						}
						else
							break;
					}
			}

			if(k==1 && current.col >=N)  //真的是很难找的条件，否则在上一步死循环
				break;
		}


		
		if(S.top == N-1 )          //解
		{
			
			total ++ ;
			cout<<"第"<<total<<"组解为"<<endl;         //输出解
			Display(N,r);
		                           //恢复栈
			if(!IsEmpty(S))
			{
				Pop(S,current);//最后一个皇后换下一列的位置
				k--;
				r[current.row][current.col] = 0;
				current.row = current.row;
				current.col = current.col++;
			}
			else
				break;
		}
		col = S.element[0].col ;                  //判断结束


	}while( col <N  && !IsEmpty(S) && k>=0);
	
	
	
}








int main(int argc, char* argv[])
{
	int N;

	cout<<"输入有几个皇后(不多于20个）：";
	cin>>N;
	cout<<endl;


	
	Stack S;
	createStack(S);
	eight_queens(S,N);

	
	return 0;
}

