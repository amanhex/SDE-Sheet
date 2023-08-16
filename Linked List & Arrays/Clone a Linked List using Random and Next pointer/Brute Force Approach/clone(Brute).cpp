#include<bits/stdc++.h>
#include "../Custom-Node.h"
using namespace std;

Node* cloneBrute(Node* head){
  unordered_map<Node*, Node*> mpp;
  Node* temp = head;
  while (temp){
    mpp[temp] = new Node(temp -> val);
    temp = temp -> next;
  }
  temp = head;
  while (temp){
    Node* deepNode = mpp[temp];
    deepNode -> next = temp -> next ? temp -> next : nullptr;
    deepNode -> random = temp -> random ? temp -> random : nullptr;
    temp = temp -> next;
  }
  return mpp[head];
}

int main() {
    Node* head = NULL;
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    head = node1;
    head -> next = node2;
    head -> next -> next = node3;
    head -> next -> next -> next = node4;
    
    head -> random = node4;
    head -> next -> random = node1;
    head -> next -> next -> random = NULL;
    head -> next -> next -> next -> random = node2;
    
    cout << "Original list:(current node:node pointed by next pointer,node pointed by random pointer)" << endl;
    head -> display(head);
    
    cout << "Copy list:(current node:node pointed by next pointer,node pointed by random pointer)" << endl;
    Node* newHead = cloneBrute(head);
    head -> display(newHead);
    return 0;
}
