#include<iostream>
using namespace std;

template<class Type>
class Comp
{
	public:
		static bool Prior(Type a,Type b);
		static void Swap(Type num[],int a, int b);
};


template<class Type>
bool Comp<Type>::Prior(Type a,Type b)
{
	if(a<b)
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
void Gselsort(Type num[],int n,int incr)
{
	for(int i=incr;i<n;i+=incr)
	{
		for(int j=i;j>=incr&&Comp::Prior(num[j],num[j-incr]);j-=incr)
		{
			Comp::Swap(num,j,j-incr);
		}
	}
}


template<class Type,class Comp>
void shellsort(Type num[],int n)
{
	for(int i=n/2;i>=2;i/=2)
	{
		for(int j=0;j<i;j++)
		{
			Gselsort<Type,Comp>(&num[j],n-j,i);
		}
	}
	Gselsort<Type,Comp>(num,n,1);
}




int main(void)
{
	int num[16]={59,20,17,13,28,14,23,83,36,98,11,70,65,41,42,15};
	shellsort<int,Comp<int> >(num,16);
	for(int i=0;i<16;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}



























