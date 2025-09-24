// change the tree so that it obey childern sum property by only 
// increment the node value no substraction 
// https://youtu.be/fnmisPM6cVo

#include"himanshu.h"

void ChangeTree(Node* root){

    if(!root) return;
    int child=0;
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;

    if(child>root->data) root->data=child;
    else  {
        if(root->left) {root->left->data = root->data;}
        if(root->right) {root->right->data = root->data;}
      }

      ChangeTree(root->left);
      ChangeTree(root->right);

      int tot=0;
      if(root->left) tot +=root->left->data;   // start backtrack
      if(root->right) tot +=root->right->data;
      if(!isleaf(root)) root->data = tot;
}

int main(){
    Node* root= taketree();
    ChangeTree(root);
    printLevelOrder(root);
}