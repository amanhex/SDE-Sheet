#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<int> bottomView(TreeNode* root){
    vector<int> res;
    map<int, int> mp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;
        mp[line] = node -> val;
        if (node -> left)
            q.push({node -> left, line - 1});
        if (node -> right)
            q.push({node -> right, line + 1});
    }
    for (auto it : mp)
        res.push_back(it.second);
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

    vector<int> view = bottomView(root);

    cout << "Bottom view of the Binary Tree : ";
    for (int i : view)
        cout << i << " ";
    cout << endl;
    return 0;
}
