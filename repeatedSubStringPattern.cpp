#include <string>
#include <iostream>
#include <map>
using namespace std;

bool repeatedSubstringPattern(string s) {
    string sub;
    
    int it = 0;

    while (it < s.size()) {
        if (s.substr(it, sub.size()) == sub) {
            it += sub.size();
        } else return false;
    }
    
    
    return true;
}

int main() {
    cout << repeatedSubstringPattern("caccaccac");
}