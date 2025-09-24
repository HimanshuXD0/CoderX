// union of linked list
// learn : set stored in sorted order 
// Revision status : 1
#include "himanshu.h"

Node* makeUnion(Node *head1, Node *head2)
{
    set<int> myset;

    while (head1)
    {
        myset.insert(head1->data); // inserting all elements in a set
        head1 = head1->next;
    }

    while (head2)
    {
        myset.insert(head2->data); // inserting all elements in a set
        head2 = head2->next;
    }

    // it=myset.begin();               // it points to first element of set
    Node *union_head = new Node(-1);  // head of union list
    Node *union_tail = union_head;   // tail of union list
    for (auto i : myset)
    {
        union_tail->next = new Node(i);
        union_tail = union_tail->next;
    }

    return union_head->next;
}

int main(){

    Node* head1 = takelist();
    Node* head2 = takelist();
    Node* ans = makeUnion(head1,head2);
    while(ans){
        std::cout<<ans->data<<" ";
        ans= ans->next;
    }

    
    return 0;
}