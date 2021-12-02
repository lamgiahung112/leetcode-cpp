#include <bits/stdc++.h>

using namespace std;

int canCompleteCircuit(vector<int> gas, vector<int> cost) {
    int n = gas.size();
    
    int i = 0, j = 0;
    int tank = 0;
    while (i < n) {
        tank += gas[j];

        if (tank >= cost[j]) {
            tank -= cost[j];

            j = (j+1) % n;
            if (i == j) return i;
        }
        else {
            j++;
            tank = 0;

            if (j > i) i = j;
            else return -1;
        }
    }
    return -1;
}


int main() {
    canCompleteCircuit({4,5,3,1,4}, {5,4,3,4,2});
}