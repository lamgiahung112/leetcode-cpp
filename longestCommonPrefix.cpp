#include <iostream>
#include <vector>
std::string solve(std::vector<std::string> &strs) {
    if (strs.size() == 1) return strs[0];
    std::string ans;
    int outer = strs[0].size();
    int inner = strs.size();

    for (int i = 0; i < outer; i++) {
        for (int j = 1; j < inner; j++) {
            if (strs[0][i] != strs[j][i]) {
                return ans;
            }
        }
        ans.push_back(strs[0][i]);
    }
    return ans;
}

int main() {
    std::vector<std::string> strs = {""};
    std::cout << solve(strs);
}