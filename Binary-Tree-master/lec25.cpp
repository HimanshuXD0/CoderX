// Check for Symmetrical Binary Trees
//https://youtu.be/nKggNAiEpBE

#include"himanshu.h"

bool ans(struct Node* lt,struct Node* rt)
   {

       //if(rt==NULL&&lt==NULL)return true;

       if(rt==NULL||lt==NULL)return rt==lt;
       if(lt->data!=rt->data)return false;


       bool c1=ans(lt->left,rt->right);
       bool c2=ans(lt->right,rt->left);
       return c1&&c2;
   }

   void main()
   { Node* root = taketree();
    if(!root)
    return;
    bool res = ans(root->left,root->right);
    cout<<ans;

   }