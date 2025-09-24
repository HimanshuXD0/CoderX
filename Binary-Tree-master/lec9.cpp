//  https://youtu.be/Bfqd8BsPVuw
//  iterative way of preorder
//  Revision status : 2
//  DAY --- 1
#include "himanshu.h"
using namespace std;

vector<int>preorder(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
       root = st.top();
       st.pop();
       ans.push_back(root->data);
       if(root->right) st.push(root->right);  // bcz stack is LIFO 
       if(root->left)  st.push(root->left);  // so we put right first 
    }
    return ans;
}



int main(){
    Node* root = taketree();
    vector<int> ans;
    ans = preorder(root);
    for (int i = 0; i < ans.size(); i++)
        cout << ans [i] << " ";
}