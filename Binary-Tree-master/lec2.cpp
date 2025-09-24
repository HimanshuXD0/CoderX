
//  https://youtu.be/ctCpP0RFDFc

//  creating a binary tree
//  O(n) time and O(n) space using in stacks recursive calls

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left = right= nullptr;
    }
};

Node* insertLevelOrder(int arr[],
                       int i, int n)
{
      Node *root = nullptr;
    // Base case for recursion
    if (i < n)
    {
        root = new Node(arr[i]);
          
        // insert left child
        root->left = insertLevelOrder(arr,
                   2 * i + 1, n);
  
        // insert right child
        root->right = insertLevelOrder(arr,
                  2 * i + 2, n);
    }
    return root;
}

void printLevelOrder(Node* root,int sum)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    queue<Node*> q;
    int d =0;
    // Enqueue Root and initialize height
    q.push(root);
    sum+=root->data;
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
        
        /* Enqueue left child */
        if (node->left != NULL){
            sum+=node->left->data;
             q.push(node->left);
        }
            
 
        /*Enqueue right child */
        if (node->right != NULL){
            sum+=node->right->data;
            q.push(node->right);
        }
        d++;
    }

    cout<<d;
}


int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = insertLevelOrder(arr, 0, n);
    int sum=0;
    printLevelOrder(root,sum);
    return 0;
}

