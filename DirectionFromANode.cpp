#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string a;
bool finished = false;

void getList(TreeNode* root, map<pair<int, int>, char>& adj, map<int, vector<int>>& neigh) {
    if (!root) return;
    if (root->right) {
        adj[{root->val, root->right->val}] = 'R';
        adj[{root->right->val, root->val}] = 'U';
        neigh[root->val].push_back(root->right->val);
        neigh[root->right->val].push_back(root->val);
        getList(root->right, adj, neigh);
    }

    if (root->left) {
        adj[{root->val, root->left->val}] = 'L';
        adj[{root->left->val, root->val}] = 'U';
        neigh[root->val].push_back(root->left->val);
        neigh[root->left->val].push_back(root->val);
        getList(root->left, adj, neigh);
    }
}

void dfs(map<pair<int, int>, char>& adj, int cur, int dest, map<int, vector<int>>& neigh, vector<char>& ans, map<int, bool>& visit) {
    if (visit[cur]) return;
    if (finished) return;
    if (cur == dest) {
        a = string(ans.begin(), ans.end());
        finished = true;
        return;
    }
    visit[cur] = true;
    for (auto nei : neigh[cur]) {
        ans.push_back(adj[{cur, nei}]);
        dfs(adj, nei, dest, neigh, ans, visit);
        ans.pop_back();
    }
}


string getDirections(TreeNode* root, int startValue, int destValue) {
    map<pair<int, int>, char> adj;
    map<int, vector<int>> neigh;
    getList(root, adj, neigh);
    vector<char> v;
    map<int, bool> visit;
    dfs(adj, startValue, destValue, neigh, v, visit);
    return a;
}

int main() {

}