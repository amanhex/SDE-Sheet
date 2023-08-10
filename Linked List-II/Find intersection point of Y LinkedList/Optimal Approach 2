#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

Node* intersectionOp2(Node* head1, Node* head2){
	Node* dummy1 = head1, *dummy2 = head2;
	while (dummy1 != dummy2){
		if (!dummy1)
			dummy1 = head2;
		if (!dummy2)
			dummy2 = head1;
		dummy1 = dummy1 -> next;
		dummy2 = dummy2 -> next;
	}
	return dummy1;
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

	Node* res = intersectionOp2(head1, head2);
	if (res)
		cout << "Intersection Point at : " << res -> data << endl;
	else
		cout << "Intersection not found!" << endl;
	return 0;
}
