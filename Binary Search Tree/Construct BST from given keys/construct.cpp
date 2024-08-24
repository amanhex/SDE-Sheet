#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* f(vector<int>& nums, int left, int right){
  if (left > right) return nullptr;
  int mid = (left + right) / 2;
  TreeNode* temp = new TreeNode(nums[mid]);
  temp -> left = f(nums, left, mid - 1);
  temp -> right = f(nums, mid + 1, right);
  return temp;
}

TreeNode* construct(vector<int>& nums){
  return f(nums, 0, nums.size() - 1);
}

void printTree(TreeNode* root){
  if (!root) return;
  cout << root -> val << " ";
  printTree(root -> left);
  printTree(root -> right);
}

int main() {
  // Sorted array to BST
  vector<int> nums = {-10, -3, 0, 5, 9};
  TreeNode* root = construct(nums);
  printTree(root);
  cout << endl;
  return 0;
}
