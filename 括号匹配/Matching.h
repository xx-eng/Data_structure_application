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
						cout<<"ERROR11:右边是），左边不是（"<<endl;
						return false;
					}
				}
				else
				{
					cout<<"ERROR11:右边是），左边没有任何括号！"<<endl;
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
						cout<<"ERROR21:右边是}，左边不是{"<<endl;
						return false;
					}
				}
				else
				{
					cout<<"ERROR11:右边是}，左边没有任何括号！"<<endl;
					return false;
				}
				break;
			}
		
		}
	ch = *exp++;
	}
	if(!S.IsEmpty())  
	{	
		cout<<"ERROR3:左边有括号，但右边没有括号了！"<<endl;
		return false;
	}
	return true;
}
