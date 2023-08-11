#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

Node* reverse(Node* head){
  if (!head || !head -> next)
    return head;
  Node* prev = nullptr;
  while (head){
    Node* temp = head -> next;
    head -> next = prev;
    prev = head;
    head = temp;
  }
  return prev;
}

bool pLLOp(Node* head){
  if (!head || !(head -> next))
    return true;
  Node* slow = head, *fast = head;
  while (fast -> next && fast -> next -> next){
    slow = slow -> next;
    fast = fast -> next -> next;
  }
  slow -> next = reverse(slow -> next);
  slow = slow -> next;
  fast = head;
  while (slow){
    if (fast -> data != slow -> data)
      return false;
    slow = slow -> next;
    fast = fast -> next;
  }
  return true;
}

int main(){
  Node* head = nullptr;
  head -> push_back(head, 1);
  head -> push_back(head, 2);
  head -> push_back(head, 3);
  head -> push_back(head, 3);
  head -> push_back(head, 2);
  head -> push_back(head, 1);

  bool res = pLLOp(head);
  if (res)
    cout << "Palindrome" << endl;
  else
    cout << "Not Palindrome" << endl;
  return 0;
}
