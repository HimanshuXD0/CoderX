// Rotate a Linked List
//https://takeuforward.org/data-structure/rotate-a-linked-list/
// Revision Status : 1
#include"himanshu.h"
    
    
Node* rotate(Node* &head, int k){

        Node* temp = head;

        while(temp->next)  temp = temp->next;  
        
        temp->next = head;     // got circular 
        
        while(k--)  temp = temp->next;
        
        head = temp->next;
        temp->next = NULL;
        
        return head;
    }
    
int main(){

    Node* head = takelist();
    rotate(head,3);
    while(head) {
        std::cout<<head->data<<" ";
        head=head->next;
    }
    
    return 0;
}