
#include <iostream>
using namespace std;

typedef struct
{
	char name;     //信息
	int  num;      //出现次数
}EType;

typedef struct
{
	char name;
	char code[20];
}record;

typedef struct Huffmannode
{
	bool           flag;      //标记
	Huffmannode    *link;         //指向链表中的后继结点
	int   weight;               //出现了几次
	char  data;                 //结点的信息值
	Huffmannode  *LChild;          //左孩子结点
	Huffmannode  *RChild;          //右孩子结点 
}HuffmanNode;

typedef struct
{
	int          hdata;
	HuffmanNode *first;
}root;

void integrationstr(char s[],int n[52])
{// A--0 B--1  ……     a--26 b--27 ……
//将重复的字母的个数算出，存在n[52]中，且n[0]='A'  n[1]='B'   n[26]='a'
	int temp;
	char x;
	for(int i=0; s[i] !='\0' && s[i] != '\n'; i++)
	{
		if(s[i]>=65 && s[i]<=90)    //如果s[i] 为大写字母
			x = s[i] - 'A';      
		else 
			x = s[i] - 'a'+26;      //如果s[i] 为小写字母
		temp = (int)x;       
		n[temp]++;
	}
}


EType *orderstr(int n[52],int &x)
{//把上一个函数得出的数组再整合出来
	EType *p = new EType;
	int k = 0;
	for(int i=0;i<26;i++)
	{
		if(n[i] != 0)
		{
			p[k].name = (char)i + 'A';
			p[k].num = n[i];
			k++;
		}
	}
	for(i=26; i<52;i++)
	{
		if(n[i] != 0)
		{
			p[k].name = (char)i + 'a'-26;
			p[k].num = n[i];
			k++;
		}
	}
	x = k;
	return p;
}



HuffmanNode *MakeNode(EType &newvalue)
{//构造二叉树结点
	HuffmanNode *ptr;
	ptr = new HuffmanNode;
	if(!ptr) return NULL;
	ptr->data = newvalue.name ;
	ptr->weight = newvalue.num;
	ptr->flag = false;
	ptr->link = NULL;
	ptr->LChild = NULL;
	ptr->RChild = NULL;
	return ptr;
}

void InsertNode(HuffmanNode *newvalue,root *BT)
{
	HuffmanNode *p = BT->first;
	HuffmanNode *q = BT->first;
	HuffmanNode *temp = NULL;
	if(!BT->first)
		BT->first = newvalue;
	else
	{
		while(p)
		{
			if(newvalue->weight <= p->weight)    //要插入结点的权值小于p的权值，那么找到其位置
				break;
			p = p->link;        //p向下一个游走
		}
		
		if(BT->first != p)
		{
				while(q)
				{//找p的前一个q
					temp = q->link;
					if(temp == p)
						break;
					q = q->link;
				}
				if(!q)
					cout<<"不可能!!!"<<endl;        
				q->link = newvalue;
				newvalue->link = p;
	
		}
		else
		{//如果是在第一个，直接插入
			BT->first = newvalue;
			newvalue->link = p;
		}
	}
	
}

bool mark(char x)
{
	if((x>='a' && x<= 'z') || (x>='A' && x<='Z'))
		return true;
	return false;
}


void deletenode(root *BT)
{
	HuffmanNode *t = BT->first;
	if(t->link == NULL)  //BT->first没有下一个结点，则已经形成了一棵树
		return;
	
	HuffmanNode *p = BT->first ;   //第一个结点
	HuffmanNode *q = p->link ;    //第二个结点
	EType value;
	value.num = p->weight + q->weight;
	HuffmanNode *newvalue = MakeNode(value);
	if(mark(p->data) && !mark(q->data ))
	{
		newvalue->LChild = p;       //左孩子为有字符的，另一个为没有，没有弄标记，不想改了
		newvalue->RChild = q;
	}
	else
	{
		newvalue->LChild = q;
		newvalue->RChild = p;
	}

	BT->first = q->link;
	InsertNode(newvalue,BT);
	deletenode(BT);      //嵌套调用，很好用
}



void huffmancode(root *BT,record *re)
{//哈夫曼编码，这个是看着师兄的写的
	int n = 0;  //r 的下标
	int k=0;
	HuffmanNode *ptr = BT->first;
	if(ptr == NULL)
	{
		cout<<"哈夫曼树是空的!\n";
		exit(0);
	}
	else
	{
		while(ptr->LChild && ptr->RChild && !ptr->flag)  //有左、右孩子，标记为0
		{
			while(ptr->LChild && !ptr->LChild->flag)   //左孩子，其标记为0，未走遍
			{
				re[n].code[k++] = '0';
				ptr = ptr->LChild;   //往左走
				if(!ptr->LChild && ptr->RChild)  //判断是否为叶子结点
				{
					ptr->flag = true;
					re[n].name = ptr->data;
					re[n].code[k] = '\0';
					cout<<re[n].name<<"   "<<re[n].code<<endl;
					k = 0;
					n++;
					ptr = BT->first;      //从根开始
				}
			}
			if(ptr->RChild && !ptr->RChild->flag ) //有右孩子，且其标记为0，未走遍
			{
				ptr = ptr->RChild;
				re[n].code[k++] = '1';
			}
			if(!ptr->LChild && !ptr->RChild)  //没有左右孩子
			{
				ptr->flag = true;
				re[n].name = ptr->data;
				re[n].code[k++] = '\0';
				cout<<re[n].name<<"   "<<re[n].code<<endl;
				k = 0;
				n++;
				ptr = BT->first;
			}
			if(ptr->LChild->flag && ptr->RChild->flag)
			{
				ptr->flag = true;
				ptr = BT->first;
				k = 0;
			}
		}
	}
	cout<<endl;

}