//Find intersection of Two Linked Lists
//https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
// Revision Status : 1
#include"himanshu.h"
    
    
Node* intersectionPresent(Node* head1,Node* head2) {
    Node* d1 = head1;
    Node* d2 = head2;
    
    while(d1 != d2) {
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    
    return d1;
}

    
int main(){
    
     Node* head1 =takelist();
     Node* head2 =takelist();
     head1->next->next->next=head2->next->next;
     Node* ans= intersectionPresent(head1,head2);
     std::cout<<ans->data;
    
    return 0;
}