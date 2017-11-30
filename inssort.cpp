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








template<class Type,class Comp>
void inssort(Type num[],int n)
{
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i;j>0&&Comp::Prior(num[j],num[j-1]);j--)
		{
			Comp::Swap(num,j-1,j);
		}
	}
}


int main(void)
{
	int num[5]={5,4,3,2,1};
	inssort<int,Comp<int> >(num,5);
	for(int i=0;i<5;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}















