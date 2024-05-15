#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

void getPath(TreeNode* node, vector<int>& ans, int nodeVal){
    if (!node) return;
    ans.push_back(node -> val);
    if (node -> val == nodeVal) return;
    getPath(node -> left, ans, nodeVal);
    getPath(node -> right, ans, nodeVal);
    if (ans.back() != nodeVal)
        ans.pop_back();
    return;
}

vector<int> rootToNode(TreeNode* root, int nodeVal){
    vector<int> ans;
    getPath(root, ans, nodeVal);
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

    vector<int> path = rootToNode(root, 9);

    cout << "Root to Node Path : ";
    for (int i : path)
        cout << i << " ";
    cout << endl;
    return 0;
}
