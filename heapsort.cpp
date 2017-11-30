#include<iostream>
using namespace std;
#include<cassert>





template<class Type>
class Comp
{
	public:
		static bool Prior(Type a,Type b);
		static void Swap(Type num[],int a,int b);
};



template<class Type >
bool Comp<Type>::Prior(Type a,Type b)
{
	if(a>b)
	{
		return true;
	}
	return false;
}

template<class Type>
void Comp<Type>::Swap(Type num[],int a,int b)
{
	Type temp=num[a];
	num[a]=num[b];
	num[b]=temp;
}




template<class Type,class Comp>
class Heap
{
	private:
		Type* maxheap;
		int currSize;
		int maxSize;
		void siftdown(int n);
	public:
		Heap(Type E[],int curr,int max=30);
		void buildHeap();
		int leftchild(int n);
		int rightchild(int n);
		bool isLeaf(int n);
		void removeFirst();
};



template<class Type,class Comp>
void Heap<Type,Comp>::siftdown(int n)
{
	assert((currSize!=0,"The heap is empty"));
	while(!isLeaf(n))
	{
		int left=leftchild(n);
		int right=rightchild(n);
		if((right<currSize)&&Comp::Prior(maxheap[right],maxheap[left]))
		{
			left=right;
		}
		if(Comp::Prior(maxheap[n],maxheap[left]))
		{
			return ;
		}
		Comp::Swap(maxheap,n,left);
		n=left;
	}
}





template<class Type,class Comp>
Heap<Type,Comp>::Heap(Type* E,int curr,int max)
{
	maxheap=E;
	currSize=curr;
	maxSize=max;
	buildHeap();
}






template<class Type,class Comp>
void Heap<Type,Comp>::buildHeap()
{
	for(int i=currSize/2-1;i>=0;i--)
	{
		siftdown(i);
	}
}



template<class Type,class Comp>
int Heap<Type,Comp>::leftchild(int n)
{
	return 2*n+1;
}


template<class Type,class Comp>
int Heap<Type,Comp>::rightchild(int n)
{
	return 2*n+2;
}



template<class Type,class Comp>
bool Heap<Type,Comp>::isLeaf(int n)
{
	return n<currSize&&(2*n+1<=currSize)?false:true;
}



template<class Type,class Comp>
void Heap<Type,Comp>::removeFirst()
{
	Comp::Swap(maxheap,0,--currSize);
	if(currSize!=0)
	{
		siftdown(0);
	}
}


template<class Type,class Comp>
void heapsort(Type num[],int n)
{
	Heap<Type,Comp> aheap(num,n);
	for(int i=0;i<n;i++)
	{
		aheap.removeFirst();
	}
}



int main(void)
{
	
	int num[16]={15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
	heapsort<int,Comp<int> >(num,16);
	for(int i=0;i<16;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}


