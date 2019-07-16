#include<bits/stdc++.h>
using namespace std;
//Queue Array Class Implementation

class Queue{
	public:
		int frontP=0;
		int rearP=0;
		int size=5;
		int arr[5];
		
		//out of class method 
		void enqueue(int x);
		int dequeue();
		int front();
		int rear();
		
		//in class methods
		bool isEmpty(){
			return (frontP==rearP);
		}
		
		bool isFull(){
			return (frontP==size);
		}
		
		void display(){
			cout<<"Queue:\t";
			if(frontP<=rearP){
				cout<<"Empty\n";
				return;	
			}
			for(int i=rearP;i<frontP;i++)
			cout<<arr[i]<<" ";
			cout<<endl;
		}
};

void Queue::enqueue(int x)
{
	if(frontP<size)
	{
		arr[frontP]=x;
		frontP++;
		//arr[frontP++]=x;
		display();
	}
	else
	cout<<"Queue Overflow\n";
}
int Queue::dequeue()
{
	if(rearP<frontP)
	{
		int x = arr[rearP];
		arr[rearP]=-1;
		rearP++;
		//int x=arr[rearP++];
		display();
		return x;
	}
	else{
		cout<<"Queue Underflow\n";
		return -1;	
	}
}
int Queue::front()
{
	if(frontP>rearP)
	{
		//rearP--;
		int x = arr[rearP];
		//rearP++;
		return x;
	}
	else{
		cout<<"Queue Underflow\n";
		return -1;	
	}		
}
int Queue::rear()
{
	if(frontP>rearP)
	{
		frontP--;
		int x = arr[frontP];
		frontP++;
		return x;
	}
	else{
		cout<<"Queue Underflow\n";
		return -1;	
	}
}
int main()
{
	class Queue s;
	int i;
	do{
		cout<<"1.Enqueue\t 2.Dequeue\t 3.Front\t 4.Rear\t 5.isEmpty\t 6.isFull\t 7.display\n";
		cin>>i;
		switch(i)
		{
			case 1: int x;
					cin>>x;
					s.enqueue(x);
					break;
			case 2: cout<<s.dequeue()<<endl;
					break;
			case 3: cout<<s.front()<<endl;
					break;
			case 4: cout<<s.rear()<<endl;
					break;				
			case 5: cout<<s.isEmpty()<<endl; 
					break;
			case 6: cout<<s.isFull()<<endl;
					 break;
			case 7: s.display(); break;
		}
	}while(i);
}
