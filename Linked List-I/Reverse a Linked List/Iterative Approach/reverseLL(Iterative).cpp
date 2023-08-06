#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

Node* reverseIterative(Node* head){
    if (head == nullptr || head -> next == nullptr)
        return head;
    Node* newHead = nullptr;
    while (head){
        Node* temp = head -> next;
        head -> next = newHead;
        newHead = head;
        head = temp;
    }
    return newHead;
}

int main(){
    Node* head = nullptr;
    head -> push_back(head, 1);
    head -> push_back(head, 2);
    head -> push_back(head, 3);
    head -> push_back(head, 4);
    head -> push_back(head, 5);

    // Linked List Before Reversal
    head -> display(head);

    Node* newHead = reverseIterative(head);

    // Linked List After Reversal
    head -> display(newHead);
    return 0;
}
