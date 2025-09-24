// Minimum time taken to BURN the Binary Tree from a Node
// https://youtu.be/2r5wLmQfD6g


#include"himanshu.h"

Node* MarkParents(Node* root, map<Node*,Node*> &keep_parent, int start) {
    queue<Node*> q; 
    q.push(root); 
    Node* res; 
    while(!q.empty()) {
        Node* node = q.front(); 
        if(node->data == start) res = node; 
        q.pop(); 
        if(node->left) {
            keep_parent[node->left] = node; 
            q.push(node->left); 
        }
        if(node->right) {
            keep_parent[node->right] = node;
            q.push(node->right); 
        }
    }
    return res; 
}


int findMaxDistance(map<Node*, Node*> &keep_parent,Node* target) {
    map<Node*,int> vis; 
    queue<Node*> q; 
    q.push(target); 
    vis[target] = 1;
    int maxi = 0; 
    while(!q.empty()) {
        int sz = q.size();
        int fl = 0; 
        for(int i = 0;i<sz;i++) {
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]) {
                fl = 1; 
                vis[node->left] = 1; 
                q.push(node->left); 
            }
            if(node->right && !vis[node->right]) {
                fl = 1; 
                vis[node->right] = 1; 
                q.push(node->right); 
            }
            
            if(keep_parent[node] && !vis[keep_parent[node]]) {
                fl = 1; 
                vis[keep_parent[node]] = 1; 
                q.push(keep_parent[node]); 
            } 
        }
        if(fl) maxi++; 
    }
    return maxi; 
}

int timeToBurnTree(Node* root, int start)
{
    map<Node*, Node*> keep_parent; 
    Node* target = MarkParents(root, keep_parent, start); 
    int maxi = findMaxDistance(keep_parent, target); 
    return maxi; 
}

    int main(){
        Node* root = taketree();
        int t;
        cin>>t;
        int ans = timeToBurnTree(root,t);
        cout<<" "<<ans;
    }