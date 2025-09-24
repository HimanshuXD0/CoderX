// top view of BT
// https://youtu.be/Et9OCDNvJ78
#include "himanshu.h"
list<int> topView(Node *root, list<int> &ans)
{

    if (!root)
        return ans;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *temp = it.first;
        int line = it.second;
         // if find() does not find the key it is equal to map.end()
        if (mp.find(line) == mp.end()) 
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
    topView(root, ans);
    ans.remove_if([](int n){return (n%2!=0); });
    for (auto i : ans)
    {
        cout << i << " ";
    }

  
}