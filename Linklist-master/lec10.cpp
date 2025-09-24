 // Reverse Linked List in groups of Size K
// https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/
// Revision Status : 0
#include"himanshu.h"
    
int lengthOfLinkedList(Node* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}    

Node* reverseKNodes(Node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    
    int length = lengthOfLinkedList(head);
    
    Node* dummyHead = new Node(0);
    dummyHead->next = head;
    
    Node* pre = dummyHead;
    Node* cur;
    Node* nex;
    
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
     head = dummyHead->next;
}
    
int main(){

    Node* head = takelist();
    Node* ans = reverseKNodes(head,3);
    while(ans){
        std::cout<<ans->data<<" ";
        ans= ans->next;
    }

    
    return 0;
}