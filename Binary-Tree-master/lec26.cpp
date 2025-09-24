//Print Root to Node Path in Binary Tree 
//https://youtu.be/fmflMqVOC7k

#include"himanshu.h"

bool getPath(Node * root, vector < int > & arr, int x) {
  if (!root)
    return false;
  arr.push_back(root -> data);
  if (root -> data == x)
    return true;

  if (getPath(root -> left, arr, x) ||
     getPath(root -> right, arr, x))
    return true;

  arr.pop_back();
  return false;
}

int main()
{
    Node* root = taketree();
    int x;
    cin>>x;
    vector<int> arr;
    getPath(root,arr,x);
    
    for(auto i : arr)
    cout<<" "<<i;
    
}