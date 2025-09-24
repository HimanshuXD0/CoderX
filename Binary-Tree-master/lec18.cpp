// two trees identical or not
// https://youtu.be/BhuvF_-PWS0

#include"himanshu.h"

bool isIdentical(Node *p, Node *q)
    {
          if(p == NULL || q == NULL)
            return p == q;
        bool left_value = isIdentical(p->left , q->left);
        bool right_value = isIdentical(p->right , q->right);
        return p->data == q->data && left_value && right_value;
    }

int main(){
    Node* p = taketree();
    Node* q = taketree();
    bool ans=isIdentical(p,q);
    cout<<ans;
    return 0;
}