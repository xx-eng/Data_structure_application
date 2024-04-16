#include "Stack.h"

/*1��������������������Ǿ�ֱ�ӽ��������
2����������������������ǽ�����뵽ջ�У�����������ʱ����Ҳ�������ջ�С�
3���������һ�������ţ���ջԪ�ص������������Ĳ��������ֱ������������Ϊֹ��ע�⣬������ֻ�������������
4����������κ������Ĳ��������磨��+���� ��*�������������ȣ���ջ�е���Ԫ��ֱ���������ָ������ȼ���Ԫ��(����ջΪ��)Ϊֹ����������ЩԪ�غ󣬲Ž������Ĳ�����ѹ�뵽ջ�С���һ����Ҫע�⣬ֻ��������" ) "����������ǲŵ���" ( "������������Ƕ����ᵯ��" ( "��
5��������Ƕ����������ĩβ����ջ������Ԫ�����ε�����*/

bool Operate1(char exp[30],char str[30])  //exp��Ϊ�������׺����ʽ��strΪ��ת���ɵĺ�׺����ʽ
{
	int               MaxStackSize = 30;
	Stack<StackType>  S(MaxStackSize);
	StackType result,result1;
	char ch,ch1;
	StackType temp;
	ch = *exp++;      //ch Ϊ��һ���ַ���expָ����һ��
	temp.bracket = ch;
	int i=0;
	while(ch != '#')
	{
		temp.bracket = ch;            
		if( ch>='0' && ch<='9' )             //���chΪ��ĸ��ŵ�str��,ֻ����һ�����ֵ�������
		{
			str[i] = ch;
			i++;
		}
		else
		{
			switch(ch)             
			{
				case '+':
					{
						if(!S.IsEmpty())
						{
							S.GetTop(result);         //ȡ��ջ��Ԫ��
							ch1 = result.bracket; 
							while(ch1 == '/'  ||  ch1 == '*')
							//ջ�����ȼ�С��+��-       
							{
								S.Pop(result1);                       //��ջ�������ַ�����
								str[i] = result1.bracket;
								i++;
								if(S.IsEmpty())   break;
							}
						}
						S.Push(temp); 
						break;
					}

						      //��ջ
				case '-':            //���Ϊ-�����ж�ջ�������ȼ��Ƿ�С��+��-
					{
						if(!S.IsEmpty())
						{
							S.GetTop(result);         //ȡ��ջ��Ԫ��
							ch1 = result.bracket; 
							while(ch1 == '/'  ||  ch1 == '*')
							//ջ�����ȼ�С��+��-       
							{
								S.Pop(result1);                       //��ջ�������ַ�����
								str[i] = result1.bracket;
								i++;
								if(S.IsEmpty())   break;
							}
						}
						S.Push(temp);       //��ջ
						break;
					}
				case '*':
				case '/':
					{
						 S.Push(temp);
						 break;
					}
					
				case '(':
					{
						S.Push(temp);
						break;
					}
				case '{':
					{
						S.Push(temp);
						break;
					}
				case ')':
					{
						if(!S.IsEmpty())
						{
							S.Pop(temp);
							ch1 = temp.bracket;
							while( ch1 != '(')          //��ջ����Ϊ��ʱ
							{
								str[i] = temp.bracket;     //��ջ���ķ��Ŵ��뵽str��
								i++;
								if(!S.IsEmpty())           //ջ���ǿ�
								{
									S.Pop(temp);            
									ch1 = temp.bracket;     //��ջ���ķ��ŷŵ�ch1�����Ƚ�
								}
								else if(S.IsEmpty())
								{
									return false;
									break;
								}
							}
						}
						break;
					}

				case '}':
					{
						if(!S.IsEmpty())
						{
							S.Pop(temp);
							ch1 = temp.bracket;
							while( ch1 != '{')
							{
								str[i] = temp.bracket;
								i++;
								if(!S.IsEmpty())
								{
									S.Pop(temp);
									ch1 = temp.bracket;
								}
								else if(S.IsEmpty())
								{
									return false;
									break;
								}
							}
						}
						break;
					}
			}
		
		}
		ch = *exp++;
	}
	while(!S.IsEmpty())
	{
		S.Pop(result1);
		str[i] = result1.bracket;
		i++;
	}
	str[i] = '#';
	return true;
}




StackType Operate(StackType f1,char ch,StackType f2)
{
	StackType result;
	switch(ch)
	{
	case '+':
		{
			result.value = f2.value + f1.value;
			break;
		}
	case '-':
		{
			result.value = f2.value - f1.value;
			break;
		}
	case '*':
		{
			result.value = f2.value * f1.value;
			break;
		}
	case '/':
		{
			result.value = f2.value/f1.value;
			break;
		}
	}
	return result;     //���ؼ�����
}


void Evalution(char *suffixexp, StackType &result)
{  //�����׺���ʽ��ֵ
	char ch;
	StackType x;
	StackType f1,f2;                       //������ջ����������
	 
	int MaxStackSize = 10;
	Stack<StackType>  S(MaxStackSize);     //����S��ջ

	ch = *suffixexp++;     //��ȡ��׺���ʽ�ĵ�һ���ַ�����׼���û�ȡ��һ����ַ
	while(ch != '#')
	{
		if( !(ch == '+' || ch == '-' || ch == '*' || ch == '/') )
		{
			x.value = (float)ch -48;      //ת��Ϊ��ֵ������
			S.Push(x);
		}
		else 
		{
			S.Pop(f1);         //��һ����������ջ
			S.Pop(f2);         //�ڶ�����������ջ
			x = Operate(f1,ch,f2);
			S.Push(x);
		}
		ch = *suffixexp++;
	}
	S.Pop(result);
}