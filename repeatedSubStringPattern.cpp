#include <string>
#include <iostream>
#include <map>
using namespace std;

bool repeatedSubstringPattern(string s) {
    if (s.size() == 0) return false;
    for(int  i = 1; i <= s.size() / 2; i++) {
        string sub = s.substr(0, i);
        int it = i;
        
        while (it < s.size()) {
            string nextSub = s.substr(it, sub.size());
            if (nextSub == sub) {
                it += sub.size();
                if (it == s.size()) return true;
            } else break;
        }
    }
    return false;
}

int main() {
    cout << repeatedSubstringPattern("caccaccac");
}