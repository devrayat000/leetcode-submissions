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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        dummy1->next = l1;
        dummy2->next = l2;
        dummy1->next = addTwoNumbers(dummy1->next, dummy2->next, 0);
        return dummy1->next;
    }

private:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2) {
            return carry > 0 ? new ListNode(carry) : nullptr;
        }

        if (!l1) {
            l1 = new ListNode(0);
        }
        if (!l2) {
            l2 = new ListNode(0);
        }

        int sum = l1->val + l2->val + carry;
        carry = sum / 10;
        l1->val = sum % 10;
        l1->next = addTwoNumbers(l1->next, l2->next, carry);
        return l1;
    }
};