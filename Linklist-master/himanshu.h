#ifndef BUILDTREE_H
#define BUILDTREE_H
#include<bits/stdc++.h>
using namespace std;

class Node
{   public:
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node*& head, int element) {
   Node *toAdd = new Node(element), *temp = head;
   if (temp == nullptr) {
       // If empty list, assign the new node to head
       head = temp = toAdd;
   } else {
       // Otherwise, go to the last node and add the new node after it
       while (temp->next != nullptr) {
           temp = temp->next;
       }
       temp->next = toAdd;
   }
}

Node* bulidlist(vector<int> arr) {
    int size = arr.size();
   Node* head = nullptr;
   for (int i = 0; i < size; ++i) {
       insertAtEnd(head, arr[i]);
   }
   return head;
}

Node* takelist()
{
        string s;
        getline(std::cin, s);
        stringstream iss(s);

        int number;
        vector<int> arr;
        while ( iss >> number )
        arr.push_back( number );
        return bulidlist(arr);
        
}



#endif 