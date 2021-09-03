#include <string>
#include <iostream> 

using namespace std;

int to_power(int x, int power) {
    if (x == 0) return 1;
    return x * to_power(x, power - 1);
}

int getMultiplier(int number) {
    int ans = -1;
    while (number != 0) {
        ans++;
        number /= 10;
    }
    return to_power(26, ans);
}

string convertToTitle(int number) {
    int multiplier = getMultiplier(number);
    
    return;
}