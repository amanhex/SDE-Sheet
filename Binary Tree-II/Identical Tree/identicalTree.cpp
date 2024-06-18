#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isIdentical(TreeNode *root1, TreeNode *root2) {
  if (!root1 && !root2)
    return true;
  if (!root1 || !root2)
    return false;
  return (root1->val == root2->val) && isIdentical(root1->left, root2->left) &&
         isIdentical(root1->right, root2->right);
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  root1->left->left = new TreeNode(4);

  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(4);
  root2->left->left = new TreeNode(4);

  if (isIdentical(root1, root2))
    cout << "The binary trees are identical" << endl;
  else
    cout << "The binary trees are not identical" << endl;
  return 0;
}
