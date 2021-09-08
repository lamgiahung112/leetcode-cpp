#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isLeaf(TreeNode *node) {
    return !node->left && !node->right;
}

void path(TreeNode* root, vector<string> &ans, string currStr) {
    if (!root) return;
    currStr += to_string(root->val);

    if (isLeaf(root)) {
        ans.push_back(currStr);
    }
    else {
        currStr += "->";
        path(root->left, ans, currStr);
        path(root->right, ans, currStr);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string curr = "";
    path(root, ans, curr);
    return ans;
}