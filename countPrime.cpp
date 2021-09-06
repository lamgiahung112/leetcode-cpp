#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int countPrimes(int n) {
    vector<bool> prime (n, true);
    int count = 0;

    for (int i = 2; i < sqrt(n); i++) {
        if (prime[i]) {
            for (int j = i*i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        if (prime[i]) count++;
    }
    return count;
}

int main() {
    cout << countPrimes(10);
}