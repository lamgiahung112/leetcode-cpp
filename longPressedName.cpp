#include <string>
#include <iostream>

using namespace std;

bool isLongPressedName(string name, string typed) {
    char prev = name[0];
        int it = 0;
        
        for (int i = 0; i < name.size(); i++) {
            while (typed[it] != name[i]) {
                if (typed[it] != prev) return false;
                it++;
            }
            prev = name[i];
            it++;
        }
        while (it < typed.size()) {
            if (typed[it] != name[name.size() - 1]) return false;
            it++;
        }
        return true;
}

int main() {
    cout << isLongPressedName("alex","aaleex");
}