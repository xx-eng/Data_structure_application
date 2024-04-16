
Stack  S;      //那几个可以划为一个选区的时候用
StackType  sss[50][5] = {0};  //存划分结果


float total(constituency elem[14],Stack S)
{
	float sum = 0;
	StackType tt;
	while(!IsEmpty(S))
	{
		Pop(S,tt);
		sum = sum + elem[tt-1].all;
	}
	return sum;
}

bool checkblock(constituency elem[14], int r[15][15],StackType k, Stack S)     //k--当前入栈   inS栈顶
{
	StackType cc;
	bool flag = false;
	if(IsEmpty(S))
		flag = true;
	while(!IsEmpty(S))
	{
		Pop(S,cc);
		if(r[k][cc] == 1)
		{
			flag = true;
			break;
		}
	}
	return flag;
}

bool norepeat(int k,int s[14])
{
	int i=0;
	for(i=0;i<14;i++)
	{
		if(k == s[i])
		{
			return false;
		}
	}
	return true;
}



int devideblock(Stack &S,constituency elem[14] ,StackType sss[50][5],int r[15][15])      //分区函数——第一步  sss存结果
{
	StackType k = 1;
	StackType kkk = k;
	float votekkk = 0.0;
	float allkkk = 0.0;
	int n = 0;  //存储结果的下标
	int nn = 0;
	StackType inS;  //栈顶元素
	int top = 0;
	int s[14] = {0};
	int sn = 0;
	do
	{
		while(k<=14 && total(elem,S)<= 100000)
		{
			
			if(!IsEmpty(S))
				top = S.top ;
			if(checkblock(elem,r,k,S))         //若街区相邻，入栈
			{
				Push(S,k);
			}
			if(total(elem,S)>=30000 && total(elem,S)<=100000 && S.top >top)  //若多于一个街区的几个街区可以划分为一个街区
			{
				top = S.top;
				while(!IsEmpty(S))
				{
					Pop(S,inS);
					sss[n][nn] = inS;
					nn++;
				}
			
				n++;
				nn = 0;
				S.top = top;
			}
			k++;
		}
		if(!IsEmpty(S))
		{
			Pop(S,k);
			k++;
		}
	}while(!(IsEmpty(S) && k == 14)); //这个条件很难找
	for(k=1;k<=14;k++)
	{
		if(k != 10 && elem[k-1].all >= 50000 && norepeat(k,s))
		{
				sss[n][nn] = k;   //若可以单独，则存到结果中
				n++;
				nn = 0;
				s[sn] = k;
				sn++;
		}
	}


/*
这个是写的很复杂的，而且只试用这一种情况。应该是刚开始在第一个循环里没有找多余的街区例如1,2之后的1,2,3，导致后面需要判断
	do 
	{
		while(k<=14 && total(elem,S)<=100000)   //当栈中总选民数小于1000000时
		{
			if(!IsEmpty(S))
				top = S.top;
			if(checkblock(elem,r,k,S))   //判断可否在同一选区
			{
				Push(S,k);     //在，则入栈
				if(k != 10 && elem[k-1].all >= 50000  && norepeat(k,s))   //k可以单独作为一个选区
				{
					sss[n][nn] = k;   //若可以单独，则存到结果中
					n++;
					nn = 0;
					s[sn] = k;
					sn++;
				}
				
			}				
			k++;             //下一个
			if(total(elem,S) >= 30000 && S.top > top)  //选区总人数大于30000则产生了一个解,不只一个元素
				break;
		}
		
		top = S.top;
		Pop(S,k1);
		S.top = top;

		if(total(elem,S)>=30000 && total(elem,S)<=100000 && S.top > 0  && k<15)
		{
			top = S.top;
			while(!IsEmpty(S))
			{
				Pop(S,inS);
				sss[n][nn] = inS;
				nn++;
			}
			
			n++;
			nn = 0;
			S.top = top;
		}
		else if(k == 15 && k1 == 14 && total(elem,S)<=100000 && S.top >0)
		{
			top = S.top;
			while(!IsEmpty(S))
			{
				Pop(S,inS);
				sss[n][nn] = inS;
				nn++;
			}
			
			n++;
			nn = 0;
			S.top = top;
			k++;
		}
		else 
		{
			if(!IsEmpty(S))
			{
				Pop(S,k);
				k++;
			}
			else 
				break;
		}
 
	}while( k < 17);  //栈中还有元素，并且还没有尝试到最后一个街区*/
	return n;
}