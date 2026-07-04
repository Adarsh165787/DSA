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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;    // returns node before the middle
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (left && right) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        tail->next = (left) ? left : right;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* midPrev = findMiddle(head);
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return merge(left, right);
    }
};