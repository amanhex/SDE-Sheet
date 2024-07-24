#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool helper(TreeNode *node1, TreeNode *node2) {
  if (!node1 || !node2)
    return node1 == node2;
  return (node1->val == node2->val) && helper(node1->left, node2->right) &&
         helper(node1->right, node2->left);
}

bool isMirror(TreeNode *root) {
  if (!root)
    return true;
  return helper(root->left, root->right);
}

void printInorder(TreeNode *root) {
  if (!root)
    return;
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->right->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);

  cout << "Binary Tree (Inorder) :";
  printInorder(root);
  cout << endl;

  bool ans = isMirror(root);
  if (ans)
    cout << "The Binary Tree is mirror of itself" << endl;
  else
    cout << "The Binary Tree is not mirror of itself" << endl;
  return 0;
}