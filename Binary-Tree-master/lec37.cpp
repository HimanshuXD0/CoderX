// Morris Traversal <<NEED PRACTICE ALOT>>
//  https://youtu.be/80Zug6D1_r4


 #include"himanshu.h"

vector < int > inorderTraversal(Node * root) {
  vector < int > inorder;

  Node * cur = root;
  while (cur != NULL) {
    if (cur -> left == NULL) {
      inorder.push_back(cur -> data);
      cur = cur -> right;
    } else {
      Node * prev = cur -> left;
      while (prev -> right != NULL && prev -> right != cur) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = cur;
        cur = cur -> left;
      } else {
        prev -> right = NULL;
        inorder.push_back(cur -> data);
        cur = cur -> right;
      }
    }
  }
  return inorder;
}

int main(){
    Node* root = taketree();
    vector<int> ans;
    ans = inorderTraversal(root);
    for(auto i:ans) 
    cout<<i<<" ";
}