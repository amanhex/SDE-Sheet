#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int a) {
            data = a;
            next = nullptr;
        }

        // Function to insert Node in Linked List
        void push_back(Node* &head, int val) {
            Node* newNode = new Node(val);
            if(head == nullptr) {
                head = newNode;
                return;
            }
            Node* temp = head;
            while (temp -> next != nullptr) temp = temp -> next;
            temp -> next = newNode;
        }

        // Function to find a Node in Linked List
        Node* find(Node* head,int val) {
            while (head -> data != val) head = head -> next;    
            return head;
        }

        // Function to display the Linked List
        void display(Node* head){
            while (head -> next){
                cout << head -> data << " -> ";
                head = head -> next;
            }
            cout << head -> data << " ";
            cout << endl;
        }
};