// zig zag / spiral traversal of tree
// https://youtu.be/3OXWEdlIGl4
#include"himanshu.h"

  vector < vector < int >> zigzagLevelOrder(Node * root) {
  vector < vector < int >> result;
  if (root == NULL) {
    return result;
  }

  queue < Node * > nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;

  while (!nodesQueue.empty()) {
    int size = nodesQueue.size();
    vector < int > row(size);
    for (int i = 0; i < size; i++) {
      Node * node = nodesQueue.front();
      nodesQueue.pop();

      // find position to fill node's value
      int index = (leftToRight) ? i : (size - 1 - i);

      row[index] = node -> data;
      if (node -> left) {
        nodesQueue.push(node -> left);
      }
      if (node -> right) {
        nodesQueue.push(node -> right);
      }
    }
    // after this level
    leftToRight = !leftToRight;
    result.push_back(row);
  }
  return result;
}


int main(){
    int i, j;
    Node* root = taketree();
    vector < vector < int >> ans;
  ans = zigzagLevelOrder(root);
  cout << "Zig Zag Traversal of Binary Tree" << endl;
  for ( i = 0; i < ans.size(); i++) {
    for ( j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
  }
    return 0;
}
