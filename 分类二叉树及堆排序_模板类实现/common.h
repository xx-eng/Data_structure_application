
#include "AppData.h"
#include "sortree.h"
#include "heaptree.h"

#define  HeapSize 10 
#define  MaxHeapSize 20
char re_choose[]={"\nѡ��Ƿ�����������ȷ�ı��...\n"};
ElementType heap[20];
BinaryTreeNode *BTroot;
BinaryTree<ElementType> AppBT;

void Displayheap(ElementType heap[20],int size)
{
	cout<<"********************************************************"<<endl;
	cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
	for(int i=1;i<size+1;i++)
	{
		cout<<"  "<<heap[i].No<<"  "<<heap[i].Name<<"      "
			<<heap[i].CPMark<<"        "<<heap[i].DSMark<<"         "
			<<heap[i].PGMark<<"       "<<heap[i].key<<endl;
	}
	cout<<"********************************************************"<<endl;
	
}

//******************���������********************
void Menu1()    //�˵�����
{
	cout <<"\n\t\t"<<"��ѡ������һ������:"<<endl;
	cout <<"\n\t\t"<<"1.��ʾ��������"<<endl;
	cout <<"\t\t2.�����ݽ�������" << endl;
	cout <<"\t\t3.����" << endl;
    cout <<"\t\t4.ɾ��"<<endl;
	cout <<"\t\t5.����"<<endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;

}

BinaryTreeNode * makingtree(BinaryTree<ElementType> AppBT)
{
	
	ElementType newvalue;
	char name[10][10]={"����","����","����","����","����","Ф��","��ǿ","����","��־","��־"};
	float CPMark[10]={78.0, 84.0 ,75.0, 90.0, 80.0, 85.0 ,94.0, 81.0, 85.0, 83.0};
	float DSMark[10]={82.0, 70.0 ,88.0 ,84.0 ,95.0, 83.0, 88.0 ,84.0, 88.0, 78.0};
	float PGMark[10]={90.0, 78.0, 92.0 ,66.0 ,77.0, 85.0, 89.0 ,79.0, 95.0, 87.0};
	float Average[10]={83.0, 78.0, 86.0, 80.0 ,84.0, 85.0, 90.0, 82.0, 91.0, 87.0};
	int No[10]={1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
	strcpy(newvalue.Name,name[0]);
	newvalue.CPMark=CPMark[0];	
	newvalue.DSMark=DSMark[0];
	newvalue.PGMark=PGMark[0];
	newvalue.Average=Average[0];
	newvalue.No=No[0];
	BinaryTreeNode *BTroot = AppBT.MakeNode(newvalue);
	for(int i=1;i<10;i++)
	{
		strcpy(newvalue.Name ,name[i]);		
 		newvalue.CPMark=CPMark[i];	
		newvalue.DSMark=DSMark[i];
		newvalue.PGMark=PGMark[i];
		newvalue.Average=Average[i];
		newvalue.No=No[i];
		AppBT.InsertElementSortBinaryTree(BTroot,newvalue);
	}
	return BTroot;
}


void main_switch1(char j)
{
	ElementType result;
	ElementType newvalue;
	int SearchKey;
	switch(j)
	{
	case '1'://��ʾ��������
		BTroot = makingtree(AppBT);
		Displayheap(heap,HeapSize);
		system("pause");
		system("cls");
		break;
	case'2':
	    BTroot = makingtree(AppBT);
		cout<<"��ƽ���ɼ�����"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		AppBT.InOrderRecursive(BTroot);
		system("pause");
		system("cls");
		break;
	case'3':
		BTroot = makingtree(AppBT);
		cout<<"��ƽ���ɼ�����"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		AppBT.InOrderRecursive(BTroot);

		cout<<"Ҫ���ҵ��˵�ƽ���ɼ�";
		cin>>SearchKey;
		cout<<endl;
		if(AppBT.SearchElementSortBinaryTree(BTroot,result,SearchKey))
		{
			cout<<"ѧ��"<<result.No<<"  ����"<<result.Name<<endl;
			cout<<"  ���������"<<result.CPMark<<"  ���ݽṹ"<<result.DSMark
			<<"  �������"<<result.PGMark<<"  ƽ��"<<result.key<<endl;
		}
		else
			cout<<"δ�ҵ�����!!!"<<endl;
		system("pause");
		system("cls");
		break;
	case'4':
		BTroot = makingtree(AppBT);
		cout<<"��ƽ���ɼ�����"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		AppBT.InOrderRecursive(BTroot);

		cout<<"Ҫɾ�����˵�ƽ���ɼ�";
		cin>>SearchKey;
		cout<<endl;
		AppBT.DeleteElementSortBinaryTree_FromLeftTreeUpMaxNode(BTroot,SearchKey);
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		AppBT.InOrderRecursive(BTroot);
		system("pause");
		system("cls");
		break;
	case'5':
		BTroot = makingtree(AppBT);
		cout<<"��ƽ���ɼ�����"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		AppBT.InOrderRecursive(BTroot);
		
		cout<<"Ҫ������˵�ѧ��";
		cin>>newvalue.No ;
		cout<<"   ����";
		cin>>newvalue.Name;
		cout<<"   ���������";
		cin>>newvalue.CPMark;
		cout<<"   ���ݽṹ";
		cin>>newvalue.DSMark;
		cout<<"   �������";
		cin>>newvalue.PGMark;
		cout<<"   ƽ���ɼ�";
		cin>>newvalue.key;
		cout<<endl;

		AppBT.InsertElementSortBinaryTree(BTroot,newvalue);
		cout<<"��ƽ���ɼ�����"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		AppBT.InOrderRecursive(BTroot);
		system("pause");
		system("cls");
		break;
	
	case'0':
		exit(0);
		break;
	default  :
		cout <<re_choose<<endl;
		system("pause");
		system("cls");
		break;
	}
}




















//**************************��***********************************
void Menu2()    //�˵�����
{
	cout <<"\n\t\t"<<"��ѡ������һ������:"<<endl;
	cout <<"\n\t\t"<<"1.��ʾ��������"<<endl;
	cout <<"\t\t2.�����ݽ�������" << endl;
	cout <<"\t\t3.����" << endl;
	cout <<"\t\t0.�˳�.\n"<<endl;
	cout <<"\t\t===============================\n"<<endl;

}




void makeheaptree()
{
	char name[11][10]={"����","����","����","����","����","����","Ф��","��ǿ","����","��־","��־"};
	float CPMark[11]={0.0 ,78.0, 84.0 ,75.0, 90.0, 80.0, 85.0 ,94.0, 81.0, 85.0, 83.0};
	float DSMark[11]={0.0 ,82.0, 70.0 ,88.0 ,84.0 ,95.0, 83.0, 88.0 ,84.0, 88.0, 78.0};
	float PGMark[11]={0.0 ,90.0, 78.0, 92.0 ,66.0 ,77.0, 85.0, 89.0 ,79.0, 95.0, 87.0};
	float Average[11]={0.0 ,83.0, 78.0, 86.0, 80.0 ,84.0, 85.0, 90.0, 82.0, 91.0, 87.0};
	int No[11]={0000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
	for(int i=0;i<11;i++)
	{
		strcpy(heap[i].Name ,name[i]);		
 		heap[i].CPMark=CPMark[i];	
		heap[i].DSMark=DSMark[i];
		heap[i].PGMark=PGMark[i];
		heap[i].Average=Average[i];
		heap[i].No=No[i];
	}
}


void main_switch2(char j)
{
	ElementType newvalue;
	switch(j)
	{
	case '1'://��ʾ��������
		InitializeMaxHeap(heap,HeapSize);
		Displayheap(heap,HeapSize);
		system("pause");
		system("cls");
		break;
	case'2':
		Displayheap(heap,HeapSize);
		HeapSort(heap,HeapSize);
		cout<<"��ƽ���ɼ�����"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"  ѧ��  ����  ���������  ���ݽṹ  �������  ƽ���ɼ�  "<<endl;
		Displayheap(heap,HeapSize);
		system("pause");
		system("cls");
		break;
	case'3':
		InitializeMaxHeap(heap,HeapSize);
		Displayheap(heap,HeapSize);
		cout<<"Ҫ������˵�ѧ��";
		cin>>newvalue.No ;
		cout<<"   ����";
		cin>>newvalue.Name;
		cout<<"   ���������";
		cin>>newvalue.CPMark;
		cout<<"   ���ݽṹ";
		cin>>newvalue.DSMark;
		cout<<"   �������";
		cin>>newvalue.PGMark;
		cout<<"   ƽ���ɼ�";
		cin>>newvalue.key;
		cout<<endl;
		InsertElementMaxHeap(heap,HeapSize,newvalue);
		Displayheap(heap,HeapSize+1);
		system("pause");
		system("cls");
		break;

	
	case'0':
		exit(0);
		break;
	default  :
		cout <<re_choose<<endl;
		system("pause");
		system("cls");
		break;
	}
}





