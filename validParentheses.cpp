#include <iostream>
#include <stack>

bool isValid(std::string s) {
    std::stack<char> q;
    for (int i = 0; i < s.length(); i++) {
        //opening parentheses
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
            q.push(s[i]);
            continue;
        } 
        if (q.empty()) return false;
        //closing parentheses
        if ((s[i] == ']' && q.top() == '[') || (s[i] == '}' && q.top() == '{') || (s[i] == ')' && q.top() == '(')) {
            q.pop();
            continue;
        }
        else return false;
    }
    return q.empty();
}

int main() {
    std::cout << isValid("(])");
}