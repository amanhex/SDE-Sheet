#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int height(TreeNode *root) {
  if (!root)
    return 0;
  int lh = height(root->left);
  int rh = height(root->right);
  return max(lh, rh) + 1;
}

bool isBalancedBrute(TreeNode *root) {
  if (!root)
    return true;
  int lh = height(root->left);
  int rh = height(root->right);
  if (abs(lh - rh) > 1)
    return false;
  return isBalancedBrute(root->left) && isBalancedBrute(root->right);
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  if (isBalancedBrute(root))
    cout << "Tree is height balanced" << endl;
  else
    cout << "Tree is not height balanced" << endl;
  return 0;
}
