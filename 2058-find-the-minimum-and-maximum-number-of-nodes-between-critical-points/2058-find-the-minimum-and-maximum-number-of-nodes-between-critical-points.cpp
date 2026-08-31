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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        int ind =1;
        vector<int> arr;
        while(next!= NULL){
            bool maxi = (curr->val < next->val && curr->val < prev->val);
            bool mini = (curr->val > next->val && curr->val > prev->val);
            if(mini || maxi){
                arr.push_back(ind);
            }
            ind++;
            prev = curr;
            curr = next;
            next = next->next;
        }
        if(arr.size() < 2) return {-1,-1};
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i =1;i<arr.size();i++){
           mini = min(mini, arr[i] - arr[i-1]);
        }
        maxi = arr[arr.size()-1]- arr[0];
        return {mini,maxi};
    }
};