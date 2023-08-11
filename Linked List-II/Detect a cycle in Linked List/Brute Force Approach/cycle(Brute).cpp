#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

bool cycleBrute(Node* head){
  if (!head)
    return false;
  unordered_set<Node*> st;
  do{
    st.insert(head);
    head = head -> next;
  } while (head && st.find(head) == st.end());
  return head != nullptr;
}

int main(){
  Node* head = nullptr;
  head -> push_back(head, 3);
  head -> push_back(head, 2);
  head -> push_back(head, 0);
  head -> push_back(head, -4);
  head -> next -> next -> next -> next = head -> next;
  
  if (cycleBrute(head))
    cout << "Cycle is present" << endl;
  else 
    cout << "Cycle not present!" << endl;
  return 0;
}
