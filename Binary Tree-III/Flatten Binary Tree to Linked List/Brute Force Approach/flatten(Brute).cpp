#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void helper(TreeNode *root, TreeNode *&prev) {
  if (!root)
    return;
  helper(root->right, prev);
  helper(root->left, prev);
  root->right = prev;
  root->left = nullptr;
  prev = root;
}

void flattenBrute(TreeNode *root) {
  if (!root)
    return;
  TreeNode *prev = nullptr;
  helper(root, prev);
}

void printPreorder(TreeNode *root) {
  if (!root)
    return;
  cout << root->val << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

void printFlattenTree(TreeNode *root) {
  if (!root)
    return;
  cout << root->val << " ";
  printFlattenTree(root->right);
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->right = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->right->left = new TreeNode(8);

  cout << "Binary Tree Preorder: ";
  printPreorder(root);
  cout << endl;

  flattenBrute(root);

  cout << "Binary Tree After Flattening: ";
  printFlattenTree(root);
  cout << endl;

  return 0;
}
