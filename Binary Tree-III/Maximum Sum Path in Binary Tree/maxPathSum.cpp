#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findMaxPathSum(TreeNode *root, int &maxi) {
  if (!root)
    return 0;
  int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
  int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));
  maxi = max(maxi, (leftMaxPath + rightMaxPath + root->val));
  return max(leftMaxPath, rightMaxPath) + root->val;
}

int maxPathSum(TreeNode *root) {
  if (!root)
    return 0;
  if (!root->left && !root->right)
    return root->val;
  int maxi = INT_MIN;
  findMaxPathSum(root, maxi);
  return maxi;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->right = new TreeNode(6);
  root->left->right->right->right = new TreeNode(7);

  int maxSum = maxPathSum(root);
  cout << maxSum << endl;
  return 0;
}
