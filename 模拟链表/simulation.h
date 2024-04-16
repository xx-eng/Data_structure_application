#include "AppData.h"

class SimulationChainNode
{
	public:
		ElementType data;
		int link;
};

		
//template<class ElementType>
class SimulationChainSpace		
{//定义顺序存储结构模拟链表空间类SimulationChainSpace
	
	public:
		friend  class SimulationChainList;       //书上代码错误，好像少了个class ，f**k
		SimulationChainSpace(int MaxSpaceSize=25);  //构造函数
		~SimulationChainSpace(){delete []node;};    //析构函数
		int NewNodeSimulationChainSpace();
		//相当于C++系统的new运算
		void DeleteNodeSimulationChainSpace(int &i);
		//相当于C++系统的delete运算;
	private:
		SimulationChainNode *node;   //指向数组（存储池）的指针
		int MaxSpaceSize;  //存储池的大小
		int availableptr;  //指向存储池链表的第一个结点
};

//template<class ElementType>
SimulationChainSpace::
SimulationChainSpace(int SimSpaceSize)
{//定义顺序存储线性表空间大小MaxSapceSize
	//申请元素空间node，定义长度初值length
	MaxSpaceSize = SimSpaceSize;
	node = new SimulationChainNode[MaxSpaceSize];
	availableptr = 0;
	for(int i=0;i<=MaxSpaceSize-1;i++)
		node[i].link = i+1;
	node[MaxSpaceSize-1].link = -1;
}

//template<class ElementType>
int SimulationChainSpace::
NewNodeSimulationChainSpace()
{//模拟链表分配结点空间，相当于C++系统的new运算
	if(availableptr == -1)   return -1;
	int i = availableptr;
	availableptr = node[i].link;
	return i;
} 

//template<class ElementType>
void SimulationChainSpace::
DeleteNodeSimulationChainSpace(int &i)
{//模拟链表释放结点空间，相当于C++系统的delete运算
	node[i].link = availableptr;
	//释放的i的地址结点的链接域指向可用空间链表的第一个结点
	availableptr = i;
	i = -1;           //i置为不可用值
}

