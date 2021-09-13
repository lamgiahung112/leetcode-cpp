#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    
    vector<int> v1(26), v2(26);
    
    for (char c : s1) {
        v1[c - 'a']++;
    }
    
    for (int i = 0; i <= s2.size() - s1.size(); i++) {
        for(int j = i; j < s1.size() + i; j++) {
            v2[s2[j] - 'a']++;
        }
        
        if (v1 == v2) return true;
        
        fill(begin(v2), end(v2), 0);
        
    }
    
    return false;
}

int main() {
    cout << checkInclusion("adc", "dcda");
}