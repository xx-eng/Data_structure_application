// Huffman.cpp : Defines the entry point for the console application.
//利用数组整合数据感觉空间利用率不高，但是思路比较简洁
//对于一些指针的定义还是不可以熟练应用

#include "stdafx.h"
#include "huffmantree.h"



int main(int argc, char* argv[])
{
	int N = 0;
	char s[40];
	cout<<"输入字符（不超过40个）：";
	cin>>s;
	//char s[10] = "ABACCDA";
	int n[52] = {0}; 
	root *BT = new root;
	BT->first = NULL;
	
	
	integrationstr(s,n);   //整合数据
	

	EType *sss = orderstr(n,N);  //把数据存储在sss中

	BT->hdata = N;
	record *re = new record;

	HuffmanNode *treenode[52];    //这个可以怎样定义更好
	for(int i=0;i<N;i++)
	{
		treenode[i] = MakeNode(sss[i]);
		InsertNode(treenode[i],BT);
	}

	deletenode(BT);
	
	huffmancode(BT,re);

	for(i=0; s[i] != '\0' && s[i] !='\n';i++)
	{
		for(int j=0; j<N;j++)
		{
			if(re[j].name == s[i])
				cout<<re[j].code<<" ";
		}
	}
	
	
	return 0;
}

