// ���ʽ.cpp : Defines the entry point for the console application.
//ֻ����ֻ����λ���������㣬���������׺���ʽ

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
	cout<<"����һ��ʽ�ӣ�������һ��#,������Ҫ��Ӣ�ĸ�ʽ��: ";
	cin>>exp;
	
	if(!Operate1(exp,str))
	{
		cout<<"���벻��ȷ!"<<endl;
	}
	//str = "34+#";

	Evalution(str,result);
	cout<<"����ǣ�";
	cout<<result.value<<endl;

	
	return 0;
}

