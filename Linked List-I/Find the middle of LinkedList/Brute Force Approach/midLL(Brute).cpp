#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

Node* midLLBrute(Node* head){
    int length = 0;
    Node* temp = head;
    while (temp){
        length++;
        temp = temp -> next;
    }
    temp = head;
    for (int i = 0; i < length / 2; i++)
        temp = temp -> next;
    return temp;
}

int main(){
    Node* head = nullptr;
    head -> push_back(head, 1);
    head -> push_back(head, 2);
    head -> push_back(head, 3);
    head -> push_back(head, 4);
    head -> push_back(head, 5);

    Node* mid = midLLBrute(head);
    cout << "Mid Node: " << mid -> data << endl;
    return 0;
}
