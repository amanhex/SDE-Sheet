#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

Node* mergeSortedLLBrute(Node* l1, Node* l2){
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    Node* newHead = new Node(2);
    Node* dummy = newHead;
    while (l1 && l2){
        if (l1 -> data < l2 -> data){
            Node* temp = new Node(l1 -> data);
            dummy -> next = temp;
            dummy = dummy -> next;
            l1 = l1 -> next;
        }
        else{
            Node* temp = new Node(l2 -> data);
            dummy -> next = temp;
            dummy = dummy -> next;
            l2 = l2 -> next;
        }
    }
    while (l1){
        Node* temp = new Node(l1 -> data);
        dummy -> next = temp;
        dummy = dummy -> next;
        l1 = l1 -> next;
    }
    while (l2){
        Node* temp = new Node(l2 -> data);
        dummy -> next = temp;
        dummy = dummy -> next;
        l2 = l2 -> next;
    }
    return newHead -> next;
}

int main(){
    Node* l1 = nullptr;
    l1 -> push_back(l1, 5);
    l1 -> push_back(l1, 7);
    l1 -> push_back(l1, 9);

    Node* l2 = nullptr;
    l2 -> push_back(l2, 3);
    l2 -> push_back(l2, 4);
    l2 -> push_back(l2, 8);
    l2 -> push_back(l2, 10);

    Node* res = mergeSortedLLBrute(l1, l2);;
    res -> display(res);
    return 0;
}
