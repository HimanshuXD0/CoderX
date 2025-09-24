// Bottom view of binary tree
// https://youtu.be/KV4mRzTjlAk

#include "himanshu.h"
list<int> bottomView(Node *root, list<int> &ans)
{
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node *temp = p.first;
        int line = p.second;
        // jo key pe last milega use update krnge
        mp[line] = temp->data;
        if (temp->left)
            q.push({temp->left, line - 1});
        if (temp->right)
            q.push({temp->right, line + 1});
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    Node *root = taketree();
    list<int> ans;
    bottomView(root, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}