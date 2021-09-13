#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define MAX(x, y) ((x>y)?(x):(y))

// int lengthOfLongestSubstring(string s) {
//     if (s.size() == 0) return 0;
//     vector<string> substrs;
//     int max = 0;

//     for(int i = 0; i < s.size(); i++) {
//         if (s.size() - i < max) return max;
//         map<char, bool> isRegistered;
//         int idx = i;
//         while (idx < s.size() && !isRegistered[s[idx]]) {
//             isRegistered[s[idx]] = true;
//             idx++;
//         }
//         int len = idx - i + 1;
//         if (len > max) max = len;
//     }
//     return max;
// }

int lengthOfLongestSubstring(string s) {

    int slen = s.length();

    map<char, int> meta;
    int len = 0;
    int base = -1;
    for(int i = 0; i < slen; i++)
    {
        auto iter = meta.find(s[i]);
        if(iter != meta.end())
            base = MAX(base, iter->second);

        meta[s[i]] = i;
        
        len = MAX(len, i-base);
    }
    return len;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb");
}