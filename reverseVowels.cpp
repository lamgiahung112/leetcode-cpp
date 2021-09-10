#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverseVowels(string s) {
    vector<char> vowels;
    string ans = "";

    for (auto c : s) {
        if (c == 'a'|| c == 'e'  || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowels.push_back(c);
        }
    }

    int left = 0;
    int right = vowels.size() - 1;
    while (left < right) {
        swap(vowels[left], vowels[right]);
        left++;
        right--;
    }
    
    for (auto c : s) {
        if (c == 'a'|| c == 'e'  || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            ans += vowels[0];
            vowels.erase(vowels.begin());
        } else {
            ans += c;
        }
    }
    
    return ans;
}

int main() {
    cout << reverseVowels("holle");
}