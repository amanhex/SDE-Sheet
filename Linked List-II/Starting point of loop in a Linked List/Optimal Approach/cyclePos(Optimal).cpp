#include <iostream>
#include "../../Node.h"
using namespace std;

Node* cyclePosOp(Node* head){
  if (!head || !head -> next)
    return nullptr;
  Node* slow = head, *fast = head, *entry = head;
  while (fast -> next && fast -> next -> next){
    slow = slow -> next;
    fast = fast -> next -> next;
    if (fast == slow){
      while (slow != entry){
        slow = slow -> next;
        entry = entry -> next;
      }
      return slow;
    }
  }
  return nullptr;
}

int main(){
  Node* head = nullptr;
  head -> push_back(head, 3);
  head -> push_back(head, 2);
  head -> push_back(head, 0);
  head -> push_back(head, -4);
  head -> next -> next -> next -> next = head -> next;
  
  Node* res = cyclePosOp(head);
  if (res)
    cout << "Tail of LinkedList is connected to node: " << res -> data << endl;
  else
    cout << "No cycle present!" << endl;
  return 0;
}
