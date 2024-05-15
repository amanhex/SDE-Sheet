#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> preInPost(TreeNode* root){
    if (!root) return {};
    vector<int> pre, in, post;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()){
        auto it = st.top();
        st.pop();
        if (it.second == 1){
            pre.push_back(it.first -> val);
            it.second++;
            st.push(it);
            if (it.first -> left)
                st.push({it.first -> left, 1});
        }
        else if (it.second == 2){
            in.push_back(it.first -> val);
            it.second++;
            st.push(it);
            if (it.first -> right)
                st.push({it.first -> right, 1});
        }
        else {
            post.push_back(it.first -> val);
        }
    }
    return {pre, in, post};
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

    vector<vector<int>> ans = preInPost(root);

    for (auto i : ans){
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
