// Rotate means rotate right in this question

#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

Node* rotateLLBrute(Node* head, int k){
  if (!head || !head -> next || !k)
    return head;
  for (int i = 0; i < k; i++){
    Node* temp = head;
    while (temp -> next && temp -> next -> next)
      temp = temp -> next;
    temp -> next -> next = head;
    head = temp -> next;
    temp -> next = nullptr;
  }
  return head;
}

int main(){
  Node* head = nullptr;
  head -> push_back(head, 1);
  head -> push_back(head, 2);
  head -> push_back(head, 3);
  head -> push_back(head, 4);
  head -> push_back(head, 5);

  int k = 2;
  Node* res = rotateLLBrute(head, k);
  res -> display(res);
  return 0;
}
