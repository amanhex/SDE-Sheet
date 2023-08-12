#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

Node* cyclePosBrute(Node* head){
  if (!head || !head -> next)
    return nullptr;
  unordered_set<Node*> st;
  do{
    st.insert(head);
    head = head -> next;
  } while (head && st.find(head) == st.end());
  return head;
}

int main(){
  Node* head = nullptr;
  head -> push_back(head, 3);
  head -> push_back(head, 2);
  head -> push_back(head, 0);
  head -> push_back(head, -4);
  head -> next -> next -> next -> next = head -> next;
  
  Node* res = cyclePosBrute(head);
  if (res)
    cout << "Tail of LinkedList is connected to node: " << res -> data << endl;
  else
    cout << "No cycle present!" << endl;
  return 0;
}
