#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isLeaf(TreeNode *node) {
  if (!node->left && !node->right)
    return true;
  return false;
}

void addLeftBoundary(TreeNode *root, vector<int> &result) {
  TreeNode *curr = root->left;
  while (curr) {
    if (!isLeaf(curr))
      result.push_back(curr->val);
    if (curr->left)
      curr = curr->left;
    else
      curr = curr->right;
  }
}

void addLeafBoundary(TreeNode *root, vector<int> &result) {
  if (isLeaf(root)) {
    result.push_back(root->val);
    return;
  }
  if (root->left)
    addLeafBoundary(root->left, result);
  if (root->right)
    addLeafBoundary(root->right, result);
}

void addRightBoundary(TreeNode *root, vector<int> &result) {
  TreeNode *curr = root->right;
  vector<int> tmp;
  while (curr) {
    if (!isLeaf(curr))
      tmp.push_back(curr->val);
    if (curr->right)
      curr = curr->right;
    else
      curr = curr->left;
  }

  for (int i = tmp.size() - 1; i >= 0; i--)
    result.push_back(tmp[i]);
}

vector<int> boundary(TreeNode *root) {
  if (!root)
    return {};
  vector<int> result;
  if (!isLeaf(root))
    result.push_back(root->val);
  addLeftBoundary(root, result);
  addLeafBoundary(root, result);
  addRightBoundary(root, result);
  return result;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  vector<int> result = boundary(root);
  for (auto i : result)
    cout << i << " ";
  cout << endl;
  return 0;
}
