#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int count = 0;
    int it = 0;
    sort(begin(g), end(g));
    sort(begin(s), end(s));
    for (int i = 0; i < s.size() && it < g.size(); i++) {
        if (s[i] >= g[it]) {
            count++;
            it++;
        } 
    }
    return count;
}

int main() {
    vector<int> g = {10,9,8,7};
    vector<int> s = {5,6,7,8};
    cout << findContentChildren(g, s);
}