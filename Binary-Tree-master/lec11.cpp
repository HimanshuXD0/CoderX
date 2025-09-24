// itreative way of post order
//https://youtu.be/2YBhNLodD8Q
// learn : isme phele jo vector m push krte the use ek baar fr  dusre stack m daal lenge fr vector m daal denege 
// Revision status : 3
// Day ----3
#include"himanshu.h"

vector<int> postOrder(Node* node) {
        vector<int> ans;
        stack<Node*> st1;
        stack<Node*> st2;
      st1.push(node);
      while(!st1.empty()){
          Node* root = st1.top();
          st1.pop();
          st2.push(root);
          if(root->left) st1.push(root->left);
          if(root->right) st1.push(root->right);
      }
      
      while(!st2.empty()){
          Node* root2 = st2.top();
          ans.push_back(root2->data);
          st2.pop();
      }
      
      return ans;   
    } 


 
    int main()
{
    Node *root = taketree();
    vector<int> ans;
    ans = postOrder(root);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}