#include<bits/stdc++.h>
using namespace std;

struct node{
	int n;
	node* link;
};

void display(node* head)
{
	node* curr = head;
	if(curr==NULL)
	{
		cout<<"EMPTY\n";
	}
	else
	{
		while(curr!=NULL)
		{
			cout<<curr->n;
			curr=curr->link;
			if(curr)
			cout<<"->";
		}
		cout<<endl;
	}
}

void insertBegin(node* *head)
{
	int n;
	cin>>n;
	node* temp=new node();
	temp->n=n;temp->link=NULL;
	if(*head==NULL)
	{
		*head=temp;
	}
	else
	{
		temp->link=*head;
		*head=temp;
	}
	display(*head);
}
void insertEnd(node* *head)
{
	int n;
	cin>>n;
	node* temp=new node();
	temp->n=n;temp->link=NULL;
	if(*head==NULL)
	{
		*head=temp;
	}
	else
	{
		node* curr = *head;
		while(curr->link!=NULL)
		curr=curr->link;
		
		curr->link=temp;
	}
	display(*head);
}
void insertMiddle(node* *head)
{
	int n,pos;
	cin>>n>>pos;
	node* temp=new node();
	temp->n=n;temp->link=NULL;
	if(pos==1)
	{
		//both are same;
		if(*head==NULL)
		{
			*head=temp;
		}
		else
		{
			temp->link=*head;
			*head=temp;
		}
	}
	else
	{
		if(*head==NULL)
		{
			cout<<"Invalid (Head is empty)\n";
		}
		else
		{
			pos-=2;
			node* curr=*head;
			while(pos--)
			{
				curr=curr->link;
				if(curr==NULL)
				{
					cout<<"Invalid Position\n";
					return;
				}
			}
			temp->link=curr->link;
			curr->link=temp;
		}
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
		node* curr=*head;
		*head=(*head)->link;
		delete curr;
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
		node* curr = *head;
		node* next = (*head)->link;
		if(next==NULL)
		{
			delete curr;
			(*head)=NULL;
		}
		else
		{
			while(next->link!=NULL)
			{
				curr=next;
				next=next->link;
			}
			curr->link=NULL;
			delete next;	
		}
	}
	display(*head);
}
void deleteMiddle(node* *head)
{
	int pos;
	cin>>pos;
	if(*head==NULL)
	{
		cout<<"already empty LL\n";
		return;
	}
	else if(pos==1)
	{
		node* curr=*head;
		*head=(*head)->link;
		delete curr;
	}
	else
	{
		node* curr = *head;
		node* next = (*head)->link;
		if(next==NULL)//ll size = 1, but pos!=1
		{
			cout<<"Invalid Position 1\n";
			return;
		}
		else
		{
			pos-=2;
			while(pos--)
			{
				curr=next;
				next=next->link;
				if(next==NULL)
				{
					cout<<"Invalid Position 2\n";
					return;
				}
			}
			curr->link=next->link;
			//next->link=NULL;
			delete next;	
		}		
	}
	display(*head);
}

int main()
{
	node* head = NULL;
	int i=10;
	while(i--){
		insertBegin(&head);
	}
	//display(head);
	while(1){
		//deleteEnd(&head);
		curr=deleteBegin1(head);
		cout<<"xx\n";
		display(head);
		//display(curr);
	}
	
}
