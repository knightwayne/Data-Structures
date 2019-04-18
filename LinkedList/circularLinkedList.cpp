#include<bits/stdc++.h>
using namespace std;

struct node{
	int n;
	node* link=NULL;
};
void display(node* head)
{
	node* curr=head;
	if(curr==NULL)
	{
		cout<<"Empty\n";
	}
	else
	{
		while(1)
		{
			cout<<curr<<" "<<curr->n<<" "<<curr->link<<endl;
			curr=curr->link;
			
			if(curr==head)
			break;
		}
		cout<<endl;
	}
}

void insertBegin(node* *head)
{
	int n;
	cin>>n;
	node* temp = new node();
	temp->n=n;	temp->link=NULL;
	if(*head==NULL)
	{
		*head=temp;
		(*head)->link=*head;
	}
	else
	{
		temp->link=*head;
		node* curr=*head;
		while(curr->link!=*head)
		curr=curr->link;
		
		curr->link=temp;
		*head=temp;	//or *head->curr->link
	}	
	display(*head);
}
void insertEnd(node* *head)
{
	int n;
	cin>>n;
	node* temp = new node();
	temp->n=n;	temp->link=NULL;
	if(*head==NULL)
	{
		*head=temp;
		(*head)->link=*head;
	}
	else
	{
		temp->link=*head;
		node* curr=*head;
		while(curr->link!=*head)
		curr=curr->link;
		
		curr->link=temp;
	}	
	display(*head);
} 
void deleteBegin(node* *head)
{
	if(*head==NULL)
	{
		cout<<"Already Empty\n";
		return;	
	}
	else
	{
		if(*head==(*head)->link)
		{
			node* curr=*head;
			*head=NULL;
			delete curr;
		}
		else
		{
			node* curr=*head;		//for deleting
			node* next=(*head)->link;
			while(next->link!=*head)
			next=next->link;
			
			next->link=(*head)->link;
			*head=(*head)->link;
			delete curr;		
		}
		
	}
	display(*head);
}
void deleteEnd(node* *head)
{
	if(*head==NULL)
	{
		cout<<"Already Empty\n";
		return;	
	}
	else
	{
		if(*head==(*head)->link)
		{
			node* curr=*head;
			*head=NULL;
			delete curr;
		}
		else
		{
			node* curr=*head;	
			node* next=(*head)->link; //for deleting
			while(next->link!=*head)
			{
				curr=next;
				next=next->link;
			}
			curr->link=*head;
			delete next; 
		}	
	}
	display(*head);
}

int main()
{
	node* head=NULL;
	int i=10;
	while(i--){
		insertEnd(&head);
	}
	i=40;
	while(i--){
		deleteEnd(&head);
	}
}


//inserting at beginning and end is same, except 
//for that we have to shift *head position in
//accordance with specified conditions
//Also, neither am I going to read this ever again,
//and nor am I going to understand this comment, if
//I am brave enough to re-read it. - @nightwayne

