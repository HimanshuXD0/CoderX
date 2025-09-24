// remove the loop in link list 
// https://youtu.be/QfbOhn0WZ88
// learn : in circular ll nodes coloide on head 
// Learn : in first loop take slow backup and in 2nd loop take fast backup
// Revision Status : 4
// DAY -----2
#include "himanshu.h"

    void removeLoop(Node* head)
    {
       Node* slow = head;
       Node* fast = head;
       Node* temp ;
       while(fast->next&&fast->next->next){
           temp=slow; //-> this is for the circular LL...agr sara ll hi circular hai to temp m head se phele wala node store ho jyga 
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast) break;
       }
       if(slow!=fast) return;
       slow=head;
       while(slow!=fast){
           slow=slow->next;
           temp=fast;
           fast=fast->next;
       }
      
       temp->next=NULL;
    }


int main(){
    //  Node* head = new Node(3);
    //  head->next= new Node(5);
    //  head->next->next = new Node(10);
    //  head->next->next->next = new Node(15);
    //  head->next->next->next->next = head->next;

     Node* head = takelist();
     //head->next->next->next->next->next=head->next;
     removeLoop(head);
     while(head){
        std::cout<<head->data<<" ";
        head = head->next;
     }

    return 0;
}