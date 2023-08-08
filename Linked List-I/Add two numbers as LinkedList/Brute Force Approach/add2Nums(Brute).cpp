#include <iostream>
#include "../../Node.h"
using namespace std;

Node* add2NumsBrute(Node* num1, Node* num2){
    Node* dummy = new Node(0);
    Node* temp = dummy;
    int carry = 0;
    while (num1 || num2 || carry){
        int sum = carry;
        if (num1){
            sum += num1 -> data;
            num1 = num1 -> next;
        }
        if (num2){
            sum += num2 -> data;
            num2 = num2 -> next;
        }
        if (sum > 9){
            carry = 1;
            sum -= 10;
        }
        else
            carry = 0;
        Node* newNode = new Node(sum);
        temp -> next = newNode;
        temp = temp -> next;
    }
    return dummy -> next;
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

    Node* res = add2NumsBrute(num1, num2);

    res -> display(res);
    return 0;
}
