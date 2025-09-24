
// maximum depth of tree
// https://youtu.be/eD3tmO66aBA
// Revision Status : 2
// DAY----4
#include "himanshu.h"

int maxDepth(Node* root) {
        int depth = 0;
        
        if (root == NULL) return depth;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();
                if (temp -> left != NULL) q.push(temp -> left);
                if (temp -> right != NULL) q.push(temp -> right);
            }
        }
        
        return depth;
    }



    vector<int> lvl(Node* root){
        vector<int> ans ;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size= q.size();
            for(int i =0 ;i<size;i++){
                 Node* temp = q.front();
                 q.pop();
                 ans.push_back(temp->data);
                 if(temp->left) q.push(temp->left);
                 if(temp->right) q.push(temp->right);
            }
        }
    }

int depth(Node* root){
    int d=0;
    if(root==nullptr) return -1;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        d++;
        int size = q.size();
        for(int i =0 ;i<size;i++){
          Node* temp = q.front();
          q.pop();
          if(temp->left) q.push(temp->left);
          if(temp->right) q.push(temp->right);
        }
    }
    return d;
}
int main()
{
    Node *root = taketree();
    int ans=depth(root);
    cout<<ans;
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";
}
