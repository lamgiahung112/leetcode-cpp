#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string& s1, string& s2) {
    string contentA = s1.substr(s1.find(' '));
    string contentB = s2.substr(s2.find(' '));

    return contentA == contentB ? s1 < s2 : contentA < contentB;
}

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> result;
    int count = 0;
    for (auto log : logs) {
        if (log.back() >= '0' && log.back() <= '9') {
            result.push_back(log);
        } else {
            result.insert(begin(result), log);
            count++;
        }
    }
    
    sort(result.begin(), result.begin() + count, compare);
    return result;
}

int main() {
    vector<string> test = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    vector<string> assert = reorderLogFiles(test);
}
