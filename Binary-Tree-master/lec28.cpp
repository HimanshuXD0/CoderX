//  Maximum Width of Binary Tree
//https://youtu.be/ZbybYvcVLks

// this code will calculate also null node 

#include "himanshu.h"

int getMaxWidth(Node *root)
{
      if(!root) return 0;
  int ans=0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int mini = q.front().second; // to make id starting with 0
        int first,last;
        for(int i=0;i<size;i++){
            int curr_id = q.front().second-mini; // - the mini index to prevent overflow
            Node* root = q.front().first;
            q.pop();
            if(i==0) first=curr_id;
            if(i==size-1) last = curr_id;
            if(root->left) q.push({root->left,curr_id*2+1});
            if(root->right) q.push({root->right,curr_id*2+2});

        }
        ans = max(ans,last-first+1);
}
}

// this will only calulate the non null nodes

int WidthOfBT(Node* root) {
        int ans=0;
         if(!root) return 0;
         queue<Node*> q;
         q.push(root);
         while(!q.empty()){
             int n = q.size();
                 ans=max(ans,n);
             for(int i=0;i<n;i++){
                 Node* root = q.front();
                 q.pop();
                 if(root->left) q.push(root->left);
                 if(root->right) q.push(root->right);
             }
         }
         return ans;
    }

    int main () {

        Node* root = taketree();
        int ans = getMaxWidth(root);
        int ans2 = WidthOfBT(root);

        cout<<" maximum "<<ans;
        cout<< "actual " <<ans2;
  
    }