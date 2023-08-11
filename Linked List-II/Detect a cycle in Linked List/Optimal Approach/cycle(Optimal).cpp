#include <iostream>
#include "../../Node.h"
using namespace std;

bool cycleOp(Node* head){
  if (!head)
    return false;
  Node* slow = head, *fast = head;
  while (fast -> next && fast -> next -> next){
    slow = slow -> next;
    fast = fast -> next -> next;
    if (slow == fast)
      return true;
  }
  return false;
}

int main(){
  Node* head = nullptr;
  head -> push_back(head, 3);
  head -> push_back(head, 2);
  head -> push_back(head, 0);
  head -> push_back(head, -4);
  head -> next -> next -> next -> next = head -> next;
  
  if (cycleOp(head))
    cout << "Cycle is present" << endl;
  else 
    cout << "Cycle not present!" << endl;
  return 0;
}
