#include "Stack.h"

/*1）如果遇到操作数，我们就直接将其输出。
2）如果遇到操作符，则我们将其放入到栈中，遇到左括号时我们也将其放入栈中。
3）如果遇到一个右括号，则将栈元素弹出，将弹出的操作符输出直到遇到左括号为止。注意，左括号只弹出并不输出。
4）如果遇到任何其他的操作符，如（“+”， “*”，“（”）等，从栈中弹出元素直到遇到发现更低优先级的元素(或者栈为空)为止。弹出完这些元素后，才将遇到的操作符压入到栈中。有一点需要注意，只有在遇到" ) "的情况下我们才弹出" ( "，其他情况我们都不会弹出" ( "。
5）如果我们读到了输入的末尾，则将栈中所有元素依次弹出。*/

bool Operate1(char exp[30],char str[30])  //exp即为任意的中缀多项式，str为其转换成的后缀多项式
{
	int               MaxStackSize = 30;
	Stack<StackType>  S(MaxStackSize);
	StackType result,result1;
	char ch,ch1;
	StackType temp;
	ch = *exp++;      //ch 为第一个字符，exp指向下一个
	temp.bracket = ch;
	int i=0;
	while(ch != '#')
	{
		temp.bracket = ch;            
		if( ch>='0' && ch<='9' )             //如果ch为字母则放到str中,只能挑一个数字的数运算
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
							S.GetTop(result);         //取出栈顶元素
							ch1 = result.bracket; 
							while(ch1 == '/'  ||  ch1 == '*')
							//栈顶优先级小于+或-       
							{
								S.Pop(result1);                       //出栈，放入字符串中
								str[i] = result1.bracket;
								i++;
								if(S.IsEmpty())   break;
							}
						}
						S.Push(temp); 
						break;
					}

						      //入栈
				case '-':            //如果为-，则判断栈顶的优先级是否小于+或-
					{
						if(!S.IsEmpty())
						{
							S.GetTop(result);         //取出栈顶元素
							ch1 = result.bracket; 
							while(ch1 == '/'  ||  ch1 == '*')
							//栈顶优先级小于+或-       
							{
								S.Pop(result1);                       //出栈，放入字符串中
								str[i] = result1.bracket;
								i++;
								if(S.IsEmpty())   break;
							}
						}
						S.Push(temp);       //入栈
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
							while( ch1 != '(')          //当栈顶不为（时
							{
								str[i] = temp.bracket;     //将栈顶的符号存入到str中
								i++;
								if(!S.IsEmpty())           //栈顶非空
								{
									S.Pop(temp);            
									ch1 = temp.bracket;     //将栈顶的符号放到ch1中作比较
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
	return result;     //返回计算结果
}


void Evalution(char *suffixexp, StackType &result)
{  //计算后缀表达式的值
	char ch;
	StackType x;
	StackType f1,f2;                       //两个进栈操作数定义
	 
	int MaxStackSize = 10;
	Stack<StackType>  S(MaxStackSize);     //创建S进栈

	ch = *suffixexp++;     //获取后缀表达式的第一个字符，并准备好获取下一个地址
	while(ch != '#')
	{
		if( !(ch == '+' || ch == '-' || ch == '*' || ch == '/') )
		{
			x.value = (float)ch -48;      //转换为数值型数据
			S.Push(x);
		}
		else 
		{
			S.Pop(f1);         //第一个操作数出栈
			S.Pop(f2);         //第二个操作数出栈
			x = Operate(f1,ch,f2);
			S.Push(x);
		}
		ch = *suffixexp++;
	}
	S.Pop(result);
}