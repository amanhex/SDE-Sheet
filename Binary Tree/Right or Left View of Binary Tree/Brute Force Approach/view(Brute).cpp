#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> ans;

    if (!root)
        return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()){
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++){
            TreeNode* top  = q.front();
            level.push_back(top -> val);
            q.pop();
            if (top -> left) q.push(top -> left);
            if (top -> right) q.push(top -> right);
        }
        ans.push_back(level);
    }
    return ans;
}

vector<int> rightViewBrute(TreeNode* root){
    vector<int> res;
    vector<vector<int>> levelTraversal = levelOrder(root);
    for (auto level : levelTraversal)
        res.push_back(level.back());
    return res;
}

vector<int> leftViewBrute(TreeNode* root){
    vector<int> res;
    vector<vector<int>> levelTraversal = levelOrder(root);
    for (auto level : levelTraversal)
        res.push_back(level.front());
    return res;
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

    vector<int> rightView = rightViewBrute(root);
    vector<int> leftView = leftViewBrute(root);

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
