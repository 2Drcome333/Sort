#include<iostream>
using namespace std;


class Comp
{
	public:
		static bool Prior(int a,int b);
		static void Swap(int num[],int a,int b);
};

bool Comp::Prior(int a,int b)
{
	if(a<b)
	{
		return true;
	}
	return false;
}

void Comp::Swap(int num[],int a,int b)
{
	int temp=num[a];
	num[a]=num[b];
	num[b]=temp;
}



/*
template<class Comp>
void insert(int num[],int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=i;j>=1&&Comp::Prior(num[j],num[j-1]);j--)
		{
			Comp::Swap(num,j,j-1);
		}
	}
}


int main(void)
{
	int num[5]={5,4,3,2,1};
	insert<Comp>(num,5);
	for(int i=0;i<5;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}

*/


/*
template<class Comp>
void Bubble(int num[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(Comp::Prior(num[j],num[j-1]))
			{
				Comp::Swap(num,j,j-1);
			}
		}
	}
}




int main(void)
{
	int num[5]={5,4,3,2,1};
	Bubble<Comp>(num,5);
	for(int i=0;i<5;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}

*/



/*
template<class Comp>
void Select(int num[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int lowindex=i;
		for(int j=n-1;j>i;j--)
		{
			if(Comp::Prior(num[j],num[lowindex]))
			{
				lowindex=j;
			}
		}
		Comp::Swap(num,lowindex,i);
	}
}



int main(void)
{
	int num[5]={5,4,3,2,1};
	Select<Comp>(num,5);
	for(int i=0;i<5;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}

*/



template<class Comp>
void insertwithincr(int num[],int n,int incr)
{
	for(int i=incr;i<n;i+=incr)
	{
		for(int j=i;j>=incr&&Comp::Prior(num[j],num[j-incr]);j-=incr)
		{
			Comp::Swap(num,j,j-incr);
		}
	}
}


/*
template<class Comp>
void shellsort(int num[],int n)
{
	for(int i=n/2;i>=2;i/=2)
	{
		for(int j=0;j<i;j++)
		{
			insertwithincr<Comp>(&num[j],n-j,i);
		}
	}
	insertwithcurr<Comp>(num,n,1);
}

int main(void)
{
	int num[5]={5,4,3,2,1};
	shellsort<Comp>(num,5);
	for(int i=0;i<5;i++)
	{
		cout<<num[i]<<endl;
	}
}

*/


/*

template<class Type>
void Merge(int num[],int temp[],int left,int right)
{
	if(right<=left)
	{
		return ;
	}
	int mid=(left+right)/2;
	Merge<Comp>(num,temp,left,mid);
	Merge<Comp>(num,temp,mid+1,right);
	for(int i=left;i<=right;i++)
	{
		temp[i]=num[i];
	}
	int i1=left,i2=mid+1;
	for(int k=left;k<=right;k++)
	{
		if(i1>=mid+1)
		{
			num[k]=temp[i2++];
		}
		else if(i2>right)
		{
			num[k]=temp[i1++];
		}
		else if(Comp::Prior(temp[i1],temp[i2]))
		{
			num[k]=temp[i1++];
		}
		else
		{
			num[k]=temp[i2++];
		}
	}
}




int main(void)
{
	int num[5]={5,4,3,2,1};
	int temp[5];
	Merge<Comp>(num,temp,0,4);
	for(int i=0;i<5;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}

*/



/*

template<class Comp>
void Mergebetter(int num[],int temp[],int left,int right)
{
	if(left>=right)
	{
		return ;
	}
	int mid=(left+right)/2;
	Mergebetter<Comp>(num,temp,left,mid);
	Mergebetter<Comp>(num,temp,mid+1,right);
	for(int i=left;i<=mid;i++)
	{
		temp[i]=num[i];
	}
	for(int j=1;j<=right-mid;j++)
	{
		temp[right-j+1]=num[mid+j];
	}
	for(int i=left,j=right,k=left;k<=right;k++)
	{
		if(Comp::Prior(temp[i],temp[j]))
		{
			num[k]=temp[i++];
		}
		else
		{
			num[k]=temp[j--];
		}
	}
}





int main(void)
{
	int num[5]={5,4,3,2,1};
	int temp[5];
	Mergebetter<Comp>(num,temp,0,4);
	for(int i=0;i<5;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}

*/


/*
int findpivot(int left,int right)
{
	return (left+right)/2;
}
template<class Comp>
int partition(int num[],int left,int right,int pivotnum)
{
	do
	{
		while(Comp::Prior(num[++left],pivotnum));
		while(right>left&&Comp::Prior(pivotnum,num[--right]));
		Comp::Swap(num,left,right);
	}while(right>left);
	return left;
}

template<class Comp>
void quicksort(int num[],int left,int right)
{
	if(left>=right)
	{
		return ;
	}
	int pivot=findpivot(left,right);
	Comp::Swap(num,pivot,right);
	int k=partition<Comp>(num,left-1,right,num[right]);
	Comp::Swap(num,k,right);
	quicksort<Comp>(num,left,k-1);
	quicksort<Comp>(num,k+1,right);
}


int main(void)
{
	int num[5]={5,4,3,2,1};
	quicksort<Comp>(num,0,4);
	for(int i=0;i<5;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}


*/



/*

template<class Comp>
class maxHeap
{
	private:
		int* heap;
		int currSize;
		void siftdown(int num);
	public:
		maxHeap(int num[],int size);
		void buildheap();
		void removeFirst();
		int leftchild(int num);
		int rightchild(int num);
		int parent(int num);
		bool isLeaf(int num);
		int Length();
};

template<class Comp>
void maxHeap<Comp>::siftdown(int num)
{
	if(isLeaf(num))
	{
		return;
	}
	int left=leftchild(num);
	int right=rightchild(num);
	if(right<currSize&&Comp::Prior(heap[left],heap[right]))
	{
		left=right;
	}
	if(Comp::Prior(heap[left],heap[num]))
	{
		return;
	}
	Comp::Swap(heap,num,left);
	num=left;
	siftdown(num);
}

template<class Comp>
maxHeap<Comp>::maxHeap(int num[],int size)
{
	heap=num;
	currSize=size;
	buildheap();
}



template<class Comp>
void maxHeap<Comp>::buildheap()
{
	for(int i=currSize/2-1;i>=0;i--)
	{
		siftdown(i);
	}
}



template<class Comp>
void maxHeap<Comp>::removeFirst()
{
	Comp::Swap(heap,0,--currSize);
	siftdown(0);
}



template<class Comp>
int maxHeap<Comp>::leftchild(int num)
{
	return 2*num+1;
}



template<class Comp>
int maxHeap<Comp>::rightchild(int num)
{
	return 2*num+2;
}


template<class Comp>
int maxHeap<Comp>::parent(int num)
{
	return (num-1)/2;
}



template<class Comp>
bool maxHeap<Comp>::isLeaf(int num)
{
	if(num<currSize&&leftchild(num)<currSize)
	{
		return false;
	}
	return true;
}


template<class Comp>
int maxHeap<Comp>::Length()
{
	return currSize;
}


template<class Comp>
void Heapsort(int num[],int n)
{
	maxHeap<Comp> heap(num,n);
	for(int i=0;i<n;i++)
	{
		heap.removeFirst();
	}
}



int main(void)
{
	int num[5]={5,4,3,2,1};
	Heapsort<Comp>(num,5);
	for(int i=0;i<5;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}

*/

























