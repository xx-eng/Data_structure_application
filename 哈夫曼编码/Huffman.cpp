// Huffman.cpp : Defines the entry point for the console application.
//���������������ݸо��ռ������ʲ��ߣ�����˼·�Ƚϼ��
//����һЩָ��Ķ��廹�ǲ���������Ӧ��

#include "stdafx.h"
#include "huffmantree.h"



int main(int argc, char* argv[])
{
	int N = 0;
	char s[40];
	cout<<"�����ַ���������40������";
	cin>>s;
	//char s[10] = "ABACCDA";
	int n[52] = {0}; 
	root *BT = new root;
	BT->first = NULL;
	
	
	integrationstr(s,n);   //��������
	

	EType *sss = orderstr(n,N);  //�����ݴ洢��sss��

	BT->hdata = N;
	record *re = new record;

	HuffmanNode *treenode[52];    //������������������
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

