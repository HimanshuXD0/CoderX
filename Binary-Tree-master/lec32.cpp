// Count total Nodes in a COMPLETE Binary Tree | O(Log^2 N) Approach
//https://youtu.be/u-yWemKGWO0

#include"himanshu.h"

    int findHeightLeft(Node* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->left; 
        }
        return hght; 
    }
    int findHeightRight(Node* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->right; 
        }
        return hght; 
    }
    int countNodes(Node* root) {
        if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) return (1<<lh) - 1; 
        
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }

int main(){
    Node* root =taketree();
    int ans = countNodes(root);
    cout<<ans;
}