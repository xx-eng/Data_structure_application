// 括号匹配.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include "Matching.h"



int main(int argc, char* argv[])
{
	char expstr[31];
	cout<<"请输入一个不超过30个字符式子(最后请加入一个#)： ";
	cin>>expstr;
    if(Matching(expstr))
		cout<<"匹配成功!"<<endl;

	return 0;
}

