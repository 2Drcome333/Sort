#include<iostream>
using namespace std;


/*****************based on array
void Radix(int A[],int B[],int n,int radix,int bit)
{
	int cnt[radix];
	for(int i=1,rtoi=i;i<=bit;i++,rtoi*=radix)
	{
		for(int i=0;i<radix;i++)
		{
			cnt[i]=0;
		}
		for(int j=0;j<n;j++)
		{
			cnt[(A[j]/rtoi)%radix]++;
		}
		for(int i=1;i<radix;i++)
		{
			cnt[i]=cnt[i]+cnt[i-1];
		}
		for(int j=n-1;j>=0;j--)
		{
			B[--(cnt[(A[j]/rtoi)%radix])]=A[j];
		}
		for(int i=0;i<n;i++)
		{
			A[i]=B[i];
		}
	}
}


int main(void)
{
	int A[5]={25,34,13,62,51};
	int B[5];
	Radix(A,B,5,10,2);
	for(int i=0;i<5;i++)
	{
		cout<<A[i]<<endl;
	}
	return 0;
}

***************************************/


/*based on linkedlist
class Node
{
	public:
		int data;
		Node* next;
		Node(int data,Node* link=NULL);
};


Node::Node(int data,Node* link)
{
	this->data=data;
	next=link;
}



class LinkedList
{
	private:
		Node* head;
		Node* tail;
		int currSize;
	public:
		LinkedList();
		~LinkedList();
		int Length();
		void Append(int data);
		int removeLast();
};


LinkedList::LinkedList()
{
	head=tail=NULL;
	currSize=0;
}


LinkedList::~LinkedList()
{
	if(Length()==0)
	{
		return ;
	}
	Node* temp=head;
	for(int i=0;i<Length();i++)
	{
		head=head->next;
		delete temp;
		temp=head;
	}
}


int LinkedList::Length()
{
	return currSize;
}


void LinkedList::Append(int data)
{
	if(currSize==0)
	{
		head=tail=new Node(data,NULL);
	}
	else
	{
		tail=tail->next=new Node(data,tail->next);
		
	}
	currSize++;
}


int LinkedList::removeLast()
{
	int temp=tail->data;
	if(tail==head)
	{
		delete tail;
		head=tail=NULL;
		currSize--;
		return temp;
	}
	Node* curr=head;
	for(int i=1;i<Length()-1;i++)
	{
		curr=curr->next;
	}
	tail=curr;
	delete curr->next;
	currSize--;
	return temp;
}


template<class LinkedList>
void Radixsort(int A[],int n,int radix,int bit)
{
	LinkedList list[radix];
	for(int i=0,rtoi=1;i<bit;i++,rtoi*=radix)
	{
		for(int j=0;j<n;j++)
		{
			list[(A[j]/rtoi)%radix].Append(A[j]);
		}
		for(int i=radix-1,k=n-1;i>=0;i--)
		{
			while(list[i].Length())
			{
				A[k--]=list[i].removeLast();
				
			}
		}
	}
	
}9



int main(void)
{
	int A[5]={33,82,56,12,59};
	Radixsort<LinkedList>(A,5,10,2);
	for(int i=0;i<5;i++)
	{
		cout<<A[i]<<endl;
	}
}


*/
