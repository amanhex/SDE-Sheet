#include <iostream>
#include "../../Node.h"
using namespace std;

// T.C: O(2n) & S.C: O(1)
Node* removeBrute(Node* head, int n){
    Node* dummy = head;
    int length = 0;
    while (dummy){
        length++;
        dummy = dummy -> next;
    }

    if (n == length){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    int j = length - n;
    dummy = head;
    for (int i = 1; i < j; i++)
        dummy = dummy -> next;
    Node* temp = dummy -> next;
    dummy -> next = temp -> next;
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

    Node* newHead = removeBrute(head, n);

    // Linked List After removal
    newHead -> display(newHead);
    return 0;
}
