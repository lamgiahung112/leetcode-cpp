#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int ransomPtr = 0;
        int magPtr = 0;
        
        while (ransomPtr < ransomNote.size() && magPtr < magazine.size()) {
            if (ransomNote[ransomPtr] > magazine[magPtr]) {
                magPtr++;
            }
            else if (ransomNote[ransomPtr] == magazine[magPtr]) {
                ransomPtr++;
                magPtr++;
            } else 
                return false;
        }
        
        return ransomPtr == ransomNote.size();
}

int main() {
    canConstruct("aa", "aab");
}