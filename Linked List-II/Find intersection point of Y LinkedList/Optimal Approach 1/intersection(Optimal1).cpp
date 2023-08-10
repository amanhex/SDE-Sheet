#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

int getDifference(Node* head1, Node* head2){
	int length1 = 0, length2 = 0;
	Node* temp1 = head1, *temp2 = head2;
	while (temp1 || temp2){
		if (temp1){
			length1++;
			temp1 = temp1 -> next;
		}
		if (temp2){
			length2++;
			temp2 = temp2 -> next;
		}
	}
	return length1 - length2;
}

Node* intersectionOp1(Node* head1, Node* head2){
	int diff = getDifference(head1, head2);
	if (diff < 0){
		while (diff++ != 0)
			head2 = head2 -> next;
	}
	else{
		while (diff--)
			head1 = head1 -> next;
	}
	while (head1){
		if (head1 == head2) return head1;
		head1 = head1 -> next;
		head2 = head2 -> next;
	}
	return head1;
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

	Node* res = intersectionOp1(head1, head2);
	if (res)
		cout << "Intersection Point at : " << res -> data << endl;
	else
		cout << "Intersection not found!" << endl;
	return 0;
}
