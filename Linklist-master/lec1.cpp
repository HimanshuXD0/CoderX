// Detect the loop in Linklist 
// (Floyd's cycle-detection algorithm/Tortoise-Hare algorthim)
// https://youtu.be/354J83hX7RI
// Revision status : 3
// DAY -- 1

#include "himanshu.h"

bool detectLoop(Node* head)
    {
        if(!head||!head->next) return false;
        Node* fast = head;
        Node* slow = head;
    
        while(fast->next&&fast->next->next){
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast) return true;
       }
       return false;
    }


int main(){
    Node* head = takelist();
    head->next->next->next->next->next= head->next;   // ex - 1 2 3 4 5 6 7 
    std::cout<<detectLoop(head);
    return 0;
}