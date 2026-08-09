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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        int k = lists.size();
        // Divide and conquer: merge pairs of lists iteratively
        while (k > 1) {
            for (int i = 0; i < k / 2; i++) {
                // Merge list from the front with a list from the back
                lists[i] = mergeTwoLists(lists[i], lists[k - 1 - i]);
            }
            // Reduce the active size of lists to check by half
            k = (k + 1) / 2;
        }

        return lists[0];
    }

private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if (list1 != nullptr) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }

        return dummy.next;
    }
};