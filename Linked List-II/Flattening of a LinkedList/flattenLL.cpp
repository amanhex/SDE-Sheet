/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/


// Just Like the mergeSort merging algorithm
Node* mergeTwoLL(Node* l1, Node* l2){
  Node* temp = new Node(0);
  Node* res = temp;
  while (l1 && l2){
    if (l1 -> data < l2 -> data){
      temp -> bottom = l1;
      temp = temp -> bottom;
      l1 = l1 -> bottom;
    }
    else{
      temp -> bottom = l2;
      temp = temp -> next;
      l2 = l2 -> bottom;
    }
  }
  if (l1) temp -> bottom = l1;
  else temp -> bottom = l2;
  return res -> bottom;
}

Node* flatten(Node* root){
  if (root || root -> next)
    return root;
  root -> next = flatten(root -> next);
  root = mergeTwoLL(root, root -> next);
  return root;
}
