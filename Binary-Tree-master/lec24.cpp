// Right view of BT
//https://youtu.be/KV4mRzTjlAk
#include"himanshu.h"
vector<int> rightSideView(Node* root,vector<int> &ans) {
        
        if(!root) return ans;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0;i < size;i++) {
                Node *temp = q.front();
                q.pop();
                if(i == size-1) ans.push_back(temp->data);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }

    int main(){
        Node* root= taketree();
        vector<int> ans;
       rightSideView(root,ans);
        for(auto i : ans){
            cout<<i<<" ";
        }
    }

// what is c++?