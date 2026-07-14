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

ListNode* reversek(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(curr != NULL){
        ListNode* nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    return prev;
}

ListNode* findkth(ListNode* temp, int k){
    while(temp != NULL && k>0){
        k--;
        temp= temp->next;
    }
    return temp;
}

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* kth = findkth(temp,k-1);
            if(kth == NULL){
                if(prev){
                    prev->next = temp;
                    break;
                }
            }
            ListNode* nextnode = kth->next;
            kth->next = NULL;
            reversek(temp);
            if(temp == head){
                head = kth;
            } else{
                prev->next = kth;
            }
            prev = temp;
            temp = nextnode;
        }
        return head;
    }
};