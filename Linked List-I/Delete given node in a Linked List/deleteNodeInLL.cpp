/*
Problem Statement: Write a function to delete a node in a singly-linked list.
You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly. 
It is guaranteed that the node to be deleted is not a tail node in the list.
*/

#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

// T.C: O(1)
void deleteNode(Node* delNode){
    if (delNode == nullptr || delNode -> next == nullptr)
        return;
    delNode -> data = delNode -> next -> data;
    delNode -> next = delNode -> next -> next;
    return;
}


int main(){
    Node* head = nullptr;
    head -> push_back(head, 1);
    head -> push_back(head, 2);
    head -> push_back(head, 3);
    head -> push_back(head, 4);
    head -> push_back(head, 5);

    // Before Deleting 3
    head -> display(head);

    Node* delNode = head -> find(head, 3);
    deleteNode(delNode);

    // After Deleting 3
    head -> display(head);
    return 0;
}
