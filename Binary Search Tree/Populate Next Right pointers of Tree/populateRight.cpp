#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

void printTree(TreeNode *root) {
  while (root) {
    TreeNode *curr = root;
    while (curr) {
      cout << curr->val << " ";
      curr = curr->next;
    }
    cout << endl;
    root = root->left;
  }
}

void populateRight(TreeNode *root) {
  if (!root)
    return;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    TreeNode *prev = nullptr;

    for (int i = 0; i < size; i++) {
      TreeNode *curr = q.front();
      q.pop();
      if (prev) {
        prev->next = curr;
      }
      prev = curr;
      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
    }
  }
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  populateRight(root);

  cout << "Tree with next pointers populated: " << endl;
  printTree(root);
  return 0;
}