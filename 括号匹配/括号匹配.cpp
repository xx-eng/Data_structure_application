// ����ƥ��.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include "Matching.h"



int main(int argc, char* argv[])
{
	char expstr[31];
	cout<<"������һ��������30���ַ�ʽ��(��������һ��#)�� ";
	cin>>expstr;
    if(Matching(expstr))
		cout<<"ƥ��ɹ�!"<<endl;

	return 0;
}

