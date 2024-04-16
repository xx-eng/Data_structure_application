
#include <iostream>
using namespace std;

typedef struct
{
	char name;     //��Ϣ
	int  num;      //���ִ���
}EType;

typedef struct
{
	char name;
	char code[20];
}record;

typedef struct Huffmannode
{
	bool           flag;      //���
	Huffmannode    *link;         //ָ�������еĺ�̽��
	int   weight;               //�����˼���
	char  data;                 //������Ϣֵ
	Huffmannode  *LChild;          //���ӽ��
	Huffmannode  *RChild;          //�Һ��ӽ�� 
}HuffmanNode;

typedef struct
{
	int          hdata;
	HuffmanNode *first;
}root;

void integrationstr(char s[],int n[52])
{// A--0 B--1  ����     a--26 b--27 ����
//���ظ�����ĸ�ĸ������������n[52]�У���n[0]='A'  n[1]='B'   n[26]='a'
	int temp;
	char x;
	for(int i=0; s[i] !='\0' && s[i] != '\n'; i++)
	{
		if(s[i]>=65 && s[i]<=90)    //���s[i] Ϊ��д��ĸ
			x = s[i] - 'A';      
		else 
			x = s[i] - 'a'+26;      //���s[i] ΪСд��ĸ
		temp = (int)x;       
		n[temp]++;
	}
}


EType *orderstr(int n[52],int &x)
{//����һ�������ó������������ϳ���
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
{//������������
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
			if(newvalue->weight <= p->weight)    //Ҫ�������ȨֵС��p��Ȩֵ����ô�ҵ���λ��
				break;
			p = p->link;        //p����һ������
		}
		
		if(BT->first != p)
		{
				while(q)
				{//��p��ǰһ��q
					temp = q->link;
					if(temp == p)
						break;
					q = q->link;
				}
				if(!q)
					cout<<"������!!!"<<endl;        
				q->link = newvalue;
				newvalue->link = p;
	
		}
		else
		{//������ڵ�һ����ֱ�Ӳ���
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
	if(t->link == NULL)  //BT->firstû����һ����㣬���Ѿ��γ���һ����
		return;
	
	HuffmanNode *p = BT->first ;   //��һ�����
	HuffmanNode *q = p->link ;    //�ڶ������
	EType value;
	value.num = p->weight + q->weight;
	HuffmanNode *newvalue = MakeNode(value);
	if(mark(p->data) && !mark(q->data ))
	{
		newvalue->LChild = p;       //����Ϊ���ַ��ģ���һ��Ϊû�У�û��Ū��ǣ��������
		newvalue->RChild = q;
	}
	else
	{
		newvalue->LChild = q;
		newvalue->RChild = p;
	}

	BT->first = q->link;
	InsertNode(newvalue,BT);
	deletenode(BT);      //Ƕ�׵��ã��ܺ���
}



void huffmancode(root *BT,record *re)
{//���������룬����ǿ���ʦ�ֵ�д��
	int n = 0;  //r ���±�
	int k=0;
	HuffmanNode *ptr = BT->first;
	if(ptr == NULL)
	{
		cout<<"���������ǿյ�!\n";
		exit(0);
	}
	else
	{
		while(ptr->LChild && ptr->RChild && !ptr->flag)  //�����Һ��ӣ����Ϊ0
		{
			while(ptr->LChild && !ptr->LChild->flag)   //���ӣ�����Ϊ0��δ�߱�
			{
				re[n].code[k++] = '0';
				ptr = ptr->LChild;   //������
				if(!ptr->LChild && ptr->RChild)  //�ж��Ƿ�ΪҶ�ӽ��
				{
					ptr->flag = true;
					re[n].name = ptr->data;
					re[n].code[k] = '\0';
					cout<<re[n].name<<"   "<<re[n].code<<endl;
					k = 0;
					n++;
					ptr = BT->first;      //�Ӹ���ʼ
				}
			}
			if(ptr->RChild && !ptr->RChild->flag ) //���Һ��ӣ�������Ϊ0��δ�߱�
			{
				ptr = ptr->RChild;
				re[n].code[k++] = '1';
			}
			if(!ptr->LChild && !ptr->RChild)  //û�����Һ���
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