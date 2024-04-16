// colormap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "STACK.h"
#include "windows.h"
using namespace std;
/*SetConsoleTextAttribute()函数是一个API设置字体颜色和背景色的函数。
参数表中使用两个属性（属性之间用，隔开）。
GetStdHandle()和FOREGROUND_*或BACKGROUND_*。*值为INTENSITY或RED或GREEN或BLUE。
第一个属性获得句柄（即要设置颜色的地方），第二个属性设置颜色。
属性相加是在属性值中间加“|”隔开即可。
GetStdHandle(STD_OUTPUT_HANDLE)获得句柄??。*/


void MapColor(int r[8][8],int n,Stack<StackType> &S)
{//将地图用4中颜色染色，n个地区间的相邻关系在r数组中表示
	int MaxStackSize = 20;
	Stack<StackType> Skeep(MaxStackSize);   //创建堆栈对象sKEEP
	//Stack<StackType> S(MaxStackSize);
	//结果在S堆栈中，若在内部创立，则返回S即可
	StackType  x,temp;          //堆栈中数据元素类型
	bool flag;          
	int currentArea = 1;       //当前准备染色的区域编号，从1号地区开始
	int currentColor = 1;      //当前准备使用的颜色编号，从1号颜色开始
	x.AreaIndex = currentArea;
	x.ColorIndex = currentArea;
	S.Push(x);                           //1号地区以1号颜色染色，并进栈
	currentArea++;                       //地区编号增1,准备为新地区染色
	while(currentArea<=n)
	{
		flag = true;       //flag为真时，表示堆栈中已染色区域比较时未发现重色
		while(!S.IsEmpty() && flag)
		{  //从栈顶至栈底与已染色区域逐个比较有无重色
			S.Pop(x);  
			Skeep.Push(x)  ;    //保存到Skeep中，以便恢复
			if(x.ColorIndex  == currentColor && r[currentArea][x.AreaIndex])
			//栈中读出的区域与当前准备染色的区域要使用的颜色相同，且两个区域相邻   ???  r
			{
				flag = false;     //无法使用当且颜色，需改变颜色或出栈，结束比较
			}
		}
		if(flag)
		{//与已染色区域相比，无一同色
		//将当前区域号及使用颜色进栈，并准备下一个区域号，从颜色1开始尝试
			x.AreaIndex = currentArea;
			x.ColorIndex = currentColor;
			while(!Skeep.IsEmpty())
			{//从Skeep中恢复S堆栈的数据（为暂时染色的区域）
			//准备下一个区域染色时堆栈的初始数据
				Skeep.Pop(temp);
				S.Push(temp);
			}
			S.Push(x);       //当前染色区域进栈
		//	cout<<"		【进栈】"<<endl;
			     // S.DisplayStack();    //输出整个进栈过程
				currentArea++;
				currentColor = 1;
		}
		else
		{
			currentColor++;     //准备使用下一种颜色重新尝试
			while(!Skeep.IsEmpty())
			{//从Skeep堆栈中恢复S堆栈的数据（S中为暂时染色区域）
			 //退出栈顶染色区域，重新染色
				Skeep.Pop(temp);
				S.Push(temp);
			}
			while(currentColor > 4)
			{//如果当前使用的颜色或退出的栈顶的颜色超过4
				//说明栈顶染色不对，需出栈
				S.Pop(x);        //退出栈顶，重新染色
			//	cout<<"		【出栈】"<<endl;
				//S.DisplayStack();   //输出整个出栈过程
				currentColor = x.ColorIndex + 1;
				currentArea = x.AreaIndex;
			}
			flag = true;
		}
	}
}




int main(int argc, char* argv[])
{
	StackType   xx;

	//r[i][j]表示第i号区域和第j号区域相邻，则r[i][j] = 1,否则=0
	int r[8][8] = 
	{{0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,0},   // 1 near 2,3,4,5,6     
	{0,1,0,0,0,0,1,0},   //  2 near 6,1
	{0,1,0,0,1,1,0,0},   //  3 near 1,4,5
	{0,1,0,1,0,1,1,0},   //  4 near 1,3,5,6
	{0,1,0,1,1,0,1,0},   //  5 near 1,3,4,6
	{0,1,1,0,1,1,0,0},   //  6 near 1,2,4,5
	{0,0,0,0,0,0,0,0}};   //  7 none
	int n = 7;

	Stack<StackType>  S;
	Stack<StackType>  temp;
	MapColor(r,n,S);
	cout<<"1 near 2,3,4,5,6"<<endl;
	cout<<"2 near 6,1"<<endl;
	cout<<"3 near 1,4,5"<<endl;
	cout<<"4 near 1,3,5,6"<<endl;
	cout<<"5 near 1,3,4,6"<<endl;
	cout<<"6 near 1,2,4,5"<<endl;
	cout<<" 7 none"<<endl;
	while(!S.IsEmpty())
	{
		S.Pop(xx);
		temp.Push(xx);
		
	}
	while(!temp.IsEmpty())
	{
		temp.Pop(xx);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);//设置三色相加
		cout<<"\t第"<<xx.key<<"区：";
		if(xx.ColorIndex == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
			cout<<"blue"<<endl;
		}
		else if(xx.ColorIndex == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
			cout<<"purple"<<endl;
		}
		else if(xx.ColorIndex == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
			cout<<"yellow"<<endl;
		}
		else if(xx.ColorIndex == 4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"red"<<endl;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);//设置三色相加
	return 0;
}

