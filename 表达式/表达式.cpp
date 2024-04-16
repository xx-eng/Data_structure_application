// 表达式.cpp : Defines the entry point for the console application.
//只能挑只含个位数的数运算，输入的是中缀表达式

#include "stdafx.h"
#include "Opetate.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	char exp[30] ,str[30];
	/*exp = "#";
	str = "#";*/
	StackType result;
	cout<<"输入一个式子（最后加入一个#,且括号要用英文格式）: ";
	cin>>exp;
	
	if(!Operate1(exp,str))
	{
		cout<<"输入不正确!"<<endl;
	}
	//str = "34+#";

	Evalution(str,result);
	cout<<"结果是：";
	cout<<result.value<<endl;

	
	return 0;
}

