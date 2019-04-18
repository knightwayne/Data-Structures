#include<bits/stdc++.h>
using namespace std;

struct node{
	int n;
	node* left=NULL;
	node* right=NULL;
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
			cout<<curr->left<<" ["<<curr->n<<" "<<curr<<"] "<<curr->right<<endl;
			curr=curr->right;
//			if(curr)
//			cout<<"->";
		}
		cout<<endl;
	}
}

void insertBegin(node* *head)
{
	int n;
	cin>>n;
	node* temp=new node();
	temp->n=n;temp->left=NULL;temp->right=NULL;
	if(*head==NULL)
	{
		*head=temp;
	}
	else
	{
		temp->right=*head;
		(*head)->left=temp;
		*head=temp;
	}
	display(*head);
}
void insertEnd(node* *head)
{
	int n;
	cin>>n;
	node* temp=new node();
	temp->n=n;temp->left=NULL;temp->right=NULL;
	if(*head==NULL)
	{
		*head=temp;
	}
	else
	{
		node* curr = *head;
		while(curr->right!=NULL)
		curr=curr->right;
		
		curr->right=temp;
		temp->left=curr;
	}
	display(*head);
}
void insertMiddle(node* *head)
{
	int n,pos;
	cin>>n>>pos;
	node* temp=new node();
	temp->n=n;temp->left=NULL;temp->right=NULL;
	
	if(pos==1)
	{
		if(*head==NULL)
		{
			*head=temp;
		}
		else
		{
			temp->right=*head;
			(*head)->left=temp;
			*head=temp;
		}
	}
	else
	{
		if(*head==NULL)
		{
			cout<<"Invalid (head is empty)\n";
		}
		else
		{
			pos-=2;
			node* curr = *head;
			while(pos--)
			{
				curr=curr->right;
				if(curr==NULL)
				{
					cout<<"Invalid Position\n";
					return;	
				}	
			}
			temp->right=curr->right;
			curr->right=temp;
			temp->left=curr;
			if(temp->right)
			{
				curr=temp->right;
				curr->left=temp;
			}
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
		*head=(*head)->right;
		if(*head)
		(*head)->left=NULL;
		
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
		node* curr=*head;
		node* next=(*head)->right;
		if(next==NULL)
		{
			node* curr=*head;
			*head=NULL;
			delete curr;
		}
		else
		{
			while(next->right!=NULL)
			{
				curr=next;
				next=next->right;
			}
			curr->right=NULL;
			//next->left=NULL;
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
		cout<<"Already Empty\n";
		return;
	}
	else if(pos==1)
	{
		node* curr=*head;
		//cout<<curr<<" "<<*head<<" "<<(*head)->right<<endl;
		*head=(*head)->right;
		//cout<<curr<<" "<<*head<<" "<<(*head)->right<<endl;
		if(*head)
		(*head)->left=NULL;
		
		delete curr;
	}
	else
	{
		node* curr=*head;
		node* next=(*head)->right;
		if(next==NULL)
		{
			cout<<"Invalid Position 1\n";//ll size = 1, pos!=1
		}
		else
		{
			pos-=2;
			while(pos--)
			{
				curr=next;
				next=next->right;
				if(next==NULL)
				{
					cout<<"Invalid Position 2\n";
					return;
				}
			}
			curr->right=next->right;
			if(curr->right)
			{
				(curr->right)->left=curr;
			}
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
	i=50;
	while(i--){
		deleteMiddle(&head);
	}
}
