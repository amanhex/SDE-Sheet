#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> getInorder(TreeNode* root){
    vector<int> inorder;
    TreeNode* curr = root;
    while (curr){
        if (curr -> left == nullptr){
            inorder.push_back(curr -> val);
            curr = curr -> right;
        }
        else {
            TreeNode* prev = curr -> left;
            while (prev -> right && prev -> right != curr){
                prev = prev -> right;
            }
            if (prev -> right == nullptr){
                prev -> right = curr;
                curr = curr -> left;
            }
            else {
                prev -> right = nullptr;
                inorder.push_back(curr -> val);
                curr = curr -> right;
            }
        }
    }
    return inorder;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> left -> right -> right = new TreeNode(6);

    vector<int> ans = getInorder(root);

    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
