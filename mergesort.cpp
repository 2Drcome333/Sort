#include<iostream>
using namespace std;



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
	if(left==right)
	{
		return ;
	}
	int mid=(left+right)/2;
	mergesort<Type,Comp>(num,temp,left,mid);
	mergesort<Type,Comp>(num,temp,mid+1,right);
	for(int i=left;i<=right;i++)
	{
		temp[i]=num[i];
	}
	int i1=left,i2=mid+1;
	for(int curr=left;curr<=right;curr++)
	{
		if(i1==mid+1)
		{
			num[curr]=temp[i2++];
		}
		else if(i2>right)
		{
			num[curr]=temp[i1++];
		}
		else if(Comp::Prior(temp[i1],temp[i2]))
		{
			
			num[curr]=temp[i1++];
		}
		else
		{
			num[curr]=temp[i2++];
		}
	}
}



int main(void)
{
	int num[16]={16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int temp[16];
	mergesort<int,Comp<int> >(num,temp,0,15);
	for(int i=0;i<16;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}




























