// Remove Nth Node From End of Linked List 
// https://youtu.be/Lhu3MsXZy-Q
// learn : we always take dummmy start if we want to count head itself 
//         and its better to handel head cases 
// Revision Status : 2
// Day ==--- 3
#include"himanshu.h"

 Node* removeNthFromEnd(Node* head, int n) {
        Node * start = new Node(0);
        start -> next = head;
        Node* fast = start;
        Node* slow = start;     

        for(int i = 1; i <= n; ++i)
        if(fast->next==nullptr) return nullptr;
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next; 
        }
        
        slow->next = slow->next->next;
        return start->next;
        
    }

  void rmn(Node* head, int n){
        if(!head) return ;
        Node* slow=head;
        Node* fast=head;
        Node* temp=NULL;
        while(n--){
            slow=head->next;
        }
        while(slow->next){
           temp=fast;
           fast=fast->next;
           slow=slow->next;
        }

        temp->next=temp->next->next;
        Node* temp2=head;
        while (temp2)
        {
            cout<<temp2->data<<" ";
            temp2=temp2->next;
        }
  }
    

int main(){
    Node* head = takelist();
    // Node* head2=rmn(head,1);
    // cout<<head2->data<<endl;
    // while(head){
    //     std::cout<<head->data<<" ";
    //     head=head->next;
    // }
    rmn(head,5);
    return 0;
}