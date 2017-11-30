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
void mergesort(Type num[],Type temp[],int left,int right)
{
	if(right==left)
	{
		return ;
	}
	int mid=(right+left)/2;
	mergesort<Type,Comp>(num,temp,left,mid);
	mergesort<Type,Comp>(num,temp,mid+1,right);
	for(int i=0;i<=mid;i++)
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
	int num[16]={16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int temp[16];
	mergesort<int,Comp<int> >(num,temp,0,15);
	for(int i=0;i<15;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}





