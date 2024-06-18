#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int heightBT(TreeNode* root){
    if (!root) return 0;

    int leftHeight = heightBT(root -> left);
    int rightHeight = heightBT(root -> right);
    return 1 + max(leftHeight, rightHeight);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(10);
    root -> left -> left -> right = new TreeNode(5);
    root -> left -> left -> right -> right = new TreeNode(6);
    root -> right = new TreeNode(3);
    root -> right -> right = new TreeNode(10);
    root -> right -> left = new TreeNode(9);

    cout << heightBT(root) << endl;
    return 0;
}
