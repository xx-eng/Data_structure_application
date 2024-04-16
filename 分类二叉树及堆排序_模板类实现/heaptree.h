
template<class  ElementType>
bool InitializeMaxHeap(ElementType heap[],int HeapSize)
{// 对堆中的数据初始化为一个最大堆
	for (int i = HeapSize/2; i >= 1; i--) 
	{//从最后一个结点的根开始，直到第一个结点
		heap[0] = heap[i]; 	// 将子树根结点值复制到工作空间heap[0]中
		int son = 2*i; 		// son首先指向i的左孩子
		while (son <= HeapSize) 
		{// 找左右孩子中较大结点
			if (son < HeapSize && heap[son].key < heap[son +1].key)
				son ++;
			// son < HeapSize时，存在右孩子，如左孩子小于右孩子，son指向右孩子
			if (heap[0].key >= heap[son].key)
 		// 大孩子再与工作空间中结点值再比较
				break; 		//工作空间中值大，找到heap[0]的目标位置
			heap[son /2] = heap[son]; 	// 将大孩子上移至双亲位置
			son *=2;		// son下移一层到上移的结点（大孩子）位置
		}
		heap[son /2] = heap[0];			//heap[0]存放到目标位置
	}
	return true;
}

template<class  ElementType>
bool InsertElementMaxHeap( ElementType heap[],int HeapSize,ElementType &newvalue)
{// 插入值为x的结点到最大堆中，MaxSize是数组空间最大容量
//	if (HeapSize == MaxSpaceSize)
//		return false;
	int i = ++HeapSize;					//i的初值设为后堆的元素个数
	while (i != 1 && newvalue.key > heap[i/2].key)	
	{  // 寻找 newvalue的插入点
		heap[i] = heap[i/2]; 			// i位置的双亲i/2结点下移
		i = i / 2;						// i指向i的双亲i/2位置,i上移
	}
	heap[i] = newvalue;					//newvalue存入找到的插入位置
	return true;
}

template<class  ElementType>
bool DeleteTopElementMaxHeap (ElementType heap[],int HeapSize,ElementType &result)
{// 删除最大堆中的堆顶
	int  parents,son;
	if (HeapSize == 0)    return false;		//堆空，返回
	result = heap[1]; 						//堆顶最大结点存放到result带出
	heap[0] = heap[HeapSize--]; //最后一个结点存放到heap[0]，调整堆中元素的个数
	parents = 1;							//parents首先指向堆顶
	son = 2*parents;						//son指向parents的左孩子
	while (son <= HeapSize) 
	{
		if (son < HeapSize && heap[son].key < heap[son+1].key) 
			son++;					//左孩子小于右孩子，son++后指向右孩子
		if (heap[0].key >= heap[son].key)	
//临时空间heap[0]与较大孩子比较，大者提升到parents位置
			break;   
		heap[parents] = heap[son]; 			//son位置的孩子上移到parents位置
		parents = son;             			//下移双亲结点指针parents，继续比较
		son = parents * 2;					//son指向parents的左孩子
	}
	heap[parents] = heap[0];		//临时空间heap[0]存入到调整出来的位置
	return true;
}

template<class  ElementType>
void HeapSort(ElementType heap[],int heapsize)
{// 利用堆对heap[1:heapsize] 数组中的数据排序
	ElementType		temp;
	InitializeMaxHeap(heap,heapsize);	//初始化heap[]中的完全二叉树为最大堆
	for (int i = heapsize-1; i >= 1; i--)	
	{
		DeleteTopElementMaxHeap(heap,i+1,temp);//i+1的值为当前堆的大小
		heap[i+1] = temp;		//temp是删除堆顶带回的堆顶元素并存入到最后
	}
}




