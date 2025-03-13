#include <iostream>
#include <set>
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
        void reorderList(ListNode* head) {
            if (head == nullptr || head->next == nullptr) {
                return;
            }
            std::vector<ListNode*> nodes;
            ListNode *temp = head;
            while( temp != nullptr) {
                nodes.push_back(temp);
                temp = temp->next;
            }
            int left = 0;
            int right = nodes.size() - 1;
            ListNode *tempHead = new ListNode(0);
            temp = tempHead;
            while(left <= right){
                temp->next = nodes[left];
                temp = temp->next;
                left++;
                if (left<=right) {
                    temp->next = nodes[right];
                    temp = temp->next;
                    right--;
                }
            }
            temp->next = nullptr;
        }
    };


int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    sol.reorderList(head);

    ListNode *temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << endl;
    return 0;
}