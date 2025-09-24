//https://youtu.be/WszrfSwMz58
// Maximum path sum from any node
 #include "himanshu.h"

 int maxpath(Node* root,int &maxi){
        if (!root) return 0;
       int leftsum=max(0,maxpath(root->left,maxi));   
       int rightsum=max(0,maxpath(root->right,maxi));
       maxi= max((leftsum+rightsum+root->data),maxi);
       return max(leftsum,rightsum)+root->data;
    }

    
    int main(){
        Node* root = taketree();
        int maxi=root->data;
        maxpath(root,maxi);
        cout<<maxi;
    }