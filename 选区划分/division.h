
Stack  S;      //�Ǽ������Ի�Ϊһ��ѡ����ʱ����
StackType  sss[50][5] = {0};  //�滮�ֽ��


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

bool checkblock(constituency elem[14], int r[15][15],StackType k, Stack S)     //k--��ǰ��ջ   inSջ��
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



int devideblock(Stack &S,constituency elem[14] ,StackType sss[50][5],int r[15][15])      //��������������һ��  sss����
{
	StackType k = 1;
	StackType kkk = k;
	float votekkk = 0.0;
	float allkkk = 0.0;
	int n = 0;  //�洢������±�
	int nn = 0;
	StackType inS;  //ջ��Ԫ��
	int top = 0;
	int s[14] = {0};
	int sn = 0;
	do
	{
		while(k<=14 && total(elem,S)<= 100000)
		{
			
			if(!IsEmpty(S))
				top = S.top ;
			if(checkblock(elem,r,k,S))         //���������ڣ���ջ
			{
				Push(S,k);
			}
			if(total(elem,S)>=30000 && total(elem,S)<=100000 && S.top >top)  //������һ�������ļ����������Ի���Ϊһ������
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
	}while(!(IsEmpty(S) && k == 14)); //�������������
	for(k=1;k<=14;k++)
	{
		if(k != 10 && elem[k-1].all >= 50000 && norepeat(k,s))
		{
				sss[n][nn] = k;   //�����Ե�������浽�����
				n++;
				nn = 0;
				s[sn] = k;
				sn++;
		}
	}


/*
�����д�ĺܸ��ӵģ�����ֻ������һ�������Ӧ���Ǹտ�ʼ�ڵ�һ��ѭ����û���Ҷ���Ľ�������1,2֮���1,2,3�����º�����Ҫ�ж�
	do 
	{
		while(k<=14 && total(elem,S)<=100000)   //��ջ����ѡ����С��1000000ʱ
		{
			if(!IsEmpty(S))
				top = S.top;
			if(checkblock(elem,r,k,S))   //�жϿɷ���ͬһѡ��
			{
				Push(S,k);     //�ڣ�����ջ
				if(k != 10 && elem[k-1].all >= 50000  && norepeat(k,s))   //k���Ե�����Ϊһ��ѡ��
				{
					sss[n][nn] = k;   //�����Ե�������浽�����
					n++;
					nn = 0;
					s[sn] = k;
					sn++;
				}
				
			}				
			k++;             //��һ��
			if(total(elem,S) >= 30000 && S.top > top)  //ѡ������������30000�������һ����,��ֻһ��Ԫ��
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
 
	}while( k < 17);  //ջ�л���Ԫ�أ����һ�û�г��Ե����һ������*/
	return n;
}