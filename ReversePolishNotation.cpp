#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> s;

    for (auto token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int n2 = s.top();
            s.pop();
            int n1 = s.top();
            s.pop();

            if (token == "+") {
                s.push(n1+n2);
            }
            if (token == "-") {
                s.push(n1-n2);
            }
            if (token == "*") {
                s.push(n1*n2);
            }
            if (token == "/") {
                s.push(n1/n2);
            }
        }
        else {
            s.push(stoi(token));
        }
    }
    return s.top();
}

int main() {
    vector<string> test = {"4","13","5","/","+"};
    cout << evalRPN(test);
}