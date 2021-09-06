#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;

    vector<char> table (256);
    vector<bool> duplicated (256);

    for (int i = 0; i < s.size(); i++) {
        int idx_s = static_cast<int>(s[i]);
        int idx_t = static_cast<int>(t[i]);

        //check if char at idx_s is already assigned a different t[i]
        if (table[idx_s]) {
            if (table[idx_s] != t[i]) return false;
        }

        //check if char at idx_t is already assigned a different s[i]
        if (duplicated[idx_t] && table[idx_s] != t[i]) return false;
        table[idx_s] = t[i];
        duplicated[idx_t] = true;
    }
    return true;
}

int main() {
    string s = "egg";
    string t = "add";

    cout << isIsomorphic(s, t);
}