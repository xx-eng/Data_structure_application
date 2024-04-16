#include "appdata.h"
#include <string.h>
//û�п��������ظ������


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
	MultipleChainNode<ElementType>  *first[3];  //0--������  1--������  2--�޵���
}partyyy;

typedef  struct  careerrr
{
	MultipleChainNode<ElementType>  *first[5];  //0--����   1--������   2--��ʦ  3--����  4--�̸�
}careerrr;


template <class ElementType>
class MultipleChainList
{//��������ģ����Ķ���
public:
	MultipleChainList();
	~MultipleChainList();

	int LengthNameList() const;
	//���ֱ�ĳ���
	
	MultipleChainNode<ElementType> *GetFirstPtrMultipleChainList(int k);
	//��ȡ���������е�һ������ָ��first��ֵ.
	//1--����   2--male  3--female  4--������  5--������  6--�޵���  7--����   8--������   9--��ʦ  10--����  11--�̸�

	bool GetElementMultipleChainList(int k,ElementType &result);
	//�����k��Ԫ��ֵȡ��result�д��ء��粻���ڷ���false�����ڷ���true
	//kΪ���������е�˳��


	bool  SearchElement(char n[10], char s, char par,  char car);
	//���Һ���

	bool InsertElement(ElementType &newvalue);
	//����Ԫ��
   
	void	DisplayMultipleChainList(MultipleChainList<ElementType> &AppList);
	//��ʾ������Ա��е���������Ԫ�ص�ֵ
	void    DisplayMultipleChainNode(ElementType result);
		//��ʾ����Ԫ��

private:
	nameee  *mainfirst1;
	sexxx  *mainfirst2;
	partyyy  *mainfirst3;
	careerrr  *mainfirst4;
};



template <class ElementType>
MultipleChainList<ElementType>::
MultipleChainList()
{//���캯��
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
{//��������
	int i=0;
	MultipleChainNode<ElementType> *current = mainfirst1->first;    //���ֱ�
	while(mainfirst1->first)
	{
		current = current->link[0];
		delete mainfirst1->first;
		mainfirst1->first = current;
	}
	delete mainfirst1;
	

	for(i=0;i<2;i++)
	{
		current = mainfirst2->first[i];       //�Ա��
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
		current = mainfirst3->first[i];     //���ɱ�
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
		current = mainfirst4->first[i];      //ְ�Ʊ�
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
{//�󳤶�
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
{//�����k��Ԫ��ֵȡ��result�д��ء��粻���ڷ���false�����ڷ���true
	//kΪ����������
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

//���Һ���
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
					cout<<"�޷�����!"<<endl;//û����Ϣ
					return false;
					break;

				case 'p':
					current = mainfirst4->first[0];    //ֻ��ְ����Ϣ,currentָ���ְ�Ƶ��׽��
					while(current)
					{
						DisplayMultipleChainNode(current->data); //������ְ�Ƶ�չʾ����
						cout<<endl;
						current = current->link[3];  //current �����ְ���������һ�����
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
				current = mainfirst3->first[0];//currentָ�����׽��
				if(car == '0')        //ֻ֪�����ɣ���֪��ְ��
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
							DisplayMultipleChainNode(current->data);  //���ɺ�ְ�ƶ�֪��
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
				current = mainfirst3->first[1];//currentָ�����׽��
				if(car == '0')        //ֻ֪�����ɣ���֪��ְ��
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
							DisplayMultipleChainNode(current->data);  //���ɺ�ְ�ƶ�֪��
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
				current = mainfirst3->first[2];//currentָ�����׽��
				if(car == '0')        //ֻ֪�����ɣ���֪��ְ��
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
					DisplayMultipleChainNode(current->data);  //ֻ֪���Ա� 
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
					DisplayMultipleChainNode(current->data);  //ֻ֪���Ա� 
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



//���뺯��
template <class ElementType>
bool MultipleChainList<ElementType>::
InsertElement(ElementType &newvalue)
{//ֻ���˴ӿ�ͷ�����
	MultipleChainNode<ElementType> *current = new MultipleChainNode<ElementType>;//���ֱ�
	MultipleChainNode<ElementType> *current1 = mainfirst1->first;
	current->data = newvalue;
	current->plink[0] = NULL;
	current->link[0] = mainfirst1->first;
	if(current1)
		current1->plink[0] = current;
	mainfirst1->first = current;

	MultipleChainNode<ElementType> *q = current;//�Ա�� 
	MultipleChainNode<ElementType> *p ;
	switch(q->data.sex)
	{
		case 'm':
			q->plink[1] = NULL;  //q��plinkָ���
			q->link[1] = mainfirst2->first[0];			//q��linkָ��p
			p = mainfirst2->first[0]; 
			if(p)
				p->plink[1] = q;       //p��plinkָ��q
			mainfirst2->first[0] = q;   //���Ա���׽��ָ��q
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


	q = current;//���ɱ�
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
	
	



//p--����  a--������  l--��ʦ  t--����  s--�̸�
	q = current;			//ְ�Ʊ�
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
	cout<<" ��������������������������������������������������������������"<<endl;
	cout<<" ��           ��Ϣ��            �� "<<endl;
	cout<<" ��������������������������������������������������������������"<<endl;
	cout<<" �� ���� ���Ա� ��  �� �� ְ  �� ��"<<endl;
	cout<<" ���������������੤�������੤���������������੤����������������"<<endl;


	while(current)
	{
		cout<<" �� "<<current->data.name;
		if(current->data.sex == 'm')
			cout<<" �� "<<"��";
		else
			cout<<" �� "<<"Ů";

		if(current->data.party == 'c')
			cout<<" �� "<<"������";
		else if(current->data.party == 'd')
			cout<<" �� "<<"������";
		else
			cout<<" �� "<<"�޵���";

		if(current->data.career == 'p')
			cout<<" �� "<<"��  ��"<<" �� ";
		else if(current->data.career == 'a')
			cout<<" �� "<<"������"<<" �� ";
		else if(current->data.career == 'l')
			cout<<" �� "<<"��  ʦ"<<" �� ";
		else if(current->data.career == 't')
			cout<<" �� "<<"��  ��"<<" �� ";
		else if(current->data.career == 's')
			cout<<" �� "<<"��  ��"<<" �� ";
		cout<<endl;
		cout<<" ���������������੤�������੤���������������੤����������������"<<endl;
		current = current->link[0];
	} 
}

template <class ElementType>
void  MultipleChainList<ElementType>::
DisplayMultipleChainNode(ElementType result)
{
	cout<<result.name<<"  ";
	if(result.sex == 'f')
		cout<<"Ů"<<"  ";
	else
		cout<<"��"<<"  ";

	if(result.party == 'c')
		cout<<"������"<<"  ";
	else if(result.party == 'd')
		cout<<"������"<<"  ";
	else
		cout<<"�޵���"<<"  ";

	if(result.career == 'p')
		cout<<"����"<<"  ";
	else if(result.career == 'a')
		cout<<"������"<<"  ";
	else if(result.career == 'l')
		cout<<"��ʦ"<<"  ";
	else if(result.career == 't')
		cout<<"����"<<"  ";
	else 
		cout<<"�̸�"<<endl;

}







