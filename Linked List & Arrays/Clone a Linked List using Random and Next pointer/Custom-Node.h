#include <iostream>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;
  Node(int value) {
    val = value;
    next = NULL;
    random = NULL;
  }
  void display(Node *head) {
    while (head != NULL) {
      cout << head->val << ':';
      head->next != NULL ? cout << head->next->val : cout << "NULL";
      head->random != NULL ? cout << "," << head->random->val : cout << ",NULL";
      cout << endl;
      head = head->next;
    }
  }
};
