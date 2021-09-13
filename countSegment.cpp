#include <iostream>
#include <string>

using namespace std;

void validateString(string &s) {
    while (s[0] == ' ' && s.size() != 0) {
        s.erase(0, 1);
    }

    for(int i = 0; i < s.size() - 1 && s.size() != 0; i++) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            s.erase(i, 1);
            i--;
        }
    }

    if (s[s.size() - 1] == ' ' && s.size() != 0) {
        s.erase(s.size() - 1);
    }
}

int countSegments(string s) {
    validateString(s);
    if (s.size() == 0) return 0;
    int count = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            count++;
        }
    }
    return count;
}

int main() {
    // string test1 = "     ";
    // string test2 = "";
    string test3 = ", , , ,        a, eaefa    ";

    // cout << countSegments(test1) << endl;
    // cout << countSegments(test2) << endl;
    cout << countSegments(test3) << endl;
}

