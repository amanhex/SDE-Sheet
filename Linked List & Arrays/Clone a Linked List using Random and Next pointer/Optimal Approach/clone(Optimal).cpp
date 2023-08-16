#include<bits/stdc++.h>
#include "../Custom-Node.h"
using namespace std;

Node* cloneOp(Node* head){
  if (!head)
    return nullptr;
  //Step1 : Interweave New and Original Linked List together
  Node* temp = head;
  while (temp){
    Node* newNode = new Node(temp -> val);
    newNode -> next = temp -> next;
    temp -> next = newNode;
    temp = newNode -> next;
  }

  // Step2 : Initialise the random pointers of newNode correctly
  temp = head;
  while (temp){
    temp -> next -> random = temp -> random ? temp -> random -> next : nullptr;
    temp = temp -> next -> next;
  }

  // Step3 : Correct both Original and New Linked List
  Node* newHead = head -> next;
  temp = head;
  Node* newTemp = newHead;
  while (temp){
    temp -> next = newTemp -> next;
    temp = temp -> next;
    newTemp -> next = temp ? temp -> next : nullptr;
    newTemp = newTemp -> next;
  }
  return newHead;
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
    Node* newHead = cloneOp(head);
    head -> display(newHead);
    return 0;
}
