
#include <iostream>
using namespace std;


template<class ElementType>
class  Sort
{
	public:
		Sort(int MaxSize = 30);    //构造函数
		~Sort() {delete [] element;};      //析构函数
		void InsertElementSort(ElementType &newvalue); //插入函数，构造该表
		void DisplaySort();     //显示App中数据
		int Partition(int low,int high,char j);     //对数组element[low ……high]范围进行一次快速排序
		void Qsort(int low,int high,char j);     //对数组element[low ……high]范围进行快速排序
		void QuickSort(char j);  //j是确定用哪个排序
		
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
	for (int i = length - 1; i >= 0; i--)		//插入点后的数据后移
		element[i + 1] = element[i];
	element[0] = newvalue;			//新数据元素插入
	length++;						//顺序存储线性表长度加1
}


template<class ElementType>
void Sort<ElementType>::
DisplaySort()    //显示App中数据
{

	cout<<"\n\n";
	cout<<" ┌─────────────────────────────────────────────────────┐"<<endl;
	cout<<" │                      成    绩    单                 │"<<endl;
	cout<<" ├────────┬──────┬──────────┬────────┬────────┬────────┤"<<endl;
	cout<<" │        │      │          │        │        │        │"<<endl;
	cout<<" │学    号│姓 名 │计算机基础│数据结构│程序设计│平均成绩│"<<endl;
	cout<<" │　　　　│　　　│　　　    │　　　　│　　　　│　　　　│"<<endl;
	cout<<" ├────────┼──────┼──────────┼────────┼────────┼────────┤"<<endl;

	for (int i = 0; i < length; i++)
	{
		cout<<" │  "<<element[i].No<<"  │ "<<element[i].Name<<" │   "<<element[i].CPMark<<"     │    "<<element[i].DSMark
			<<"  │  "<<element[i].PGMark<<"    │   "<<element[i].Average<<"   │"<<endl;
		cout<<" ├────────┼──────┼──────────┼────────┼────────┼────────┤"<<endl;
	}
	//cout<<" │                │            │                    │                │                │                │"<<endl;
//	cout<<" └────────┴──────┴──────────┴────────┴────────┴────────┘"<<endl;
}

template<class ElementType>
int Sort<ElementType>::
Partition(int low,int high,char j)
{//对数组element[low……high]范围的数据进行一次快速排序
	//并将本范围的数据按标准元素（本次排好元素）位置划分为左右两个部分
	//左部分小于标准元素（本次排好元素），右边大于标准元素
	int StandardKey;
	ElementType temp;
	temp = element[low];//将待排序数据元素（标准元素）存放到中间单元temp,查找其最终存放位置
	switch (j)
	{
		case'2':
			{
				StandardKey = element[low].CPMark;  //将待排序的元素标准元素存放到中间单元temp，查找其最终存放位置
				while(low<high)
				{//对数组[low……high]范围的数据从两边交替地向中间与temp比较
					while(low<high && element[high].CPMark >= StandardKey)
					//temp从high向low方向比较,直到temp大于比较对象
						high--;
					if(low<high)
						element[low++] = element[high];  //将标准元素往前放
					while(low<high && element[low].CPMark <= StandardKey)
						//从low向high方向比较，直到temp小于比较对象
						low++;
					if(low<high)
						element[high--] = element[low];  //将大于标准元素temp的数据往后放
				}
				element[low] = temp;
				return low;
				break;
			}

		case'3':
			{
				StandardKey = element[low].DSMark;  //将待排序的元素标准元素存放到中间单元temp，查找其最终存放位置
				while(low<high)
				{//对数组[low……high]范围的数据从两边交替地向中间与temp比较
					while(low<high && element[high].DSMark >= StandardKey)
					//temp从high向low方向比较,直到temp大于比较对象
						high--;
					if(low<high)
						element[low++] = element[high];  //将标准元素往前放
					while(low<high && element[low].DSMark <= StandardKey)
						//从low向high方向比较，直到temp小于比较对象
						low++;
					if(low<high)
						element[high--] = element[low];  //将大于标准元素temp的数据往后放
				}
				element[low] = temp;
				return low;
				break;
			}

		case'4':
			{
				StandardKey = element[low].PGMark;  //将待排序的元素标准元素存放到中间单元temp，查找其最终存放位置
				while(low<high)
				{//对数组[low……high]范围的数据从两边交替地向中间与temp比较
					while(low<high && element[high].PGMark >= StandardKey)
					//temp从high向low方向比较,直到temp大于比较对象
						high--;
					if(low<high)
						element[low++] = element[high];  //将标准元素往前放
					while(low<high && element[low].PGMark <= StandardKey)
						//从low向high方向比较，直到temp小于比较对象
						low++;
					if(low<high)
						element[high--] = element[low];  //将大于标准元素temp的数据往后放
				}
				element[low] = temp;
				return low;
				break;
			}

		case'5':
			{
				StandardKey = element[low].Average;  //将待排序的元素标准元素存放到中间单元temp，查找其最终存放位置
				while(low<high)
				{//对数组[low……high]范围的数据从两边交替地向中间与temp比较
					while(low<high && element[high].Average >= StandardKey)
					//temp从high向low方向比较,直到temp大于比较对象
						high--;
					if(low<high)
						element[low++] = element[high];  //将标准元素往前放
					while(low<high && element[low].Average <= StandardKey)
						//从low向high方向比较，直到temp小于比较对象
						low++;
					if(low<high)
						element[high--] = element[low];  //将大于标准元素temp的数据往后放
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
{//对element[low……high]进行快速排序
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
