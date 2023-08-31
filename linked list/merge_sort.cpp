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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {

        if(first ==nullptr){
            return second;
        }
        if (second == nullptr){
            return first;
        }

        ListNode *head = nullptr;
        ListNode *list = nullptr;
        while((first != nullptr && second!=nullptr )){
            ListNode *newNode;
            if (first -> val < second -> val){
                newNode = new ListNode(first->val);
                first = first -> next;
            }else{
                newNode = new ListNode(second->val);
                second = second -> next;
            }
            if (head == nullptr && list == nullptr){
                head = newNode;
                list = head;
            }else{
                list->next = newNode;
                list = list -> next;
            }
        }
        while(first != nullptr){
            if(head == nullptr){
                head = new ListNode(first->val);
                list = head;
            }else{
                list->next = new ListNode(first->val);
                list = list->next;
            }
            first = first -> next;
        }
        while(second != nullptr){
            if(head == nullptr){
                head = new ListNode(second->val);
                list = head;
            }else{
                list->next = new ListNode(second->val);
                list = list->next;
            }
            second = second -> next;
        }
        return head;
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ListNode *first = new ListNode(2);


    ListNode *second = new ListNode(1);


    cout<<"First list: ";
    ListNode *temp = first;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;


    cout<<"Second list: ";
    temp = second;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;



    Solution obj;
    ListNode *result = obj.mergeTwoLists(first, second);
    while(result != NULL){
        cout<<result->val<<" ";
        result = result->next;
    }

    return 0;
}