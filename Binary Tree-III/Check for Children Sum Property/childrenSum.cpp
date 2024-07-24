#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void changeTree(TreeNode *root) {
  if (!root)
    return;
  int child = 0;
  if (root->left)
    child += root->left->val;
  if (root->right)
    child += root->right->val;
  if (child >= root->val)
    root->val = child;
  else {
    if (root->left)
      root->left->val = root->val;
    else if (root->right)
      root->right->val = root->val;
  }

  changeTree(root->left);
  changeTree(root->right);

  int total = 0;
  if (root->left)
    total += root->left->val;
  if (root->right)
    total += root->right->val;
  if (root->left || root->right)
    root->val = total;
}

void printInorder(TreeNode *root) {
  if (!root)
    return;
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  cout << "Binary Tree Before Modification: ";
  printInorder(root);
  cout << endl;

  changeTree(root);

  cout << "Binary Tree After Children Sum Property: ";
  printInorder(root);
  cout << endl;

  return 0;
}