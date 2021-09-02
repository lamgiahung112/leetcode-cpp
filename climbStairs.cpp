#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    vector<int> steps = {1, 2};
    vector<int> results (n + 1);
    fill(results.begin(), results.end(), 0);
    results[0] = 1;

    for (int i = 0; i <= n; i++) {
        for(auto step: steps) {
            int idx = i + step;
            if (idx <= n) {
                results[idx] += results[i];
            }
        }
    }  
    return results[n];
}

int main() {
    cout << climbStairs(3);
}