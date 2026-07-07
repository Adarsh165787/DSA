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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n =0;
        ListNode* temp = head;
        vector<ListNode*> ans;

        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        int size = n/k;
        int extra = n%k;

        ListNode* curr = head;
        for(int i =0;i<k;i++){
            if(curr == NULL){
                ans.push_back(curr);
                continue;
            }
            ans.push_back(curr);
            int prtsize = size;
            if(extra >0){
                prtsize++;
                extra--;
            }
            for(int i =1;i<prtsize;i++){
                curr = curr->next;
            }
            ListNode* next = curr->next;
            curr->next = NULL;
            curr = next;
        }
    return ans;
    }
};