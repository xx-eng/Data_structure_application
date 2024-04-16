#include "Stack.h"
#include <iostream>
using namespace std;


bool Matching(char exp[30])
{
	int               MaxStackSize = 30;
	Stack<StackType>  S(MaxStackSize);
	StackType		  temp;
	char              ch;
	ch = *exp++;
	temp.bracket = ch;
	while(ch != '#')
	{
		temp.bracket = ch;
		switch(ch)
		{
		case '(':
			{S.Push(temp);break;}

		case '{':
			{S.Push(temp);break;}

		case ')':
			{
				if(!S.IsEmpty())
				{
					S.Pop(temp);
					ch = temp.bracket;
					if(ch != '(')
					{
						cout<<"ERROR11:�ұ��ǣ�����߲��ǣ�"<<endl;
						return false;
					}
				}
				else
				{
					cout<<"ERROR11:�ұ��ǣ������û���κ����ţ�"<<endl;
					return false;
				}
				break;
			}
			
		case '}':
			{
				if(!S.IsEmpty())
				{
					S.Pop(temp);
					ch = temp.bracket;
					if(ch != '{')
					{
						cout<<"ERROR21:�ұ���}����߲���{"<<endl;
						return false;
					}
				}
				else
				{
					cout<<"ERROR11:�ұ���}�����û���κ����ţ�"<<endl;
					return false;
				}
				break;
			}
		
		}
	ch = *exp++;
	}
	if(!S.IsEmpty())  
	{	
		cout<<"ERROR3:��������ţ����ұ�û�������ˣ�"<<endl;
		return false;
	}
	return true;
}
