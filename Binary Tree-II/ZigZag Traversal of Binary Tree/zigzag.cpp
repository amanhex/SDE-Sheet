#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzag(TreeNode *root) {
  vector<vector<int>> result;

  if (!root)
    return result;
  queue<TreeNode *> q;
  bool leftToRight = true;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    vector<int> row(size);
    for (int i = 0; i < size; i++) {
      TreeNode *node = q.front();
      q.pop();
      int index = leftToRight ? i : (size - i - 1);
      row[index] = node->val;
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    leftToRight = !leftToRight;
    result.push_back(row);
  }
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

  vector<vector<int>> ans = zigzag(root);

  for (auto i : ans) {
    for (auto j : i)
      cout << j << " ";
    cout << endl;
  }

  return 0;
}
