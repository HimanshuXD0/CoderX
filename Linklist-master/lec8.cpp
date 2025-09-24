// Merge sort on LL
//https://youtu.be/qYgGBRAry9s
// // Revision Status : 1
#include"himanshu.h"
    
    
 Node* Mid(Node* head){
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next != NULL and fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* mergeSortedList(Node *p1, Node *p2){
        if(p1 == NULL or p2 == NULL){
            return (p1==NULL) ? p2 : p1;
        }
        
        Node * ans = new Node(0);
        Node* curr = ans;
        
        while(p1 != NULL and p2 != NULL){
            if(p1->data < p2->data){
                curr->next = p1;
                p1= p1->next;
            }else{
                curr->next = p2;
                p2 = p2->next;
            }
            curr = curr->next;
        }
        

        if(p1 != NULL or p2 != NULL){
            curr->next = (p1 != NULL) ?  p1 : p2;
        }
        return ans->next;
    }
    
    Node* sortList(Node* head) {
        if( head == NULL or head->next == NULL) return head;
        Node* mid = Mid(head);
        Node* newhead = mid->next;
        mid->next = NULL;
        
        Node* left_half = sortList(head);
        Node* right_half = sortList(newhead);
        
        return mergeSortedList(left_half, right_half);
    }
    
int main(){

     Node* head =takelist();
      Node* ans= sortList(head);
      while(ans){
        std::cout<<ans->data<<" ";
        ans= ans->next;
      }
    
    return 0;
}