#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

void gen(vector<int>& path, int k, int target, int sum, int prev) {
    if (path.size() == k) {
        if (sum != n) return;
        ans.push_back(path);
    }
    else {
        for (int i = prev + 1; i <= 9; i++) {
            sum += i;
            path.push_back(i);
            gen(path, k, target, sum, i);
            path.pop_back();
            sum -= i;
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    if (n > 45) return {};
    vector<int> path;
    gen(path, k, n, 0, 0);
    return ans;
}

int main() {

}