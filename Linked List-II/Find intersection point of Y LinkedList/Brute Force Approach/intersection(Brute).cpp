#include <iostream>
#include "../../Node.h"
using namespace std;

Node* intersectionBrute(Node* head1, Node* head2){
	while (head2){
		Node* temp = head1;
		while (temp){
			if (temp == head2)
				return head2;
			temp = temp -> next;
		}
		head2 = head2 -> next;
	}
	return nullptr;
}

int main(){
	Node* head = nullptr;
	head -> push_back(head, 1);
	head -> push_back(head, 3);
	head -> push_back(head, 1);
	head -> push_back(head, 2);
	head -> push_back(head, 4);

	Node* head1 = head;
	head = head -> next -> next -> next;

	Node* headsec = nullptr;
	headsec -> push_back(headsec, 3);
	Node* head2 = headsec;
	headsec -> next = head;

	Node* res = intersectionBrute(head1, head2);
	if (res)
		cout << "Intersection Point at : " << res -> data << endl;
	else
		cout << "Intersection not found!" << endl;
	return 0;
}
