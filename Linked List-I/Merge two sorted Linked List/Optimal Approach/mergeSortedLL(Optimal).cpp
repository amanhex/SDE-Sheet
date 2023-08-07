#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

Node* mergeSortedLLOp(Node* l1, Node* l2){
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1 -> data > l2 -> data)
        swap(l1, l2);
    Node* res = l1;
    while (l1 && l2){
        Node* temp = nullptr;
        while (l1 && l1 -> data <= l2 -> data){
            temp = l1;
            l1 = l1 -> next;
        }
        temp -> next = l2;
        swap(l1, l2);
    }
    return res;
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

    Node* res = mergeSortedLLOp(l1, l2);;
    res -> display(res);
    return 0;
}
