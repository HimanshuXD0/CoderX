// Vertical Order Traversal of Binary Tree
// https://youtu.be/q_a6lpbKJdw

#include"himanshu.h"

 vector<int> verticalOrder(Node *root)
    {
       map<int,map<int,vector<int>>> mp;   // mp<vertical,mp<level,set<elements>>>
       queue<pair<Node*,pair<int,int>>> q; // <element<vertical,level>>
       q.push({root,{0,0}});
       while(!q.empty()){
           auto e = q.front();
           q.pop();
           Node* root = e.first;
           int v = e.second.first;
           int l = e.second.second;
           mp[v][l].push_back(root->data);
           if(root->left)
           q.push({root->left,{v-1,l+1}});
           if(root->right)
           q.push({root->right,{v+1,l+1}});
           
       }
       
       vector<int> ans;
      for(auto i:mp){
            for(auto j:i.second){
                for(auto k:j.second)
                    ans.push_back(k);
            }
        }
        return ans;
       
    }
    int main(){
            Node* root = taketree();
             vector<int> ans = verticalOrder(root);
             for(auto e : ans)
              cout<<e<<" ";
         }