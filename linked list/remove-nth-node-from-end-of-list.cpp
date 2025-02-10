#include <iostream>

using namespace std;


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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head->next == nullptr && n == 1) {
                return nullptr;
            }
            std::unordered_map<int, ListNode*> map;
            int index = 0;
            ListNode* temp = head;
            while(temp != nullptr) {
                map[index] = temp;
                temp = temp->next;
                index++;
            }
            int toRemove = index - n;
            ListNode* prev = map[toRemove - 1];
            ListNode* next = map[toRemove + 1];
            if(prev == nullptr) {
                return next;
            }
            prev->next = next;
            return head;
        }
    };



int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);


    Solution s;
    ListNode* result = s.removeNthFromEnd(head, 2);

    // return should be 1 2 3 5

    for(ListNode* temp = result; temp != nullptr; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;

}