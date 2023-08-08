#include <iostream>
#include "../../Node.h"
using namespace std;

Node* add2NumsOp(Node* num1, Node* num2){
    Node* node1 = num1, *node2 = num2, *prev = nullptr;
    int sum = 0, carry = 0;
    while (node1 && node2){
        sum = node1 -> data + node2 -> data + carry;
        node1 -> data = sum % 10;
        carry = sum / 10;
        prev = node1;
        node1 = node1 -> next;
        node2 = node2 -> next;
    }

    if (node1 || node2){
        if (node2)
            prev -> next = node2;
        node1 = prev -> next;
        while (node1){
            sum = node1 -> data + carry;
            node1 -> data = sum % 10;
            carry = sum / 10;
            prev = node1;
            node1 = node1 -> next;
        }
    }
    if (carry > 0)
        prev -> next = new Node(carry);
    return num1;
}

int main(){
    Node* num1 = nullptr;
    num1 -> push_back(num1, 2);
    num1 -> push_back(num1, 4);
    num1 -> push_back(num1, 3);

    Node* num2 = nullptr;
    num2 -> push_back(num2, 5);
    num2 -> push_back(num2, 6);
    num2 -> push_back(num2, 7);
    num2 -> push_back(num2, 9);

    Node* res = add2NumsOp(num1, num2);

    res -> display(res);
    return 0;
}
