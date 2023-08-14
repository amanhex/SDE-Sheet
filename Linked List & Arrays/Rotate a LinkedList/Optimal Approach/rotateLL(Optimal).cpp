// Rotate means rotate right in this question

#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

Node* rotateLLOp(Node* head, int k){
  if (!head || !head -> next || !k)
    return head;
  Node* temp = head;
  int length = 1;
  while (temp -> next){
    length++;
    temp = temp -> next;
  }
  temp -> next = head;
  k = k % length;
  k = length - k;
  while (k--)
    temp = temp -> next;
  head = temp -> next;
  temp -> next = nullptr;
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
  Node* res = rotateLLOp(head, k);
  res -> display(res);
  return 0;
}
