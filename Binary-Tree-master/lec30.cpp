// Print all the Nodes at a distance of K in Binary Tree
//https://youtu.be/i9ORlEy6EsI

/*
  Mark each node to its parent to traverse upwards
🍋 We will do a BFS traversal starting from the target node
🍋 As long as we have not seen our node previously, Traverse up, left, right until reached Kth distance
🍋 when reached Kth distance, break out of BFS loop and remaining node's values in our queue is our result
*/


#include"himanshu.h"

void markparent(Node* root , unordered_map<Node*,Node*> &keep_parent,int t,Node* &tn ){
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){

    int n = q.size();
    for(int i=0;i<n;i++){
      Node* root = q.front();
      q.pop();
         if(root->data==t) tn=root; //only for getting target node form given key
      if(root->left){
        keep_parent[root->left]=root; //  root k left ka parent root mark kr diya
        q.push(root->left);
      }
      if(root->right){
        keep_parent[root->right]=root; // root k right ka parent root mark kr diya 
        q.push(root->right);
      }
    }
  }
}
    
    
vector<int> KDistanceNodes(Node* root , int target , int k){
      unordered_map<Node*,Node*> Keep_parent ;
      Node* targetN =NULL;
      markparent(root,Keep_parent,target,targetN);  // sare parent aa gye
      unordered_map<Node*,bool> visted;
      queue<Node*> q;
      q.push(targetN);
      visted[targetN] = true;
       int curr_dist=0;
       while(!q.empty()){
        int size = q.size();
         if(curr_dist++ == k) break;
         for(int i=0;i<size;i++){
            Node* curr=q.front();
            q.pop();
            if(curr->left && !visted[curr->left]) {
               q.push(curr->left);
               visted[curr->left]=true;
            }
            if(curr->right && !visted[curr->right]) {
               q.push(curr->right);
               visted[curr->right]=true;
            }
            if(Keep_parent[curr] && !visted[Keep_parent[curr]]) {
               q.push(Keep_parent[curr]);
               visted[Keep_parent[curr]]=true;
            }

         }
       }

       vector<int> ans;
       while(!q.empty()){
          Node* temp = q.front();
          q.pop();
          ans.push_back(temp->data);
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
    


     int main(){
        Node* root = taketree();
        int t =0,k=0;
        cin>>t;
        cin>>k;
        vector<int> ans;
        ans=  KDistanceNodes(root,t,k);
        for(auto i : ans) cout<<" "<<i;
    }