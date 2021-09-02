#include <iostream>
#include <string>

using namespace std;

int topower(int x, int power) {
    if (power < 1) return 1;
    return x * topower(x, power - 1);
}

int titleToNumber(string columnTitle) {
    int multiplier = topower(26, columnTitle.size() - 1);
    int ans = 0;
    for (int i = 0; i < columnTitle.size(); i--) {
        ans += (columnTitle[i] - 'A' + 1) * multiplier;
        multiplier /= 26;
    }
    return ans;
}

int main() {
    cout << topower(5, 3);
    cout << titleToNumber("ZY");
}