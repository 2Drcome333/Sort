#include<iostream>
using namespace std;





template<class Type>
class Comp
{
	public:
		static bool Prior(int a,int b);
		static void Swap(Type num[],int a,int b);
};



template<class Type>
bool Comp<Type>::Prior(int a,int b)
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
void selsort(Type num[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int leastindex=i;
		for(int j=n-1;j>i;j--)
		{
			if(Comp::Prior(num[j],num[leastindex]))
			{
				leastindex=j;
			}
		}
		Comp::Swap(num,i,leastindex);
	}
}



int main(void)
{
	int num[5]={5,4,3,2,1};
	selsort<int,Comp<int> >(num,5);
	for(int i=0;i<5;i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}



















