#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printSubTree(TreeNode *node) {
  if (!node)
    return;
  cout << node->val << " ";
  printSubTree(node->left);
  printSubTree(node->right);
}

TreeNode *searchBST(TreeNode *root, int val) {
  if (!root)
    return nullptr;
  if (root->val == val)
    return root;
  if (root->val > val)
    return searchBST(root->left, val);
  else
    return searchBST(root->right, val);
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  TreeNode *node = searchBST(root, 5);

  printSubTree(node);
  cout << endl;
  return 0;
}