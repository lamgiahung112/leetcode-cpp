#include <vector>

using namespace std;

vector<int> generate(int numRows) {
    if (numRows == 0) return {1};
    if (numRows == 1) return {1,1};

    vector<vector<int>> triangle (numRows + 1);
    triangle[0] = {1};
    triangle[1] = {1,1};
    for(int i = 2; i < numRows + 1; i++) {
        triangle[i].push_back(1);
        for(int j = 1; j < i; j++) {
            int value = triangle[i - 1][j - 1] + triangle[i - 1][j];
            triangle[i].push_back(value);
        }
        triangle[i].push_back(1);
    }
    return triangle[numRows];
}

int main() {
    generate(0);
}