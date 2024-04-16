#include "appdata.h"
#include <string.h>
//没有考虑名字重复的情况


template <class ElementType>
class MultipleChainNode
{
public:
	ElementType   data;
	
	MultipleChainNode<ElementType>  *link[4];
	MultipleChainNode<ElementType>  *plink[4];
	//nlink[0]--name  nlink[1]--sex  nlink[2]--party  nlink[3]--career
};

typedef struct nameee
{
	MultipleChainNode<ElementType>    *first;
}nameee;

typedef  struct  sexxx
{
	MultipleChainNode<ElementType>  *first[2];  //0--male  1--female
}sexxx;

typedef  struct  partyyy
{
	MultipleChainNode<ElementType>  *first[3];  //0--共产党  1--民主党  2--无党派
}partyyy;

typedef  struct  careerrr
{
	MultipleChainNode<ElementType>  *first[5];  //0--教授   1--副教授   2--讲师  3--助教  4--教辅
}careerrr;


template <class ElementType>
class MultipleChainList
{//多重链表模板类的定义
public:
	MultipleChainList();
	~MultipleChainList();

	int LengthNameList() const;
	//名字表的长度
	
	MultipleChainNode<ElementType> *GetFirstPtrMultipleChainList(int k);
	//获取多重链表中第一个结点的指针first的值.
	//1--姓名   2--male  3--female  4--共产党  5--民主党  6--无党派  7--教授   8--副教授   9--讲师  10--助教  11--教辅

	bool GetElementMultipleChainList(int k,ElementType &result);
	//链表第k个元素值取至result中带回。如不存在返回false，存在返回true
	//k为名字链表中的顺序


	bool  SearchElement(char n[10], char s, char par,  char car);
	//查找函数

	bool InsertElement(ElementType &newvalue);
	//插入元素
   
	void	DisplayMultipleChainList(MultipleChainList<ElementType> &AppList);
	//显示输出线性表中的所有数据元素的值
	void    DisplayMultipleChainNode(ElementType result);
		//显示单个元素

private:
	nameee  *mainfirst1;
	sexxx  *mainfirst2;
	partyyy  *mainfirst3;
	careerrr  *mainfirst4;
};



template <class ElementType>
MultipleChainList<ElementType>::
MultipleChainList()
{//构造函数
	mainfirst1 = new nameee;
	mainfirst2 = new sexxx;
	mainfirst3 = new partyyy;
	mainfirst4 = new careerrr;
	mainfirst1->first = NULL;

	mainfirst2->first[0] = NULL;
	mainfirst2->first[1] = NULL;

	mainfirst3->first[0] = NULL;
	mainfirst3->first[1] = NULL;
	mainfirst3->first[2] = NULL;

	mainfirst4->first[0] = NULL;
	mainfirst4->first[1] = NULL;
	mainfirst4->first[2] = NULL;
	mainfirst4->first[3] = NULL;
	mainfirst4->first[4] = NULL;
	
}

template <class ElementType>
MultipleChainList<ElementType>::
~MultipleChainList()
{//析构函数
	int i=0;
	MultipleChainNode<ElementType> *current = mainfirst1->first;    //名字表
	while(mainfirst1->first)
	{
		current = current->link[0];
		delete mainfirst1->first;
		mainfirst1->first = current;
	}
	delete mainfirst1;
	

	for(i=0;i<2;i++)
	{
		current = mainfirst2->first[i];       //性别表
		while(mainfirst2->first[i]);
		{ 
			current = current->link[1];
			delete mainfirst2->first[i];
		    mainfirst2->first[i] = current;
		}
	}
	delete mainfirst2;

	for(i=0;i<3;i++)
	{
		current = mainfirst3->first[i];     //党派表
		while(mainfirst3->first[i]);
		{ 
			current = current->link[2];
			delete mainfirst3->first[i];
		    mainfirst3->first[i] = current;
		}
	}
	delete mainfirst3;
	
	for(i=0;i<5;i++)
	{
		current = mainfirst4->first[i];      //职称表
		while(mainfirst4->first[i]);
		{ 
			current = current->link[3];
			delete mainfirst4->first[i];
		    mainfirst4->first[i] = current;
		}
	}
	delete mainfirst4;
	
}

template <class ElementType>
int MultipleChainList<ElementType>::
LengthNameList() const
{//求长度
	MultipleChainNode<ElementType> *current = mainfirst1->first;
	int len = 0;
	while(current)
	{
		len++;
		current = current->link[0];
	}
	return len;
}

template <class ElementType>
bool MultipleChainList<ElementType>::
GetElementMultipleChainList(int k,ElementType &result)
{//链表第k个元素值取至result中带回。如不存在返回false，存在返回true
	//k为名字链表中
	if(k<1) return false;
	MultipleChainNode<ElementType> *current = mainfirst1->first;
	int index=1;
	while(index < k  && current)
	{
		current = current->link[0];
		index++;
	}
	if(current)
	{
		result = current->data;
		return true;
	}
	return false;
}


template <class ElementType>
MultipleChainNode<ElementType> *MultipleChainList<ElementType>::
GetFirstPtrMultipleChainList(int k)
{
	if(k==1)  return mainfirst1->first;
	if(k==2)  return mainfirst2->first[0];
	if(k==3)  return mainfirst2->first[1];
	if(k==4)  return mainfirst3->first[0];
	if(k==5)  return mainfirst3->first[1];
	if(k==6)  return mainfirst3->first[2];
	if(k==7)  return mainfirst4->first[0];
	if(k==8)  return mainfirst4->first[1];
	if(k==9)  return mainfirst4->first[2];
	if(k==10)  return mainfirst4->first[3];
	if(k==11)  return mainfirst4->first[4];
	else return NULL;
}

//查找函数
template <class ElementType>
bool  MultipleChainList<ElementType>::
SearchElement(char n[10], char s, char par,  char car)
{
	MultipleChainNode<ElementType> *current;
	int index = 0;

	if(!strcmp(n,"0"))
	{
	
		switch(s)
		{
		case '0':
			switch(par)
			{
			case '0':
				switch(car)
				{
				case '0':
					cout<<"无法查找!"<<endl;//没有信息
					return false;
					break;

				case 'p':
					current = mainfirst4->first[0];    //只有职称信息,current指向该职称的首结点
					while(current)
					{
						DisplayMultipleChainNode(current->data); //包含该职称的展示出来
						cout<<endl;
						current = current->link[3];  //current 移项该职称链表的下一个结点
						index++;
					}
					if(index != 0)  return true;
					else return false;
					break;

				case 'a':
					current = mainfirst4->first[1];
					while(current)
					{
						DisplayMultipleChainNode(current->data);
						cout<<endl;
						current = current->link[3];	
						index++;
					}
					if(index != 0)  return true;
					else return false;
					break;


				case 'l':
					current = mainfirst4->first[2];
					while(current)
					{
						DisplayMultipleChainNode(current->data)	;
						cout<<endl;
						current = current->link[3];						
					}
					if(index != 0)  return true;
					else return false;
					break;


				case 't':
					current = mainfirst4->first[3];
					while(current)
					{
						DisplayMultipleChainNode(current->data);
						cout<<endl;
						current = current->link[3];						
					}
					if(index != 0)  return true;
					else return false;
					break;


				case 's':
					current = mainfirst4->first[4];
					while(current)
					{
						DisplayMultipleChainNode(current->data);
						cout<<endl;
						current = current->link[3];						
					}
					if(index != 0)  return true;
					else return false;
					break;

				}
				break;

			case 'c':
				current = mainfirst3->first[0];//current指向党派首结点
				if(car == '0')        //只知道党派，不知道职称
				{
					while(current)
					{
						DisplayMultipleChainNode(current->data);
						cout<<endl;
						current = current->link[2];	
						index++;
					}
					if(index != 0)  return true;
					else return false;
				}
				else
				{
					while(current)
					{
						if(current->data.career == car)
						{
							DisplayMultipleChainNode(current->data);  //党派和职称都知道
							cout<<endl;
							index++;
						}
						current = current->link[2];	
					}
					if(index != 0)  return true;
					else return false;
				}
				break;

			case 'd':
				current = mainfirst3->first[1];//current指向党派首结点
				if(car == '0')        //只知道党派，不知道职称
				{
					while(current)
					{
						DisplayMultipleChainNode(current->data);
						cout<<endl;
						current = current->link[2];	
						index++;
					}
					if(index != 0)  return true;
					else return false;
				}
				else
				{
					while(current)
					{
						if(current->data.career == car)
						{
							DisplayMultipleChainNode(current->data);  //党派和职称都知道
							cout<<endl;
							index++;
						}
						current = current->link[2];	
					}
					if(index != 0)  return true;
					else return false;
				}
				break;

				case 'n':
				current = mainfirst3->first[2];//current指向党派首结点
				if(car == '0')        //只知道党派，不知道职称
				{
					while(current)
					{
						DisplayMultipleChainNode(current->data);
						cout<<endl;
						current = current->link[2];	
						index++;
					}
					if(index != 0)  return true;
					else return false;
				}
				else
				{
					while(current)
					{
						if(current->data.career == car)
						{
							DisplayMultipleChainNode(current->data);  
							cout<<endl;
							index++;
						}
						current = current->link[2];	
					}
					if(index != 0)  return true;
					else return false;
				}
				break;
			}
			break;


		case 'm':
			current = mainfirst2->first[0];
			if(par == '0' && car == '0')
			{
				while(current)
				{
					DisplayMultipleChainNode(current->data);  //只知道性别 
					cout<<endl;
					index++;
					current = current->link[1];
				}
				if(index !=0 ) return true;
				else return false;
			}
			else if(par == '0' && car !='0')
			{
				while(current)
				{
					if(current->data.career == car)
					{
							DisplayMultipleChainNode(current->data);  
							cout<<endl;
							index++;
					}
					current = current->link[1];
				}
				if(index !=0 ) return true;
				else return false;
			}

		else if(par != '0' && car =='0')
			{
				while(current)
				{
					if(current->data.party == par)
					{
							DisplayMultipleChainNode(current->data); 
							cout<<endl;
							index++;
					}
					current = current->link[1];
				}
				if(index !=0 ) return true;
				else return false;
			}
		else if(par != '0' && car !='0')
			{
				while(current)
				{
					if(current->data.party == par  && current->data.career == car)
					{
							DisplayMultipleChainNode(current->data); 
							cout<<endl;
							index++;
					}
					current = current->link[1];
				}
				if(index !=0 ) return true;
				else return false;
			}
		break;
		
		
		case 'f':
			current = mainfirst2->first[1];
			if(par == '0' && car == '0')
			{
				while(current)
				{
					DisplayMultipleChainNode(current->data);  //只知道性别 
					cout<<endl;
					index++;
					current = current->link[1];
				}
				if(index !=0 ) return true;
				else return false;
			}
			else if(par == '0' && car !='0')
			{
				while(current)
				{
					if(current->data.career == car)
					{
							DisplayMultipleChainNode(current->data); 
							cout<<endl;
							index++;
					}
					current = current->link[1];
				}
				if(index !=0 ) return true;
				else return false;
			}

		else if(par != '0' && car =='0')
			{
				while(current)
				{
					if(current->data.party == par)
					{
							DisplayMultipleChainNode(current->data);   
							cout<<endl;
							index++;
					}
					current = current->link[1];
				}
				if(index !=0 ) return true;
				else return false;
			}
		else if(par != '0' && car !='0')
			{
				while(current)
				{
					if(current->data.party == par  && current->data.career == car)
					{
							DisplayMultipleChainNode(current->data);  
							cout<<endl;
							index++;
					}
					current = current->link[1];
				}
				if(index !=0 ) return true;
				else return false;
			}
		break;
		}

	}
	else
	{
		current = mainfirst1->first;
		while(current && !strcmp(current->data.name,n))
		{
			current = current->link[0];
		}
		current = current->plink[0];
		if(current)
		{
			DisplayMultipleChainNode(current->data);
			return true;
		}
		else 
			return false;
	}
}



//插入函数
template <class ElementType>
bool MultipleChainList<ElementType>::
InsertElement(ElementType &newvalue)
{//只做了从开头插入的
	MultipleChainNode<ElementType> *current = new MultipleChainNode<ElementType>;//名字表
	MultipleChainNode<ElementType> *current1 = mainfirst1->first;
	current->data = newvalue;
	current->plink[0] = NULL;
	current->link[0] = mainfirst1->first;
	if(current1)
		current1->plink[0] = current;
	mainfirst1->first = current;

	MultipleChainNode<ElementType> *q = current;//性别表 
	MultipleChainNode<ElementType> *p ;
	switch(q->data.sex)
	{
		case 'm':
			q->plink[1] = NULL;  //q的plink指向空
			q->link[1] = mainfirst2->first[0];			//q的link指向p
			p = mainfirst2->first[0]; 
			if(p)
				p->plink[1] = q;       //p的plink指向q
			mainfirst2->first[0] = q;   //男性表的首结点指向q
			/*while(p)
			{
				if(p->data.sex == 'm')      
				{	q->link[1] = p;      
					q = p;				   
				}
				p = p->link[0];            

			}*/
			break;

		case 'f':
			q->plink[1] = NULL; 
			q->link[1] = mainfirst2->first[1];
			p = mainfirst2->first[1]; 
			if(p)
				p->plink[1] = q;
			mainfirst2->first[1] = q;
			/*{
				if(p->data.sex == 'f')
				{	
					q->link[1] = p;
					q = p;
				}
				p = p->link[0];
			}*/
			break;
	}


	q = current;//党派表
	switch(q->data.party)
	{
		case 'c':
			q->plink[2] = NULL; 
			q->link[2] = mainfirst3->first[0];
			p = mainfirst3->first[0]; 
			if(p)
				p->plink[2] = q;
			mainfirst3->first[0] = q;
			/*while(p)
			{
				if(p->data.party == 'c')
				{
					q->link[2] = p;
					q = p;
				}
				p = p->link[0];
			}*/
			break;

		case 'd':
			q->plink[2] = NULL; 
			q->link[2] = mainfirst3->first[1];
			p = mainfirst3->first[1]; 
			if(p)
				p->plink[2] = q;
			mainfirst3->first[1] = q;
			/*while(p)
			{
				if(p->data.party == 'd')
				{	
					q->link[2] = p;
					q =p;
				}
				p = p->link[0];
			}*/
			break;

		case 'n':
			q->plink[2] = NULL; 
			q->link[2] = mainfirst3->first[2];
			p = mainfirst3->first[2]; 
			if(p)
				p->plink[2] = q;
			mainfirst3->first[2] = q;
			/*while(p)
			{
				if(p->data.party == 'n')	
				{
					q->link[2] = q;
					q = p;
				}
				p = p->link[0];
			}*/
			break;
	}
	
	



//p--教授  a--副教授  l--讲师  t--助教  s--教辅
	q = current;			//职称表
	switch(q->data.career)
	{
		case 'p':
			q->plink[3] = NULL; 
			q->link[3] = mainfirst4->first[0];
			p = mainfirst4->first[0]; 
			if(p)
				p->plink[3] = q;
			mainfirst4->first[0] = q;
		/*	while(p)
			{
				if(p->data.career == 'p')
				{
					q->link[3] = p;
					q = p;
				}
				p = p->link[0];
			}*/
			break;

		case 'a':
			q->plink[3] = NULL; 
			q->link[3] = mainfirst4->first[1];
			p = mainfirst4->first[1]; 
			if(p)
				p->plink[3] = q;
			mainfirst4->first[1] = q;
			/*while(p)
			{
				if(p->data.career == 'a')
				{	
					q->link[3] = p;
					q = p;
				}
				p = p->link[0];	
			}*/
			break;

		case 'l':
			q->plink[3] = NULL; 
			q->link[3] = mainfirst4->first[2];
			p = mainfirst4->first[2]; 
			if(p)
				p->plink[3] = q;
			mainfirst4->first[2] = q;
			/*while(p)
			{
				if(p->data.career == 'l')
				{
					q->link[3] = p;	
					q = p;
				}
				p = p->link[0];
			}*/
			break;

		case 't':
			q->plink[3] = NULL; 
			q->link[3] = mainfirst4->first[3];
			p = mainfirst4->first[3]; 
			if(p)
				p->plink[3] = q;
			mainfirst4->first[3] = q;
			/*while(p)
			{
				if(p->data.career == 't')
				{
					q->link[3] = p;	
					q = p;
				}
				p = p->link[0];
			}*/
			break;

		case 's':
			q->plink[3] = NULL; 
			q->link[3] = mainfirst4->first[4];
			p = mainfirst4->first[4]; 
			if(p)
				p->plink[3] = q;
			mainfirst4->first[4] = q;
			/*while(p)
			{
				if(p->data.career == 's')
				{
					q->link[3] = p;
					q = p;
				}
				p = p->link[0];
			}*/
			break;
	}

	if(mainfirst1->first)
		return true;
	else
		return false;
}


template <class ElementType>
void MultipleChainList<ElementType>::
DisplayMultipleChainList(MultipleChainList<ElementType> &AppList)
{
	MultipleChainNode<ElementType> *current = mainfirst1->first;
	
	cout<<"\n\n";
	cout<<" ┌─────────────────────────────┐"<<endl;
	cout<<" │           信息表            │ "<<endl;
	cout<<" ├─────────────────────────────┤"<<endl;
	cout<<" │ 姓名 │性别│ 党  派 │ 职  称 │"<<endl;
	cout<<" ├──────┼────┼────────┼────────┤"<<endl;


	while(current)
	{
		cout<<" │ "<<current->data.name;
		if(current->data.sex == 'm')
			cout<<" │ "<<"男";
		else
			cout<<" │ "<<"女";

		if(current->data.party == 'c')
			cout<<" │ "<<"共产党";
		else if(current->data.party == 'd')
			cout<<" │ "<<"民主党";
		else
			cout<<" │ "<<"无党派";

		if(current->data.career == 'p')
			cout<<" │ "<<"教  授"<<" │ ";
		else if(current->data.career == 'a')
			cout<<" │ "<<"副教授"<<" │ ";
		else if(current->data.career == 'l')
			cout<<" │ "<<"讲  师"<<" │ ";
		else if(current->data.career == 't')
			cout<<" │ "<<"助  教"<<" │ ";
		else if(current->data.career == 's')
			cout<<" │ "<<"教  辅"<<" │ ";
		cout<<endl;
		cout<<" ├──────┼────┼────────┼────────┤"<<endl;
		current = current->link[0];
	} 
}

template <class ElementType>
void  MultipleChainList<ElementType>::
DisplayMultipleChainNode(ElementType result)
{
	cout<<result.name<<"  ";
	if(result.sex == 'f')
		cout<<"女"<<"  ";
	else
		cout<<"男"<<"  ";

	if(result.party == 'c')
		cout<<"共产党"<<"  ";
	else if(result.party == 'd')
		cout<<"民主党"<<"  ";
	else
		cout<<"无党派"<<"  ";

	if(result.career == 'p')
		cout<<"教授"<<"  ";
	else if(result.career == 'a')
		cout<<"副教授"<<"  ";
	else if(result.career == 'l')
		cout<<"讲师"<<"  ";
	else if(result.career == 't')
		cout<<"助教"<<"  ";
	else 
		cout<<"教辅"<<endl;

}







