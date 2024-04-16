
#include <iostream>
using namespace std;


template<class ElementType>
class  Sort
{
	public:
		Sort(int MaxSize = 30);    //���캯��
		~Sort() {delete [] element;};      //��������
		void InsertElementSort(ElementType &newvalue); //���뺯��������ñ�
		void DisplaySort();     //��ʾApp������
		int Partition(int low,int high,char j);     //������element[low ����high]��Χ����һ�ο�������
		void Qsort(int low,int high,char j);     //������element[low ����high]��Χ���п�������
		void QuickSort(char j);  //j��ȷ�����ĸ�����
		
	private:
		int MaxSortSize;
		ElementType *element;
		int length;
};


template<class ElementType>
Sort<ElementType>::
Sort(int MaxSize)
{
	MaxSortSize = MaxSize;
	length = 0;
	element = new ElementType[MaxSortSize];
}

template<class ElementType>
void Sort<ElementType>::
InsertElementSort(ElementType &newvalue)
{
	for (int i = length - 1; i >= 0; i--)		//����������ݺ���
		element[i + 1] = element[i];
	element[0] = newvalue;			//������Ԫ�ز���
	length++;						//˳��洢���Ա��ȼ�1
}


template<class ElementType>
void Sort<ElementType>::
DisplaySort()    //��ʾApp������
{

	cout<<"\n\n";
	cout<<" ��������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<" ��                      ��    ��    ��                 ��"<<endl;
	cout<<" �������������������Щ������������Щ��������������������Щ����������������Щ����������������Щ�����������������"<<endl;
	cout<<" ��        ��      ��          ��        ��        ��        ��"<<endl;
	cout<<" ��ѧ    �ũ��� �� ����������������ݽṹ��������Ʃ�ƽ���ɼ���"<<endl;
	cout<<" ��������������������������    ��������������������������������"<<endl;
	cout<<" �������������������੤�����������੤�������������������੤���������������੤���������������੤����������������"<<endl;

	for (int i = 0; i < length; i++)
	{
		cout<<" ��  "<<element[i].No<<"  �� "<<element[i].Name<<" ��   "<<element[i].CPMark<<"     ��    "<<element[i].DSMark
			<<"  ��  "<<element[i].PGMark<<"    ��   "<<element[i].Average<<"   ��"<<endl;
		cout<<" �������������������੤�����������੤�������������������੤���������������੤���������������੤����������������"<<endl;
	}
	//cout<<" ��                ��            ��                    ��                ��                ��                ��"<<endl;
//	cout<<" �������������������ة������������ة��������������������ة����������������ة����������������ة�����������������"<<endl;
}

template<class ElementType>
int Sort<ElementType>::
Partition(int low,int high,char j)
{//������element[low����high]��Χ�����ݽ���һ�ο�������
	//��������Χ�����ݰ���׼Ԫ�أ������ź�Ԫ�أ�λ�û���Ϊ������������
	//�󲿷�С�ڱ�׼Ԫ�أ������ź�Ԫ�أ����ұߴ��ڱ�׼Ԫ��
	int StandardKey;
	ElementType temp;
	temp = element[low];//������������Ԫ�أ���׼Ԫ�أ���ŵ��м䵥Ԫtemp,���������մ��λ��
	switch (j)
	{
		case'2':
			{
				StandardKey = element[low].CPMark;  //���������Ԫ�ر�׼Ԫ�ش�ŵ��м䵥Ԫtemp�����������մ��λ��
				while(low<high)
				{//������[low����high]��Χ�����ݴ����߽�������м���temp�Ƚ�
					while(low<high && element[high].CPMark >= StandardKey)
					//temp��high��low����Ƚ�,ֱ��temp���ڱȽ϶���
						high--;
					if(low<high)
						element[low++] = element[high];  //����׼Ԫ����ǰ��
					while(low<high && element[low].CPMark <= StandardKey)
						//��low��high����Ƚϣ�ֱ��tempС�ڱȽ϶���
						low++;
					if(low<high)
						element[high--] = element[low];  //�����ڱ�׼Ԫ��temp�����������
				}
				element[low] = temp;
				return low;
				break;
			}

		case'3':
			{
				StandardKey = element[low].DSMark;  //���������Ԫ�ر�׼Ԫ�ش�ŵ��м䵥Ԫtemp�����������մ��λ��
				while(low<high)
				{//������[low����high]��Χ�����ݴ����߽�������м���temp�Ƚ�
					while(low<high && element[high].DSMark >= StandardKey)
					//temp��high��low����Ƚ�,ֱ��temp���ڱȽ϶���
						high--;
					if(low<high)
						element[low++] = element[high];  //����׼Ԫ����ǰ��
					while(low<high && element[low].DSMark <= StandardKey)
						//��low��high����Ƚϣ�ֱ��tempС�ڱȽ϶���
						low++;
					if(low<high)
						element[high--] = element[low];  //�����ڱ�׼Ԫ��temp�����������
				}
				element[low] = temp;
				return low;
				break;
			}

		case'4':
			{
				StandardKey = element[low].PGMark;  //���������Ԫ�ر�׼Ԫ�ش�ŵ��м䵥Ԫtemp�����������մ��λ��
				while(low<high)
				{//������[low����high]��Χ�����ݴ����߽�������м���temp�Ƚ�
					while(low<high && element[high].PGMark >= StandardKey)
					//temp��high��low����Ƚ�,ֱ��temp���ڱȽ϶���
						high--;
					if(low<high)
						element[low++] = element[high];  //����׼Ԫ����ǰ��
					while(low<high && element[low].PGMark <= StandardKey)
						//��low��high����Ƚϣ�ֱ��tempС�ڱȽ϶���
						low++;
					if(low<high)
						element[high--] = element[low];  //�����ڱ�׼Ԫ��temp�����������
				}
				element[low] = temp;
				return low;
				break;
			}

		case'5':
			{
				StandardKey = element[low].Average;  //���������Ԫ�ر�׼Ԫ�ش�ŵ��м䵥Ԫtemp�����������մ��λ��
				while(low<high)
				{//������[low����high]��Χ�����ݴ����߽�������м���temp�Ƚ�
					while(low<high && element[high].Average >= StandardKey)
					//temp��high��low����Ƚ�,ֱ��temp���ڱȽ϶���
						high--;
					if(low<high)
						element[low++] = element[high];  //����׼Ԫ����ǰ��
					while(low<high && element[low].Average <= StandardKey)
						//��low��high����Ƚϣ�ֱ��tempС�ڱȽ϶���
						low++;
					if(low<high)
						element[high--] = element[low];  //�����ڱ�׼Ԫ��temp�����������
				}
				element[low] = temp;
				return low;
				break;
			}
	}
}


template<class ElementType>
void Sort<ElementType>::
Qsort(int low,int high,char j)
{//��element[low����high]���п�������
	int StandardLocation;
	if(low<high)
	{
		StandardLocation = Partition(low,high,j);
		Qsort(low,StandardLocation-1,j);
		Qsort(StandardLocation+1,high,j);
	}
}

template<class ElementType>
void Sort<ElementType>::
QuickSort(char j)
{
	Qsort(0,length-1,j);
}
