
template<class  ElementType>
bool InitializeMaxHeap(ElementType heap[],int HeapSize)
{// �Զ��е����ݳ�ʼ��Ϊһ������
	for (int i = HeapSize/2; i >= 1; i--) 
	{//�����һ�����ĸ���ʼ��ֱ����һ�����
		heap[0] = heap[i]; 	// �����������ֵ���Ƶ������ռ�heap[0]��
		int son = 2*i; 		// son����ָ��i������
		while (son <= HeapSize) 
		{// �����Һ����нϴ���
			if (son < HeapSize && heap[son].key < heap[son +1].key)
				son ++;
			// son < HeapSizeʱ�������Һ��ӣ�������С���Һ��ӣ�sonָ���Һ���
			if (heap[0].key >= heap[son].key)
 		// �������빤���ռ��н��ֵ�ٱȽ�
				break; 		//�����ռ���ֵ���ҵ�heap[0]��Ŀ��λ��
			heap[son /2] = heap[son]; 	// ������������˫��λ��
			son *=2;		// son����һ�㵽���ƵĽ�㣨���ӣ�λ��
		}
		heap[son /2] = heap[0];			//heap[0]��ŵ�Ŀ��λ��
	}
	return true;
}

template<class  ElementType>
bool InsertElementMaxHeap( ElementType heap[],int HeapSize,ElementType &newvalue)
{// ����ֵΪx�Ľ�㵽�����У�MaxSize������ռ��������
//	if (HeapSize == MaxSpaceSize)
//		return false;
	int i = ++HeapSize;					//i�ĳ�ֵ��Ϊ��ѵ�Ԫ�ظ���
	while (i != 1 && newvalue.key > heap[i/2].key)	
	{  // Ѱ�� newvalue�Ĳ����
		heap[i] = heap[i/2]; 			// iλ�õ�˫��i/2�������
		i = i / 2;						// iָ��i��˫��i/2λ��,i����
	}
	heap[i] = newvalue;					//newvalue�����ҵ��Ĳ���λ��
	return true;
}

template<class  ElementType>
bool DeleteTopElementMaxHeap (ElementType heap[],int HeapSize,ElementType &result)
{// ɾ�������еĶѶ�
	int  parents,son;
	if (HeapSize == 0)    return false;		//�ѿգ�����
	result = heap[1]; 						//�Ѷ�������ŵ�result����
	heap[0] = heap[HeapSize--]; //���һ������ŵ�heap[0]����������Ԫ�صĸ���
	parents = 1;							//parents����ָ��Ѷ�
	son = 2*parents;						//sonָ��parents������
	while (son <= HeapSize) 
	{
		if (son < HeapSize && heap[son].key < heap[son+1].key) 
			son++;					//����С���Һ��ӣ�son++��ָ���Һ���
		if (heap[0].key >= heap[son].key)	
//��ʱ�ռ�heap[0]��ϴ��ӱȽϣ�����������parentsλ��
			break;   
		heap[parents] = heap[son]; 			//sonλ�õĺ������Ƶ�parentsλ��
		parents = son;             			//����˫�׽��ָ��parents�������Ƚ�
		son = parents * 2;					//sonָ��parents������
	}
	heap[parents] = heap[0];		//��ʱ�ռ�heap[0]���뵽����������λ��
	return true;
}

template<class  ElementType>
void HeapSort(ElementType heap[],int heapsize)
{// ���öѶ�heap[1:heapsize] �����е���������
	ElementType		temp;
	InitializeMaxHeap(heap,heapsize);	//��ʼ��heap[]�е���ȫ������Ϊ����
	for (int i = heapsize-1; i >= 1; i--)	
	{
		DeleteTopElementMaxHeap(heap,i+1,temp);//i+1��ֵΪ��ǰ�ѵĴ�С
		heap[i+1] = temp;		//temp��ɾ���Ѷ����صĶѶ�Ԫ�ز����뵽���
	}
}




