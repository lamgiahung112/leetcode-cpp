#include <iostream>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *invertTree(TreeNode *root) {
    // return if root == nulptr or have no child
    if (!root || (!root->left && !root->right)) return root;
    
    // have two children
    if (root->left && root->right) {
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);
    }
    // only have right child
    else if (root->right) {
        root->left = root->right;
        root->right = nullptr;
        // the right child is now the left child so we call invert on the left child
        invertTree(root->left);
    }
    // only have left child
    else if (root->left) {
        root->right = root->left;
        root->left = nullptr;
        invertTree(root->right);
    }
    return root;
}