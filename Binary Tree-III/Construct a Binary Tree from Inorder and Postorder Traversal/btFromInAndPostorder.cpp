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

TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int>& inMap){
  if (inStart > inEnd || postStart > postEnd)
    return nullptr;
  TreeNode* root = new TreeNode(postorder[postEnd]);
  int inRoot = inMap[root -> val];
  int numsLeft = inRoot - inStart;
  root -> left = buildTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMap);
  root -> right = buildTree(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);
  return root;
}

TreeNode *construct(vector<int> &inorder, vector<int> &postorder) {
  map<int, int> inMap;
  for (int i = 0; i < inorder.size(); i++)
    inMap[inorder[i]] = i;
  TreeNode* root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
  return root;
}

int main() {
  vector<int> inorder = {9, 3, 15, 20, 7};
  vector<int> postorder = {9, 15, 7, 20, 3};
  TreeNode *root = construct(inorder, postorder);

  cout << "Inorder Vector: ";
  for (int i : inorder)
    cout << i << " ";
  cout << endl;

  cout << "Postorder Vector: ";
  for (int i : postorder)
    cout << i << " ";
  cout << endl;

  cout << "Inorder of Unique Binary Tree Created: ";
  printInorder(root);
  cout << endl;
  return 0;
}
