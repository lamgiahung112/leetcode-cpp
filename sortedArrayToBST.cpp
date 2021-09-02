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

TreeNode *val(vector<int> &nums, int left, int right) {
    if (left > right) return NULL;

    int mid = (left + right) / 2;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = val(nums, left, mid - 1);
    root->right = val(nums, mid + 1, right);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
    return val(nums, 0, nums.size() - 1);
}