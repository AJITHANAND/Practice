#include <iostream>
#include <vector>
/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *current = head;
        while(current != nullptr){
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};





int main() {
    Solution s;
    std::vector<int> v = {1,2,3,4,5};
    ListNode* head = new ListNode(v[0]);
    ListNode* current = head;
    for (int i = 1; i < v.size(); i++) {
        current->next = new ListNode(v[i]);
        current = current->next;
    }
    ListNode* result = s.reverseList(head);
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;
}