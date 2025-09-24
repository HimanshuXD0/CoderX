// Boundary traversal anticlock-wise 
// left boundary + leaves + right boundary
//https://youtu.be/0ca1nvR0be4

#include"himanshu.h"

void addLeftBoundary(Node* root ,vector <int> &res){
 Node* curr = root->left;
  while(curr){
     if(!isleaf(curr)) res.push_back(curr->data);
      if(curr->left) curr = curr->left;
      else curr=curr->right; 
  }
}

void addRightBoundary(Node* root, vector<int> &res){
    Node* curr= root-> right;
    vector<int> temp;
    while(curr){
        if(!isleaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr= curr->left;
    }
    // revresring the vector for maintain anticlock-wise
    for(int i= temp.size()-1;i>=0;--i){
       res.push_back(temp[i]);
    }
}

void addLeaves(Node* root, vector<int> &res){
   if(isleaf(root)){
    res.push_back(root->data);
     return; }
   if(root->left) addLeaves(root->left,res);
   if(root->right) addLeaves(root->right,res);
}

int main(){
    Node* root = taketree();
    vector<int> res;
    if(!root) return 0;
    if(!isleaf(root)) res.push_back(root->data);
    addLeftBoundary(root,res);
    addLeaves(root,res);
    addRightBoundary(root,res);

for(int i=0;i<res.size();i++){
       cout<<res[i]<<" ";
    }
    
}
