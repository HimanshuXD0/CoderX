
// Serialize and De-serialize Binary Tree
// https://youtu.be/-YbXySKJsX8

#include "himanshu.h"

vector<int> serialize(Node *root)

{
    vector<int> v;
    if (!root)
        return v;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curNode = q.front();

        q.pop();

        if (curNode == NULL)  v.push_back(-1);
        else
            v.push_back(curNode->data);

        if (curNode != NULL)
        {
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }

    return v;
}

Node *deSerialize(vector<int> &A)

{
    
   if(A.size() == 0) return NULL; 
        int i=0;
        queue<Node*> q;
        Node* root=newNode(A[i++]);
        q.push(root);

        while(!q.empty()){

            Node* t=q.front(); q.pop();

            if(A[i]==-1)  t->left=NULL;
            
            else {

                Node* tmp=newNode(A[i]);
                t->left=tmp;
                q.push(tmp);
            }

            i++; 
           
            if(A[i]==-1) t->right=NULL;

            else {

                Node* tmp=newNode(A[i]);
                t->right=tmp;
                q.push(tmp);
            }
            
            i++;

        }

        return root; 

}