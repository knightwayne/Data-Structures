#include<bits/stdc++.h>
using namespace std;

struct stackArray{
	int top;
	int size;
	int *arr;
};
/*
//Mystackoverflow - all 3 methods to deal with it, difference in C/C++ way of passing
//and in fucntion array and class passing and returning.
One way on Implementation (like 3 way of passing node in functions G4G article)
stackArray* createStack(int size)
{
	stackArray* s = new stackArray();
	s->size=size;
	s->top=-1;
	s->arr = new int[size];
	//s->arr[0]=45;s->arr[1]=4335;s->arr[2]=4115;
	return s;
}*/
void createStack(stackArray* *s, int size)
{
	(*s)->size=size;
	(*s)->top=-1;
	(*s)->arr = new int[size];	
}
void display(stackArray *s)
{
	if(s->top==-1)
	cout<<"Stack Empty\n";
	else
	{
		cout<<"Stack: ";
		for(int i=0;i<=s->top;i++)
		cout<<s->arr[i]<<" ";
		cout<<endl;	
	}
	
}
void push(stackArray* *s)
{
	if((*s)->top==(*s)->size-1)
	{
		cout<<"Stack Overflow\n";
	}
	else
	{
		int x;
		cin>>x;
		(*s)->top++;
		(*s)->arr[(*s)->top]=x;
		display(*s);
	}
}
int pop(stackArray* *s)
{
	if((*s)->top==-1)
	{
		cout<<"Stack Underflow\n";
		return -1;
	}
	else
	{
		int x = (*s)->arr[(*s)->top];
		(*s)->top--;
		display(*s);
		return x;
	}
}
void peek(stackArray* *s)
{
	if((*s)->top==-1)
	cout<<"(Peek) Stack Empty\n";
	else
	cout<<(*s)->arr[(*s)->top]<<endl;
}
bool isEmpty(stackArray* *s)
{
	return ((*s)->top==-1);
}
bool isFull(stackArray* *s)
{
	return ((*s)->top==(*s)->size-1);
}

int main()
{
	int size;
	cin>>size;
	stackArray *s = new stackArray();
	createStack(&s,size);
	//cout<<s->top<<" "<<s->arr[0]<<" "<<s->arr[4]<<" "<<s->arr[2];
	
	int i;
	do{
		cout<<"1.Push 2.Pop 3.Peek 4.isEmpty 5.isFull 6.display\n";
		cin>>i;
		switch(i)
		{
			case 1: push(&s);
					break;
			case 2: cout<<pop(&s)<<endl;
					break;
			case 3: peek(&s);
					break;		
			case 4: cout<<isEmpty(&s)<<endl; 
					break;
			case 5: cout<<isFull(&s)<<endl;
					 break;
			case 6: display(s); break;
		}
	}while(i);
	
	return 0;
}
