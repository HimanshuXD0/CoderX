// Reverse the Link list 
// https://youtu.be/iRtLEoL-r-g
// Revision Status : 2
// DAY ----- 5
#include"himanshu.h"
    
    
Node* reverselist(Node* &head){
     Node* prev = NULL;
     while(head){
        Node* next = head->next;
        head->next=prev;
        prev=head;
        head=next;
     }
     //return newhead;
     head = prev;
}


Node* reverselist2(Node* &head){
     Node* prev = NULL;
     Node* curr = head;
     Node* nextptr;
     while(curr){
        Node* nextptr = curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
     }
     return head = prev;
}
 
int main(){
    
    Node* head = takelist();
   rev(head);
    while(head){
        std::cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}