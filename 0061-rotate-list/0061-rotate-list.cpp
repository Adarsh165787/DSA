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
    ListNode* rotateRight(ListNode* head, int k) {
        int n =1;
        ListNode * temp = head;
         if(head == NULL || head->next == NULL || k == 0)
            return head;
        while( temp->next != NULL){
            temp = temp->next;
            n++;
        }
        k = k % n;
        if(k ==0) return head;
        temp->next = head;
        int step = n-k-1;
        ListNode *newtail = head;
        for(int i =0;i<step;i++){
            newtail= newtail->next;
        }
        ListNode *newhead = newtail->next;
        newtail->next = NULL;
        return newhead;
    }
};