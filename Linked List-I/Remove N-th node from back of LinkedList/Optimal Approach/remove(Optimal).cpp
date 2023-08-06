#include <iostream>
#include "../../Node.h"
using namespace std;

// T.C: O(n) & S.C: O(1)
Node* removeOp(Node* head, int n){
    Node* slow = head, *fast = head;
    for (int i = 0; i < n; i++)
        fast = fast -> next;
    if (fast == nullptr){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    while (fast -> next){
        slow = slow -> next;
        fast = fast -> next;
    }
    Node* temp = slow -> next;
    slow -> next = temp -> next;
    delete temp;
    return head;
}

int main(){
    Node* head = nullptr;
    head -> push_back(head, 7);
    head -> push_back(head, 6);
    head -> push_back(head, 9);
    head -> push_back(head, 4);
    head -> push_back(head, 13);
    head -> push_back(head, 2);
    head -> push_back(head, 8);

    int n = 6;

    // Linked List Before removal
    head -> display(head);

    Node* newHead = removeOp(head, n);

    // Linked List After removal
    newHead -> display(newHead);
    return 0;
}
