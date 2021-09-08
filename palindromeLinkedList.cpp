#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head) {
    vector<int> nodeValues;
    ListNode *start = head;

    while (head) {
        nodeValues.push_back(head->val);
        head = head->next;
    }

    int left = 0;
    int right = nodeValues.size() - 1;

    while (left < right) {
        if (nodeValues[left] != nodeValues[right]) return false;
        left++;
        right--;
    }
    return true;
}