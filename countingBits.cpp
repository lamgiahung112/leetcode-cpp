#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


string findBinary(int decimal, string result = "") {
    if (decimal == 0) return result;

    result.insert(0, to_string(decimal % 2));
    return findBinary(decimal / 2, result);
}
vector<int> countBits(int n) {
    vector<int> ans;
    for (int i = 0; i <= n; i++) {
        string binStr = findBinary(i);
        stringstream converter(binStr);
        long long bin = 0;
        converter >> bin;
        int bits = 0;
        while (bin != 0) {
            int value = bin % 10;
            if (value == 1) bits++;
            bin /= 10;
        }
        ans.push_back(bits);
    }
    return ans;
}

int main() {
    vector<int> test = countBits(5);
}