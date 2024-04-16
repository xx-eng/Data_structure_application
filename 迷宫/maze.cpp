// maze.cpp : Defines the entry point for the console application.
//这个迷宫其答案只求了一种，未穷尽迷宫的所有走法

#include "stdafx.h"
#include "STACK.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;


#define N  10
void printmaze(int r[N][N]);

/* 函数声明：srand()用来设置rand()产生随机数时的随机数种子，参数seed必须是整数，通常可以用time(0)的返回值作为seed.
如果每次seed都设置相同的值，rand()产生的随机数值每次都一样。
 srand(unsigned)time(NULL))使用系统定时/计数器的值作为随机种子每个种子对应一组根据算法预先生成的随机数，
所以在相同平台的环境下，不同时间产生的随机数是不同的，
相应的若将srand(unsigned)tima(NULL)改为任一常量，
则无论何时运行，运行多少次得到的随机数都是一组特定的序列，
所以srand生成的随机数是伪随机数。*/


/*如要产生[m,n]范围内的随机数num，可用：
int num=rand()%(n-m+1)+m;*/



Stack   S;      //找路径的栈



bool nextposition(StackType current,StackType  &nextp,int r[N][N])
{//顺时针方向尝试下一步
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
//S用来找出路，r[10][10]是迷宫，entrance是入口的位置，exit是出口的位置
//0可通--未曾到过，1不可通,栈里位置为2

{
	int top;
	StackType  current;
	StackType  temp;
	StackType  nextp;
	current.row = entrance.row;
	current.col = entrance.col;
	do
	{
		if(S.element[S.top].row== exit.row && S.element[S.top].col == exit.col)  //判断是否为出口
			break;	
		if(r[current.row][current.col] == 0)//当前可通，未探寻过
		{
			Push(S,current);    //入栈
			r[current.row][current.col] = 2;   //栈中元素为2，防止死循环？？？？？
			if(current.row == exit.row && current.col == exit.col)
			{//出路，停止循环
				break;
			}
			else
			{   //当前不为出口
				current.row = current.row;
				current.col = current.col + 1;       //向东临方向探索
			}
		}
		else
		{//当前不可通
			top = S.top;
			Pop(S,temp);
			if(!IsEmpty(S) && nextposition(temp,nextp,r))
			{//栈不空，并且当前位置的有其他方向未探索
				S.top = top;  //恢复栈顶
				current = nextp;   //current指向可探索的地方
				//Push(S,current);       
				//r[current.row][current.col] = 2;
			}
			else if(!IsEmpty(S) && !nextposition(temp,nextp,r))
			{//若栈不空，且当且位置四周均不通
				current = temp;
				r[current.row][current.col] = 1;  //该点不可通
				//Pop(S,current);          //回到上一个点，好像不用出栈，前面已经把这一步退了
			}
		}
	}while(!IsEmpty(S));//这个条件不甚理解
}


void playmaze(int r[N][N],int n,Stack &Skeep,int rn[N][N])
{//输入的方向 0--东（→）   1--北（↑）  2--西（←）  3--南（↓）
	int top = Skeep.top;
	StackType  walk;
	Pop(Skeep,walk);
	if(n==0)
	//east
	{
		if(r[walk.row][walk.col + 1] == 1)
		{
			Skeep.top = top;
			cout<<"此路不通!"<<endl;
			system("pause");
		}

		else
		{
			Skeep.top = top;  //恢复栈顶
			walk.row = walk.row;
			walk.col = walk.col + 1;
			Push(Skeep,walk);  //走到了下一步,入栈
			r[walk.row][walk.col] = 3;  //玩家走的位置
		}
	}
	else if(n==1)
	//north
	{
		if(r[walk.row - 1][walk.col] == 1)
		{
			Skeep.top = top;
			cout<<"此路不通!"<<endl;
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
			cout<<"此路不通!"<<endl;
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
			cout<<"此路不通!"<<endl;
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
				cout<<"■";
			else if(r[i][j] == 0)
				cout<<"□";
			else if(r[i][j] == 2)
				cout<<"☆";
			else if(r[i][j] == 3)
				cout<<"※";
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
	int n;//选方向

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
	cout<<"输入入口位置:  row:";
	cin>>entrance.row;
	cout<<"\tcol:";
	cin>>entrance.col;
	cout<<"输入出口位置:  row:";
	cin>>entrance.row;
	cout<<"\tcol:";
	cin>>entrance.col;
	*/          
	//若想随机，可用该方式因为，会没有出路，所以直接定义了一个迷宫，方便调试
	//若想随机产生迷宫，需要定义出口及入口



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
		cout<<"向哪里走？(0:→ 1:↑ 2:← 3:↓ 4:return  5:看答案):";
		cin>>n;
		cout<<endl;
		playmaze(r2,n,Skeep,r1);
		
		system("cls");
		printmaze(r2);
		if(Skeep.element[Skeep.top].row == exit.row  && Skeep.element[Skeep.top].col == exit.col)
			break;
	}
	cout<<"恭喜!"<<endl;

	return 0;
}

