#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, int> map_s;
    unordered_map<char, int> map_t;

    for (int i = 0; i < s.size(); i++) {
        map_s[s[i]]++;
        map_t[t[i]]++;
    }
    return map_s == map_t;
}