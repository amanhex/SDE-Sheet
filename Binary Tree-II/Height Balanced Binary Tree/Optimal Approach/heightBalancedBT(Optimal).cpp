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
  if (lh == -1)
    return -1;
  int rh = height(root->right);
  if (rh == -1)
    return -1;
  if (abs(lh - rh) > 1)
    return -1;
  return max(lh, rh) + 1;
}

bool isBalancedOp(TreeNode *root) { return height(root) != -1; }

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  if (isBalancedOp(root))
    cout << "Tree is height balanced" << endl;
  else
    cout << "Tree is not height balanced" << endl;
  return 0;
}
