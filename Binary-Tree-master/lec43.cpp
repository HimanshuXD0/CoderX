// Insert a given Node in Binary Search Tree
// https://youtu.be/FiFiNvM29ps

#include"himanshu.h"

Node* insert(Node* root, int key) {
    // Your code here
    if(root==nullptr) return newNode(key);
    Node* curr= root;
    while(true){
        if(curr->data==key) return root;
        
        if(key>curr->data){
            if(curr->right) curr=curr->right;
            else { curr->right = newNode(key);
                  break;
            }
        }
        else{
            if(curr->left) curr=curr->left;
            else { curr->left = newNode(key);
                  break;
            }
        }
    }
    return root;
}

int main(){
    Node* root = taketree();
    int c; cin>>c;
    insert(root,c);
    printLevelOrder(root);
}