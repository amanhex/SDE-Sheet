#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

void recursionLeft(TreeNode* root, int level, vector<int>& res);
void recursionRight(TreeNode* root, int level, vector<int>& res);

vector<int> rightViewOp(TreeNode* root){
    vector<int> res;
    recursionRight(root, 0, res);
    return res;
}

void recursionRight(TreeNode* root, int level, vector<int>& res){
    if (!root) return;
    if (res.size() == level)
        res.push_back(root -> val);
    recursionRight(root -> right, level + 1, res);
}

vector<int> leftViewOp(TreeNode* root){
    vector<int> res;
    recursionLeft(root, 0, res);
    return res;
}

void recursionLeft(TreeNode* root, int level, vector<int>& res){
    if (!root) return;
    if (level == res.size())
        res.push_back(root -> val);
    recursionLeft(root -> left, level + 1, res);
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

    vector<int> rightView = rightViewOp(root);
    vector<int> leftView = leftViewOp(root);

    cout << "Right view of the Binary Tree : ";
    for (int i : rightView)
        cout << i << " ";
    cout << endl;

    cout << "Left View of the Binary Tree : ";
    for (int i : leftView)
        cout << i << " ";
    cout << endl;
    return 0;
}
