#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> map; // map to store number of appearances of each key
    vector<char> keys; // keys to iterate the map
    string palindrome = "";
    for (int i = 0; i < s.size(); i++) {
        keys.push_back(s[i]);
        map[s[i]]++;
    }
    
    // get the element appearing x times (x not divisble to 2) to the middle
    for (auto key : keys) {
        if (map[key] % 2 == 1) {
            palindrome += key;
            map[key]--;
            break;
        }
    }
    
    
    for (auto key : keys) {
        while (map[key] != 0 && map[key] != 1) {
            palindrome.insert(palindrome.begin(), key);
            palindrome.insert(palindrome.end(), key);
            map[key] -= 2;
        }
    }
    
    return palindrome.size();
}

int main() {
    cout << longestPalindrome("abccccdd");
}