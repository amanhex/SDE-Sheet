#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (!root || root == p || root == q)
    return root;

  TreeNode *left = LCA(root->left, p, q);
  TreeNode *right = LCA(root->right, p, q);

  if (!left)
    return right;
  else if (!right)
    return right;
  else
    return root;
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  TreeNode *p = root->left;
  TreeNode *q = root->right->right;

  TreeNode *result = LCA(root, p, q);
  cout << result->val << endl;
  return 0;
}
