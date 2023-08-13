#include <iostream>
#include "../../Node.h"
using namespace std;

Node* reverseGroupK(Node* head, int k){
  if (!head || !head -> next)
    return head;
  Node* dummy = new Node(0);
  dummy -> next = head;
  Node* curr = dummy, *prev = dummy, *nex = dummy;
  int length = 0;
  while (curr -> next){
    length++;
    curr = curr -> next;
  }
  while (length >= k){
    curr = prev -> next;
    nex = curr -> next;
    for (int i = 1; i < k; i++){
      curr -> next = nex -> next;
      nex -> next = prev -> next;
      prev -> next = nex;
      nex = curr -> next;
    }
    prev = curr;
    length -= k;
  }
  return dummy -> next;
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
