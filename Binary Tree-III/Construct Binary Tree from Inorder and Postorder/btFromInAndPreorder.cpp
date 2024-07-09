#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printInorder(TreeNode *root) {
  if (!root)
    return;
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap) {
  if (preStart > preEnd || inStart > inEnd)
    return nullptr;

  TreeNode *root = new TreeNode(preorder[preStart]);

  int inRoot = inMap[root->val];
  int numsLeft = inRoot - inStart;

  root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);

  root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

  return root;
}

TreeNode *construct(vector<int> &inorder, vector<int> &preorder) {
  map<int, int> inMap;
  for (int i = 0; i < inorder.size(); i++)
    inMap[inorder[i]] = i;

  TreeNode *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
  return root;
}

int main() {
  vector<int> inorder = {40, 20, 50, 10, 60, 30};
  vector<int> preorder = {10, 20, 40, 50, 30, 60};
  TreeNode *root = construct(inorder, preorder);

  cout << "Inorder Vector: ";
  for (int i : inorder)
    cout << i << " ";
  cout << endl;

  cout << "Preorder Vector: ";
  for (int i : preorder)
    cout << i << " ";
  cout << endl;

  cout << "Inorder of Unique Binary Tree Created: ";
  printInorder(root);
  cout << endl;
  return 0;
}
