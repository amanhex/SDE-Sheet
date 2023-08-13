#include <iostream>
#include "../../Node.h"
using namespace std;

int getLength(Node* head, int k){
  if (!head)
    return 0;
  int length = 0;
  Node* temp = head;
  while (temp && length < k){
    length++;
    temp = temp -> next;
  }
  return length;
}

Node* reverseGroupK(Node* head, int k){
  if (!head || !head -> next || k == 1)
    return head;
  Node* prev = nullptr, *curr = head;
  int check = getLength(curr, k);
  if (check < k)
    return curr;
  int count = 1;
  while (curr && count <= k){
    Node* temp = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = temp;
    count++;
  }
  head -> next = reverseGroupK(curr, k);
  return prev;
}

int main(){
  Node* head = nullptr;
  head -> push_back(head, 1);
  head -> push_back(head, 2);
  head -> push_back(head, 3);
  head -> push_back(head, 4);
  head -> push_back(head, 5);
  head -> push_back(head, 6);
  head -> push_back(head, 7);
  head -> push_back(head, 8);

  int k = 3;
  Node* res = reverseGroupK(head, k);
  res -> display(res);
  return 0;
}
