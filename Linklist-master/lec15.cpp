//ABSOLUTE LIST SORTING 
// https://www.youtube.com/watch?v=ZbB20_pTnes
// Revision Status: 1

#include "himanshu.h"

Node* sortlist(Node* head) {
	    
		Node* curr = head;
		Node* prev = NULL;
		if(curr == NULL) return head;
		while(curr != NULL){
		    
		    
		    if(curr->data < 0 && curr!=head){
		       prev->next = curr->next;
		        curr->next = head;
		        head = curr;
		        curr = prev->next;
		        
		    }else{
		        prev = curr;
		        curr = curr->next;
		    }
		    
		}
		
		return head;
	}

    int main(){

    Node* head = takelist();
    Node* ans = sortlist(head);
    while(ans){
        std::cout<<ans->data<<" ";
        ans= ans->next;
    }

    
    return 0;
}

