#include <string>
#include <iostream>

using namespace std;

string addStrings(string num1, string num2) {
    int ptr1 = num1.size() - 1;
    int ptr2 = num2.size() - 1;

    string ans = "";
    int carry = 0;

    while (ptr1 >= 0 && ptr2 >= 0) {
        int digit1 = (num1[ptr1]) - '0';
        int digit2 = (num2[ptr2]) - '0';

        int currSum = digit1 + digit2 + carry;

        if (currSum < 10) {
            ans.insert(0, to_string(currSum));
            carry = 0;
        }

        else if (currSum >= 10) {
            string currSumStr = to_string(currSum);
            carry = (currSumStr[0]) - '0';
            ans.insert(0, 1, currSumStr[1]);
        }

        ptr1--;
        ptr2--;
    }

    if (ptr1 >= 0) {
        while (ptr1 >= 0) {
            int digit = (num1[ptr1]) - '0';
            int currSum = digit + carry;

            if (currSum < 10) {
                ans.insert(0, to_string(currSum));
                carry = 0;
            }

            else {
                string currSumStr = to_string(currSum);
                carry = (currSumStr[0]) - '0';
                ans.insert(0, 1, currSumStr[1]);
            }
            ptr1--;
        }        
    }

    if (ptr2 >= 0) {
        while (ptr2 >= 0) {
            int digit = (num2[ptr2]) - '0';
            int currSum = digit + carry;

            if (currSum < 10) {
                ans.insert(0, to_string(currSum));
                carry = 0;
            }

            else {
                string currSumStr = to_string(currSum);
                carry = (currSumStr[0]) - '0';
                ans.insert(0, 1, currSumStr[1]);
            }
            ptr2--;
        }        
    }

    if (carry != 0) {
        ans.insert(0, to_string(carry));
    }

    return ans;
}

int main() {
    cout << addStrings("9", "1");
}