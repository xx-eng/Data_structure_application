
#include "simulation.h"
#include <iostream>
using namespace std;

//template<class ElementType>


//template<class ElementType>
class SimulationChainList
{//基于模拟链表空间的简单链表
public:
	SimulationChainList(){first = -1;}   //构造函数
	~SimulationChainList(){DestroySimulationChainList();};
	int LengthSimulationChainList() const;  //长度
	void DestroySimulationChainList();   //删除模拟链表
	int GetFirstSimulationChainList() {return first;} //表头结点
	int GetAvailablePtrSimulationChainSpace() {return SimSpace.availableptr;}
	//获取可用空间表头结点指针availableptr
	bool GetElementSimulationChainList(int k,ElementType &result);
	//查找第K个数据元素，存放到result中
	bool SearchElementSimulationChainList(int Searchkey,ElementType &result);
	//查找关键字为Searchkey的数据元素，存放到result中
	bool InsertElementSimulationChainList(int k,ElementType &newvalue);
	//插入值为newvalue的数据元素到第K个元素的后面;
	bool DeleteElementSimulationChainList(int k,ElementType &result);
	//删除第K个元素，其值存放到result中


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
	int currentptr = first;        //简单链表表头指针first
	int len = 0;                   //计数器清零
	while(currentptr != -1)
	{
		currentptr = SimSpace.node[currentptr].link;     //推进指针
		len++;
	}
	return len;
}

//template<class ElementType>
void SimulationChainList::
DestroySimulationChainList()
{//删除所有结点
	int currentptr;
	while(first != -1)
	{
		currentptr = SimSpace.node[first].link;
		SimSpace.DeleteNodeSimulationChainSpace(first);   //调用释放空间运算
		first = currentptr;
	}
}


bool SimulationChainList::
GetElementSimulationChainList(int k,ElementType &result)
{//查找第K个元素
	if(k<0 || GetAvailablePtrSimulationChainSpace() == -1)      return false;
	int currentptr = first;
	for(int index = 1; index<k && currentptr != -1; index++)
		//查找第K个元素
		currentptr = SimSpace.node[currentptr].link;
	if(k>0 && currentptr == -1)  return false;
	if(k)
		result = SimSpace.node[currentptr].data;
}


bool SimulationChainList::
SearchElementSimulationChainList(int Searchkey,ElementType &result)
{//查找学号
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
{//模拟链表空间中 ，第K个元素之后中插入结点元素值newvalue的运算
	if(k<0 || GetAvailablePtrSimulationChainSpace() == -1)      return false;
	int currentptr = first;
	for(int index = 1; index<k && currentptr != -1; index++)
		//查找第K个元素
		currentptr = SimSpace.node[currentptr].link;
	if(k>0 && currentptr == -1)  return false;
	int q = SimSpace.NewNodeSimulationChainSpace();   //获取一个结点空间
	SimSpace.node[q].data = newvalue;
	if(k)
	{//插入在第K个结点之后
		SimSpace.node[q].link = SimSpace.node[currentptr].link;
		SimSpace.node[currentptr].link = q;
	}
	else 
	{//k=0插入在第一个位置，作为链表表首结点
		SimSpace.node[q].link = first;
		first = q;
	}
	return true;
}



bool SimulationChainList::
DeleteElementSimulationChainList(int k,ElementType &result)
{//模拟链表中删除简单链表第K个数据元素
	if(k<1 || first == -1)   return false;
	int currentptr = first;
	if(k==1)
		first = SimSpace.node[first].link;
	else
	{//用q指向第k个结点的直接前驱
		int q = first;
		for(int index = 1; index<k-1 && q != -1; index++)
			//查找第k-1个结点
			q = SimSpace.node[q].link;
		if(q==-1 || SimSpace.node[q].link == -1)         //判断是否存在第k个结点
			return false;
		currentptr = SimSpace.node[q].link;
		SimSpace.node[q].link = SimSpace.node[currentptr].link;   //删除第k个结点
	}
	result = SimSpace.node[currentptr].data;
	SimSpace.DeleteNodeSimulationChainSpace(currentptr);
	//将被删除结点空间加入到模拟链表空间中
	return true;
}


void SimulationChainList::
DisplaySimulationChainList(SimulationChainList &Applist)
{
	int currentptr = first;	
	cout<<"\n\n";
	cout<<" ┌───────────────┐"<<endl;
	cout<<" │     学生表    │"<<endl;
	cout<<" ├────────┬──────┤"<<endl;
	cout<<" │        │      │"<<endl;
	cout<<" │学 号│姓  名│"<<endl;
	cout<<" │　　　　│　　　│"<<endl;
	cout<<" ├──────-─┼──────┤"<<endl;

	for (int i = 1; i <= Applist.LengthSimulationChainList(); i++)
	{
		cout<<" │"<<SimSpace.node[currentptr].data.number;  
		cout<<" │"<<SimSpace.node[currentptr].data.name;
		cout<<"│ "<<SimSpace.node[currentptr].data.sex;
		cout<<"     │    "<<SimSpace.node[currentptr].data.age<<"│"<<endl;
		cout<<" ├────────┼──────┤"<<endl;
		currentptr = SimSpace.node[currentptr].link;  
	}
	
	cout<<endl<<endl<<endl;
}



void SimulationChainList::
DisplayElementSimulationChainList(ElementType &result)
{
	cout<<"学号是"<<result.number<<"    ";
	cout<<"姓名是"<<result.name<<"    ";
	cout<<"性别是"<<result.sex<<"    ";
	cout<<"年龄是"<<result.age<<endl;
}
