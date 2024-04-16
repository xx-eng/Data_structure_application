// colormap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "STACK.h"
#include "windows.h"
using namespace std;
/*SetConsoleTextAttribute()������һ��API����������ɫ�ͱ���ɫ�ĺ�����
��������ʹ���������ԣ�����֮���ã���������
GetStdHandle()��FOREGROUND_*��BACKGROUND_*��*ֵΪINTENSITY��RED��GREEN��BLUE��
��һ�����Ի�þ������Ҫ������ɫ�ĵط������ڶ�������������ɫ��
���������������ֵ�м�ӡ�|���������ɡ�
GetStdHandle(STD_OUTPUT_HANDLE)��þ��??��*/


void MapColor(int r[8][8],int n,Stack<StackType> &S)
{//����ͼ��4����ɫȾɫ��n������������ڹ�ϵ��r�����б�ʾ
	int MaxStackSize = 20;
	Stack<StackType> Skeep(MaxStackSize);   //������ջ����sKEEP
	//Stack<StackType> S(MaxStackSize);
	//�����S��ջ�У������ڲ��������򷵻�S����
	StackType  x,temp;          //��ջ������Ԫ������
	bool flag;          
	int currentArea = 1;       //��ǰ׼��Ⱦɫ�������ţ���1�ŵ�����ʼ
	int currentColor = 1;      //��ǰ׼��ʹ�õ���ɫ��ţ���1����ɫ��ʼ
	x.AreaIndex = currentArea;
	x.ColorIndex = currentArea;
	S.Push(x);                           //1�ŵ�����1����ɫȾɫ������ջ
	currentArea++;                       //���������1,׼��Ϊ�µ���Ⱦɫ
	while(currentArea<=n)
	{
		flag = true;       //flagΪ��ʱ����ʾ��ջ����Ⱦɫ����Ƚ�ʱδ������ɫ
		while(!S.IsEmpty() && flag)
		{  //��ջ����ջ������Ⱦɫ��������Ƚ�������ɫ
			S.Pop(x);  
			Skeep.Push(x)  ;    //���浽Skeep�У��Ա�ָ�
			if(x.ColorIndex  == currentColor && r[currentArea][x.AreaIndex])
			//ջ�ж����������뵱ǰ׼��Ⱦɫ������Ҫʹ�õ���ɫ��ͬ����������������   ???  r
			{
				flag = false;     //�޷�ʹ�õ�����ɫ����ı���ɫ���ջ�������Ƚ�
			}
		}
		if(flag)
		{//����Ⱦɫ������ȣ���һͬɫ
		//����ǰ����ż�ʹ����ɫ��ջ����׼����һ������ţ�����ɫ1��ʼ����
			x.AreaIndex = currentArea;
			x.ColorIndex = currentColor;
			while(!Skeep.IsEmpty())
			{//��Skeep�лָ�S��ջ�����ݣ�Ϊ��ʱȾɫ������
			//׼����һ������Ⱦɫʱ��ջ�ĳ�ʼ����
				Skeep.Pop(temp);
				S.Push(temp);
			}
			S.Push(x);       //��ǰȾɫ�����ջ
		//	cout<<"		����ջ��"<<endl;
			     // S.DisplayStack();    //���������ջ����
				currentArea++;
				currentColor = 1;
		}
		else
		{
			currentColor++;     //׼��ʹ����һ����ɫ���³���
			while(!Skeep.IsEmpty())
			{//��Skeep��ջ�лָ�S��ջ�����ݣ�S��Ϊ��ʱȾɫ����
			 //�˳�ջ��Ⱦɫ��������Ⱦɫ
				Skeep.Pop(temp);
				S.Push(temp);
			}
			while(currentColor > 4)
			{//�����ǰʹ�õ���ɫ���˳���ջ������ɫ����4
				//˵��ջ��Ⱦɫ���ԣ����ջ
				S.Pop(x);        //�˳�ջ��������Ⱦɫ
			//	cout<<"		����ջ��"<<endl;
				//S.DisplayStack();   //���������ջ����
				currentColor = x.ColorIndex + 1;
				currentArea = x.AreaIndex;
			}
			flag = true;
		}
	}
}




int main(int argc, char* argv[])
{
	StackType   xx;

	//r[i][j]��ʾ��i������͵�j���������ڣ���r[i][j] = 1,����=0
	int r[8][8] = 
	{{0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,0},   // 1 near 2,3,4,5,6     
	{0,1,0,0,0,0,1,0},   //  2 near 6,1
	{0,1,0,0,1,1,0,0},   //  3 near 1,4,5
	{0,1,0,1,0,1,1,0},   //  4 near 1,3,5,6
	{0,1,0,1,1,0,1,0},   //  5 near 1,3,4,6
	{0,1,1,0,1,1,0,0},   //  6 near 1,2,4,5
	{0,0,0,0,0,0,0,0}};   //  7 none
	int n = 7;

	Stack<StackType>  S;
	Stack<StackType>  temp;
	MapColor(r,n,S);
	cout<<"1 near 2,3,4,5,6"<<endl;
	cout<<"2 near 6,1"<<endl;
	cout<<"3 near 1,4,5"<<endl;
	cout<<"4 near 1,3,5,6"<<endl;
	cout<<"5 near 1,3,4,6"<<endl;
	cout<<"6 near 1,2,4,5"<<endl;
	cout<<" 7 none"<<endl;
	while(!S.IsEmpty())
	{
		S.Pop(xx);
		temp.Push(xx);
		
	}
	while(!temp.IsEmpty())
	{
		temp.Pop(xx);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);//������ɫ���
		cout<<"\t��"<<xx.key<<"����";
		if(xx.ColorIndex == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
			cout<<"blue"<<endl;
		}
		else if(xx.ColorIndex == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
			cout<<"purple"<<endl;
		}
		else if(xx.ColorIndex == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
			cout<<"yellow"<<endl;
		}
		else if(xx.ColorIndex == 4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"red"<<endl;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);//������ɫ���
	return 0;
}

