
// Tortoise Hare Algorithm 
// https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
// Revision Status : 3
// DAY ---- 4
#include"himanshu.h"


 Node* middleNode(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }

int main(){
    
    Node* head = takelist();
    std::cout<<middleNode(head)->data;
    return 0;
}

