//   Segrregate odd and even nodes in LL
// -> even ki link list m add krte jynge even ka node 
// => same with odd 
// -> even k age lga denge odd ki ll 
// Revision Status : 1

#include"himanshu.h"
    
    
    Node* divide(Node *head){
      if(head->next == NULL){
            return head;
        }
        
        Node* odd = new Node(-1);
        Node* even = new Node(-1);
        
        Node* e = even;
        Node* o = odd;
        
        while(head != NULL){
            
            if(head->data%2==0){
                e->next = head;
                e = e->next;
            }
            else{
                o->next = head;
                o = o->next;
            }
            head = head->next;
        }
        o->next = NULL;
        e->next = odd->next;
        return even->next;
        
    }
    
int main(){
      Node* head =takelist();
      Node* ans= divide(head);
      while(ans){
        std::cout<<ans->data<<" ";
        ans= ans->next;
      }
      

    return 0;
}