
//https://youtu.be/Rezetez59Nk
//Diameter of binary : the longest route passes through every particular node  
// Revision Status : 3
// DAY ----- 6
#include "himanshu.h"

int height(Node* root,int &daimeter){

if(!root) return 0;
  
  int lh= height(root->left,daimeter);
  int rh= height(root->right,daimeter);
  daimeter = max((lh+rh)+1,daimeter);
  return max(lh,rh)+1;
}

int main(){
     Node* root = taketree();
     int daimeter=0;
      height(root,daimeter);
     cout<<daimeter;
    return 0;
}