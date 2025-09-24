// Flattening a Linked List
// https://takeuforward.org/data-structure/flattening-a-linked-list/
// Revision Status : 0
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node *mergetwolist(Node *a,Node*b)
{
   Node* temp = new Node(0);
   Node* res= temp;
   while(a!=NULL&&b!=NULL){
       if(a->data<b->data){
           temp->bottom=a;
           temp=temp->bottom;
           a=a->bottom;
       }
       else
       {
           temp->bottom=b;
           temp=temp->bottom;
           b=b->bottom;
       }
   }
   if(a!=NULL) temp->bottom=a;
   else temp->bottom=b;
   return res->bottom;
}

Node *flatten(Node* root){
    if(root==NULL||root->next==NULL) return root;
    root->next=flatten(root->next);
    root=mergetwolist(root,root->next);
    return root;
}    
    
int main(){

    //Node* head = takelist()

    
    return 0;
}