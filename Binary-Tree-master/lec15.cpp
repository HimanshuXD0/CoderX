// check for Balanced binary tree
//https://youtu.be/Yt50Jfbd8Po

// Revision Status : 2
// DAY ----- 5

#include "himanshu.h"

  int ans=1;
    int  solve(Node*  root)
   {
       if(root==NULL) return 0;
       int l=solve(root->left);
       if(l==-1) ans=0;
       int r=solve(root->right);
       if(r==-1) ans=0;
       if(abs(l-r)>1) ans=0;
       return max(l,r)+1;
   }
   
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
     solve(root);
     return ans;
     
    }
    
    int main(){
        Node* root= taketree();
       isBalanced(root);
       cout<<ans;
        return 0;
    }