#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *first, ListNode *second)
    {

        if (first == nullptr)
        {
            return second;
        }
        if (second == nullptr)
        {
            return first;
        }
        int remainder = 0;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        
        // old 


        // while ((first != nullptr && second != nullptr))
        // {
        //     int num =  first->val + second->val + remainder;
        //     remainder = num / 10;
        //     first = first->next;
        //     second = second->next;
        //     if(head == nullptr){
        //         tail = new ListNode(num%10);
        //         head = tail;
        //     }else{
        //         tail->next = new ListNode(num%10);;
        //         tail = tail->next;
        //     }
        // }
        // while(first != nullptr){
        //     int num = first->val + remainder;
        //     remainder = num / 10;
        //     first = first->next;
        //     tail->next = new ListNode(num%10);;
        //     tail = tail->next;
        // }
        // while(second != nullptr){
        //     int num = second->val + remainder;
        //     remainder = num / 10;
        //     second = second->next;
        //     tail->next = new ListNode(num%10);;
        //     tail = tail->next;
        // }


        while(first != nullptr || second != nullptr){
            int num = (first? first->val:0) + (second? second->val:0) + remainder;
            remainder = num / 10;
            if (first != nullptr){
                first = first->next;
            }
            if (second != nullptr){
                second = second->next;
            }
            if(head != nullptr){
                tail->next = new ListNode(num%10);
                tail = tail->next;
                continue;
            }
            tail = new ListNode(num%10);
            head = tail;
        }


        if (remainder != 0){
            tail -> next = new ListNode(remainder);
            tail = tail -> next;
        }
        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ListNode *first = new ListNode(9);
    first -> next = new ListNode(9);
    first -> next -> next = new ListNode(9);
    first -> next -> next -> next = new ListNode(9);
    first -> next -> next -> next -> next = new ListNode(9);
    first -> next -> next -> next -> next -> next = new ListNode(9);
    first -> next -> next -> next -> next -> next -> next = new ListNode(9);

    ListNode *second = new ListNode(9);
    second -> next = new ListNode(9);
    second -> next -> next = new ListNode(9);
    second -> next -> next -> next = new ListNode(9);

    cout << "First list: ";
    ListNode *temp = first;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Second list: ";
    temp = second;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    Solution obj;
    ListNode *result = obj.addTwoNumbers(first, second);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}