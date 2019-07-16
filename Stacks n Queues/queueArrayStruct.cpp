#include<bits/stdc++.h>
using namespace std;
//Queue Array Struct Implementation

struct queueArray{
	int size;
	int front;
	int rear;
	int *arr;
};
void createQueue(queueArray* *q, int size)
{
	(*q)->size=size;
	(*q)->front=-1;
	(*q)->rear=-1;
	(*q)->arr = new int[size];	
}
void display(queueArray *q)
{
	if(q->front<=q->rear)
	cout<<"Queue Empty\n";
	else
	{
		cout<<"Queue: ";
		for(int i=q->rear+1;i<=q->front;i++)
		cout<<q->arr[i]<<" ";
		cout<<endl;	
	}
	
}
void enqueue(queueArray* *q)
{
	if((*q)->front==(*q)->size-1)
	{
		cout<<"Queue Overflow\n";
	}
	else
	{
		int x;
		cin>>x;
		(*q)->front++;
		(*q)->arr[(*q)->front]=x;
		display(*q);
	}
}
int dequeue(queueArray* *q)
{
	if((*q)->front<=(*q)->rear)
	{
		cout<<"Queue Underflow\n";
		return -1;
	}
	else
	{
		(*q)->rear++;
		int x = (*q)->arr[(*q)->rear];
		display(*q);
		return x;
	}
}
void frontPeek(queueArray* *q)
{
	if((*q)->front<=(*q)->rear)
	cout<<"(Peek Rear) Queue Empty\n";
	else
	{
		(*q)->rear++;
		cout<<(*q)->arr[(*q)->rear]<<endl;	
		(*q)->rear--;
	}
}
void rearPeek(queueArray* *q)
{
	if((*q)->front<=(*q)->rear)
	cout<<"(Peek Front) Queue Empty\n";
	else
	cout<<(*q)->arr[(*q)->front]<<endl;
}
bool isEmpty(queueArray* *q)
{
	return ((*q)->front<=(*q)->rear);
}
bool isFull(queueArray* *q)
{
	return ((*q)->front==(*q)->size-1);
}

int main()
{
	int size;
	cin>>size;
	queueArray *q = new queueArray();
	createQueue(&q,size);
	//cout<<s->top<<" "<<s->arr[0]<<" "<<s->arr[4]<<" "<<s->arr[2];
	
	int i;
	do{
		cout<<"1.Enqueue 2.Dequeue 3.Front 4.Rear 5.isEmpty 6.isFull 7.display\n";
		cin>>i;
		switch(i)
		{
			case 1: enqueue(&q);
					break;
			case 2: cout<<dequeue(&q)<<endl;
					break;
			case 3: frontPeek(&q);
					break;
			case 4: rearPeek(&q);
					break;				
			case 5: cout<<isEmpty(&q)<<endl; 
					break;
			case 6: cout<<isFull(&q)<<endl;
					 break;
			case 7: display(q); break;
		}
	}while(i);
	
	return 0;
}
