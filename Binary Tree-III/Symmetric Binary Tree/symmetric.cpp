#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool helper(TreeNode *root1, TreeNode *root2) {
  if (!root1 || !root2)
    return root1 == root2;
  return (root1->val == root2->val) && helper(root1->left, root2->right) &&
         helper(root1->right, root2->left);
}

bool isSymmetric(TreeNode *root) {
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

  bool ans = isSymmetric(root);
  if (ans)
    cout << "Tree is symmetrical" << endl;
  else
    cout << "Tree is not symmetrical" << endl;

  return 0;
}
