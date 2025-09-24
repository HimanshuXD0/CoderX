// Check if given Linked List is Plaindrome
// https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/
// --> center m jake age ki list ko reverse kr denge 
// --> fr match krnge dono adhe ko 
// Revision Status : 2
// DAY -----6 
#include"himanshu.h"
    
    
Node* reverse(Node* ptr) {
    Node* pre=NULL;
    Node* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}

bool isPalindrome(Node* head) {
    if(head==NULL||head->next==NULL) return true;
        
    Node* slow = head;
    Node* fast = head;
        
    while(fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
        
    slow->next = reverse(slow->next);
    slow = slow->next;
    Node* dummy = head;
        
    while(slow!=NULL) {
        if(dummy->data != slow->data) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}


/*    bool isPalindrome(Node *head)
    {
       string s1="",s2="";
       while(head!=NULL){
           string data=to_string(head->data);
           s1=s1+data;
           s2=data+s2;
           head=head->next;
       }
       return s1==s2;
    }
*/
    
int main(){
    Node * head = takelist();
    std::cout<<isPalindrome(head);
    
    return 0;
}