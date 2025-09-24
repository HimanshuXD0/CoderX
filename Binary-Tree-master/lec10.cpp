
// iteretive way of inorder
// https://youtu.be/lxTGsVXjwvM
// Revision status : 2;
// DAY --- 2
#include "himanshu.h"
using namespace std;

vector<int> inorder(Node *root){
    Node *curr = root;
    stack<Node *> s;
    vector<int> ans;
    while (true)
    {
        if (curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        else {
             if (s.empty())  break;
             curr = s.top();
              s.pop();
             ans.push_back(curr->data);
             curr = curr->right;
        }
    }

    return ans;
}



int main()
{
    Node *root = taketree();
    vector<int> ans;
    ans = inorder(root);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}