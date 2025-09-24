// Ceil in a Binary Search Tree 
// https://youtu.be/KSsk8AhdOZA

#include"himanshu.h"

int findCeil(Node* root, int k) {
   int c = -1;
   while(root){
       if(root->data==k){c=root->data; return c;}
       if(root->data<k) root=root->right;
       else {c=root->data; root=root->left;}   
   }
   return c;    
}

int floor(Node* root, int k) {
    int c = -1;
   while(root){
       if(root->data==k){c=root->data; return c;}
       if(root->data<k) {c=root->data;root=root->right;}
       else {root=root->left;}   
   }
   return c;  
}

int main(){
    Node* root = taketree();
    int c; cin>>c;
    cout<<findCeil(root,c);
}

