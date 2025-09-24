// Flatten a Binary Tree to Linked List
// https://youtu.be/sWf7k1x9XR4


#include"himanshu.h"

void flatten(Node *root)
    {
       Node* current=root;
        while (current != NULL){
            if (current->left){
                Node* pred = current->left;
                while (pred->right) 
                pred = pred->right;
                
                pred->right = current->right;
                current->right = current->left;
                current->left = NULL;
            }
            current = current->right;
        }
    }

// void flatten(Node *root)
//     {
//        stack<Node*> st;
//        st.push(root);
//        while(!st.empty()){
//            Node* curr = st.top();
//            st.pop();
//            if(curr->right) st.push(curr->right);
//            if(curr->left) st.push(curr->left);
//            if(!st.empty()){
//                curr->right=st.top();
//                curr->left =nullptr;
//            }
          
//        }
//     }


    int main(){
        Node* root = taketree();
        flatten(root);
        while(!root){
            cout<<root->data<<" ";
            root=root->left;
        }
    }