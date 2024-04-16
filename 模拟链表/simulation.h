#include "AppData.h"

class SimulationChainNode
{
	public:
		ElementType data;
		int link;
};

		
//template<class ElementType>
class SimulationChainSpace		
{//����˳��洢�ṹģ������ռ���SimulationChainSpace
	
	public:
		friend  class SimulationChainList;       //���ϴ�����󣬺������˸�class ��f**k
		SimulationChainSpace(int MaxSpaceSize=25);  //���캯��
		~SimulationChainSpace(){delete []node;};    //��������
		int NewNodeSimulationChainSpace();
		//�൱��C++ϵͳ��new����
		void DeleteNodeSimulationChainSpace(int &i);
		//�൱��C++ϵͳ��delete����;
	private:
		SimulationChainNode *node;   //ָ�����飨�洢�أ���ָ��
		int MaxSpaceSize;  //�洢�صĴ�С
		int availableptr;  //ָ��洢������ĵ�һ�����
};

//template<class ElementType>
SimulationChainSpace::
SimulationChainSpace(int SimSpaceSize)
{//����˳��洢���Ա�ռ��СMaxSapceSize
	//����Ԫ�ؿռ�node�����峤�ȳ�ֵlength
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
{//ģ�����������ռ䣬�൱��C++ϵͳ��new����
	if(availableptr == -1)   return -1;
	int i = availableptr;
	availableptr = node[i].link;
	return i;
} 

//template<class ElementType>
void SimulationChainSpace::
DeleteNodeSimulationChainSpace(int &i)
{//ģ�������ͷŽ��ռ䣬�൱��C++ϵͳ��delete����
	node[i].link = availableptr;
	//�ͷŵ�i�ĵ�ַ����������ָ����ÿռ�����ĵ�һ�����
	availableptr = i;
	i = -1;           //i��Ϊ������ֵ
}

