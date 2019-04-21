#include<bits/stdc++.h>
using namespace std;

class Stack{
	public:
		int top=-1;
		int size=5;
		int arr[5];
		
		//out of class method 
		void push(int x);
		int pop();
		int peek();
		
		//in class methods
		bool isEmpty(){
			return (top==-1);
		}
		
		bool isFull(){
			return (top==(size-1));
		}
		
		void display(){
			cout<<"Stack:\t";
			if(top==-1){
				cout<<"Empty\n";
				return;	
			}
			for(int i=0;i<=top;i++)
			cout<<arr[i]<<" ";
			cout<<endl;
		}
};

void Stack::push(int x)
{
	if(top!=size-1)
	{
		top++;
		arr[top]=x;
		//arr[++top]=x;
		display();
	}
	else
	cout<<"Stack Overflow\n";
}
int Stack::pop()
{
	if(top!=-1)
	{
		int x = arr[top];
		top--;
		//int x=arr[top--];
		display();
		return x;
	}
	else{
		cout<<"Stack Underflow\n";
		return -1;	
	}
	
}
int Stack::peek()
{
	if(top!=-1)
	{
		int x = arr[top];
		return x;
	}
	else{
		cout<<"Stack Underflow\n";
		return -1;	
	}	
}
int main()
{
	class Stack s;
	int i;
	do{
		cout<<"1.Push\t 2.Pop\t 3.Peek\t 4.isEmpty\t 5.isFull()\t 6.display\n";
		cin>>i;
		switch(i)
		{
			case 1: int x;
					cin>>x;
					s.push(x);
					break;
			case 2: cout<<s.pop()<<endl;
					break;
			case 3: cout<<s.peek()<<endl;
					break;		
			case 4: cout<<s.isEmpty()<<endl; 
					break;
			case 5: cout<<s.isFull()<<endl;
					 break;
			case 6: s.display(); break;
		}
	}while(i);
}
