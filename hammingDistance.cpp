#include <string>
#include <iostream>

using namespace std;

string getBin(int x) {
    string ans = "";
    
    while (x != 0) {
        ans.insert(0, to_string(x % 2));
        x /= 2;
    }
    
    return ans;
}

int hammingDistance(int x, int y) {
    string xStr = getBin(x);
    string yStr = getBin(y);
    
    int count = 0;

    //make them have the same length
    while (xStr.size() < yStr.size()) {
        xStr.insert(0, 1, '0');
    }
    while (yStr.size() < xStr.size()) {
        yStr.insert(0, 1, '0');
    }

    for (int i = xStr.size(); i >= 0; i--) {
        if (xStr[i] != yStr[i]) count++;
    }

    return count;
}

int main() {
    cout << hammingDistance(3,1);
}