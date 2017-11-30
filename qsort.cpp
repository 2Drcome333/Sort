#include<iostream>
using namespace std;

template<class Type>
class Comp
{
	public:
		static bool Prior(Type a,Type b);
		static void Swap(Type num[],int a,int b);
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



int findpivot(int l,int r)
{
	return (l+r)/2;
}


template<class Type,class Comp>
int partition(Type num[],int l,int r,Type pivot)
{
	do
	{
		while(Comp::Prior(num[++l],pivot));
		while((r>l)&&Comp::Prior(pivot,num[--r]));
		Comp::Swap(num,l,r);
	}while(r>l);
	return l;
}


template<class Type,class Comp>
void qsort(Type num[],int l,int r)
{
	if(l>=r)
	{
		return ;
	}
	int pivotindex=findpivot(l,r);
	Comp::Swap(num,pivotindex,r);
	int k=partition<Type,Comp>(num,l-1,r,num[r]);
	Comp::Swap(num,k,r);
	qsort<Type,Comp>(num,l,k-1);
	qsort<Type,Comp>(num,k+1,r);
}





int main(void)
{
	int num[16]={16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	qsort<int,Comp<int> >(num,0,15);
	for(int i=0;i<16;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}



































