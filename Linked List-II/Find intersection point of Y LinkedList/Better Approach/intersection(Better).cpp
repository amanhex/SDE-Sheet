#include <bits/stdc++.h>
#include "../../Node.h"
using namespace std;

Node* intersectionBetter(Node* head1, Node* head2){
	unordered_set<Node*> st;
	while (head1){
		st.insert(head1);
		head1 = head1 -> next;
	}
	while (head2){
		if (st.find(head2) != st.end())
			return head2;
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

	Node* res = intersectionBetter(head1, head2);
	if (res)
		cout << "Intersection Point at : " << res -> data << endl;
	else
		cout << "Intersection not found!" << endl;
	return 0;
}
