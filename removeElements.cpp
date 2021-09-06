#include <iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val) {
    if (!head) return nullptr;
    ListNode *start = head;

    ListNode *prev = head;

    //delete nodes at the beginning
    while (head->val == val && head->next) {
        head = head->next;
        start = head;
        prev = head;
    }

    while (head->next) {
        while (head->next && head->val == val) {
            head = head->next;
            prev->next = head;
        }

        if (head->next) {
            prev = head;
            head = head->next;
        }
    }


    //last element
    if (head->val == val) {
        prev->next = nullptr;
        if (head == start) {
            return nullptr;
        }
    }
    return start;
}

int main() {
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2, one);
    ListNode *three = new ListNode(1, two);

    ListNode *test = removeElements(three, 2);
}
