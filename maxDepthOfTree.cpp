#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root, int currDepth = 0) {
    if (!root) return currDepth;

    int left = currDepth + 1, right = currDepth + 1;
    if (root->left)
    {
        left += maxDepth(root->left, currDepth);
    }

    if (root->right) {
        right += maxDepth(root->right, currDepth);
    }

    return max(left, right);
}
