#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

bool pLLBrute(Node* head){
  if (!head || !(head -> next))
    return true;
  vector<int> vc;
  Node* temp = head;
  while (temp){
    vc.push_back(temp -> data);
    temp = temp -> next;
  }
  for (int i = 0; i < vc.size() / 2; i++) {
    if (vc[i] != vc[vc.size() - i - 1])
      return false;
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

  bool res = pLLBrute(head);
  if (res)
    cout << "Palindrome" << endl;
  else
    cout << "Not Palindrome" << endl;
  return 0;
}
