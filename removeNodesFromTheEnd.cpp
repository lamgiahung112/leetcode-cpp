#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> nodes;
    ListNode *start = head;
    int it = -1;
    while (true) {
        if (!head) {
            //delete at the start
            if (it + 1 == n) {
                if (nodes.size() > 1) {
                    start = nodes[1];
                } else {
                    start = nullptr;
                }
            }
            // delete in the middle
            else if (n != 1) {
                nodes[it - n]->next = nodes[it - n + 2]; 
            }
            // delete at the end
            else {
                nodes[it - 1]->next = nullptr;
            }
            break;
        }
        nodes.push_back(head);
        head = head->next;
        it++;
    }
    return start;
}

int main() {
    ListNode *one = new ListNode(5);
    ListNode *two = new ListNode(4, one);
    ListNode *three = new ListNode(3, two);
    ListNode *four = new ListNode(2, three);
    ListNode *five = new ListNode(1, four);

    removeNthFromEnd(five, 2);
}