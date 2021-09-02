#include <iostream>
#include <string>

using namespace std;

int findDecimal(int n) {
    int dec_value = 0;

    int base = 1;
    int temp = n;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

string findBinary(int n, string result = "") {
    if (n==0) return result;

    result.insert(0, to_string(n % 2));
    return findBinary(n / 2, result);
}
string addBinary(string a, string b) {
    int dec_a = findDecimal(stoi(a));
    int dec_b = findDecimal(stoi(b));
    int sum = dec_a + dec_b;
    if (sum == 0) return "0";
    return findBinary(sum);
}

int main() {
    cout << addBinary("11","1");
    cout << addBinary("0","0");
}