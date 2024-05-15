#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root){
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty()){
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node -> val);
        if (node -> left)
            todo.push({node -> left, {x - 1, y + 1}});
        if (node -> right)
            todo.push({node -> right, {x + 1, y + 1}});
    }
    vector<vector<int>> ans;
    for (auto p : nodes){
        vector<int> cols;
        for (auto q : p.second){
            cols.insert(cols.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(cols);
    }
    return ans;
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

    vector<vector<int>> res = verticalTraversal(root);

    cout << "Vertical Traversal of Binary Tree" << endl;
    for (auto i : res){
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
