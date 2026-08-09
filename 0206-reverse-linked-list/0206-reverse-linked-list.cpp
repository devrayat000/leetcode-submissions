/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* rHead = nullptr;
        ListNode* tmp = nullptr;
        auto curr = head;
        while (curr != nullptr) {
            tmp = curr->next;
            curr->next = rHead;
            rHead = curr;
            curr = tmp;
        }
        return rHead;
    }
};