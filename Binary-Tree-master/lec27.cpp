// Lowest Common Ancestor in Binary Tree
// https://youtu.be/_-QHfMDde90

#include"himanshu.h"

Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==nullptr||root->data==n1||root->data==n2) 
        {return root;}
        
        Node* left = lca(root->left,n1,n2);
        Node* right = lca(root->right,n1,n2);
        
        if(left==nullptr) return right;
        else if(right==nullptr) return left;
        else 
        return root;
    }

    int main(){
        Node* root = taketree();
        int n1,n2;
        cin>>n1>>n2;
        Node* ans = lca(root,n1,n2);
        cout<<" "<<ans->data;
       
    }