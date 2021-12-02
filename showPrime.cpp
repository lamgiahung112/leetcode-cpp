#include <bits/stdc++.h>

using namespace std;

void showPrimes(int n) {
    vector<bool> primes (n + 1, true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (primes[i]) {
            for (int j = i*i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (primes[i]) cout << i << " ";
    }
}

int main() {
    showPrimes(20);
}