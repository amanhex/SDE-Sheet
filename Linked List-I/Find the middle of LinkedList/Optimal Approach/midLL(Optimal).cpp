#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

// T.C: O(n) && S.C: O(1)
Node* midLLBrute(Node* head){
    Node* slow = head, *fast = head;
    while (fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
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
