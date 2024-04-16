
#include "simulation.h"
#include <iostream>
using namespace std;

//template<class ElementType>


//template<class ElementType>
class SimulationChainList
{//����ģ������ռ�ļ�����
public:
	SimulationChainList(){first = -1;}   //���캯��
	~SimulationChainList(){DestroySimulationChainList();};
	int LengthSimulationChainList() const;  //����
	void DestroySimulationChainList();   //ɾ��ģ������
	int GetFirstSimulationChainList() {return first;} //��ͷ���
	int GetAvailablePtrSimulationChainSpace() {return SimSpace.availableptr;}
	//��ȡ���ÿռ��ͷ���ָ��availableptr
	bool GetElementSimulationChainList(int k,ElementType &result);
	//���ҵ�K������Ԫ�أ���ŵ�result��
	bool SearchElementSimulationChainList(int Searchkey,ElementType &result);
	//���ҹؼ���ΪSearchkey������Ԫ�أ���ŵ�result��
	bool InsertElementSimulationChainList(int k,ElementType &newvalue);
	//����ֵΪnewvalue������Ԫ�ص���K��Ԫ�صĺ���;
	bool DeleteElementSimulationChainList(int k,ElementType &result);
	//ɾ����K��Ԫ�أ���ֵ��ŵ�result��


	void DisplaySimulationChainList(SimulationChainList &Applist);
	void DisplayElementSimulationChainList(ElementType  &result);
	
private:
	int first;
	SimulationChainSpace SimSpace;
};


//template<class ElementType>
int SimulationChainList::
LengthSimulationChainList() const
{
	int currentptr = first;        //�������ͷָ��first
	int len = 0;                   //����������
	while(currentptr != -1)
	{
		currentptr = SimSpace.node[currentptr].link;     //�ƽ�ָ��
		len++;
	}
	return len;
}

//template<class ElementType>
void SimulationChainList::
DestroySimulationChainList()
{//ɾ�����н��
	int currentptr;
	while(first != -1)
	{
		currentptr = SimSpace.node[first].link;
		SimSpace.DeleteNodeSimulationChainSpace(first);   //�����ͷſռ�����
		first = currentptr;
	}
}


bool SimulationChainList::
GetElementSimulationChainList(int k,ElementType &result)
{//���ҵ�K��Ԫ��
	if(k<0 || GetAvailablePtrSimulationChainSpace() == -1)      return false;
	int currentptr = first;
	for(int index = 1; index<k && currentptr != -1; index++)
		//���ҵ�K��Ԫ��
		currentptr = SimSpace.node[currentptr].link;
	if(k>0 && currentptr == -1)  return false;
	if(k)
		result = SimSpace.node[currentptr].data;
}


bool SimulationChainList::
SearchElementSimulationChainList(int Searchkey,ElementType &result)
{//����ѧ��
	int currentptr = first;
	while(currentptr != -1 && SimSpace.node[currentptr].data.number == Searchkey)
	{
		currentptr = SimSpace.node[currentptr].link;
	}
	if(currentptr != -1)
	{	
		return true;
		result = SimSpace.node[currentptr].data;
	}
	else 
		return false;
}


bool SimulationChainList::
InsertElementSimulationChainList(int k,ElementType &newvalue)
{//ģ������ռ��� ����K��Ԫ��֮���в�����Ԫ��ֵnewvalue������
	if(k<0 || GetAvailablePtrSimulationChainSpace() == -1)      return false;
	int currentptr = first;
	for(int index = 1; index<k && currentptr != -1; index++)
		//���ҵ�K��Ԫ��
		currentptr = SimSpace.node[currentptr].link;
	if(k>0 && currentptr == -1)  return false;
	int q = SimSpace.NewNodeSimulationChainSpace();   //��ȡһ�����ռ�
	SimSpace.node[q].data = newvalue;
	if(k)
	{//�����ڵ�K�����֮��
		SimSpace.node[q].link = SimSpace.node[currentptr].link;
		SimSpace.node[currentptr].link = q;
	}
	else 
	{//k=0�����ڵ�һ��λ�ã���Ϊ������׽��
		SimSpace.node[q].link = first;
		first = q;
	}
	return true;
}



bool SimulationChainList::
DeleteElementSimulationChainList(int k,ElementType &result)
{//ģ��������ɾ���������K������Ԫ��
	if(k<1 || first == -1)   return false;
	int currentptr = first;
	if(k==1)
		first = SimSpace.node[first].link;
	else
	{//��qָ���k������ֱ��ǰ��
		int q = first;
		for(int index = 1; index<k-1 && q != -1; index++)
			//���ҵ�k-1�����
			q = SimSpace.node[q].link;
		if(q==-1 || SimSpace.node[q].link == -1)         //�ж��Ƿ���ڵ�k�����
			return false;
		currentptr = SimSpace.node[q].link;
		SimSpace.node[q].link = SimSpace.node[currentptr].link;   //ɾ����k�����
	}
	result = SimSpace.node[currentptr].data;
	SimSpace.DeleteNodeSimulationChainSpace(currentptr);
	//����ɾ�����ռ���뵽ģ������ռ���
	return true;
}


void SimulationChainList::
DisplaySimulationChainList(SimulationChainList &Applist)
{
	int currentptr = first;	
	cout<<"\n\n";
	cout<<" ����������������������������������"<<endl;
	cout<<" ��     ѧ����    ��"<<endl;
	cout<<" �������������������Щ�������������"<<endl;
	cout<<" ��        ��      ��"<<endl;
	cout<<" ��ѧ �ũ���  ����"<<endl;
	cout<<" ��������������������"<<endl;
	cout<<" ��������������-���੤������������"<<endl;

	for (int i = 1; i <= Applist.LengthSimulationChainList(); i++)
	{
		cout<<" ��"<<SimSpace.node[currentptr].data.number;  
		cout<<" ��"<<SimSpace.node[currentptr].data.name;
		cout<<"�� "<<SimSpace.node[currentptr].data.sex;
		cout<<"     ��    "<<SimSpace.node[currentptr].data.age<<"��"<<endl;
		cout<<" �������������������੤������������"<<endl;
		currentptr = SimSpace.node[currentptr].link;  
	}
	
	cout<<endl<<endl<<endl;
}



void SimulationChainList::
DisplayElementSimulationChainList(ElementType &result)
{
	cout<<"ѧ����"<<result.number<<"    ";
	cout<<"������"<<result.name<<"    ";
	cout<<"�Ա���"<<result.sex<<"    ";
	cout<<"������"<<result.age<<endl;
}
