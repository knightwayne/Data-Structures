#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};
void modify(node* head)
{
	head->data=45;
	node* temp = new node();
	temp->data=10;
	head->left=temp;
}
int main()
{
	node* head=NULL;
	node* temp = new node();
	temp->data=10;
	head=temp;
	modify(head);
	cout<<head->data<<" "<<head->left->data;
}
