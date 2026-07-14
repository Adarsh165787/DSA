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

ListNode* merge(ListNode* head1, ListNode* head2){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    while(head1 != NULL && head2 != NULL){
        if(head1->val < head2->val){
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        } else{
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }

    }
        if(head1) {
            temp->next = head1;
        } else{
            temp->next = head2;
        }
    return dummy->next;
}


ListNode* solve(vector<ListNode*>& lists,int low,int high){
    if(low == high) return lists[low];
    int mid = low +(high-low)/2;
    ListNode* left = solve(lists,low,mid);
    ListNode* right = solve(lists,mid+1,high);
    return merge(left,right);

}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        return solve(lists,0,n-1);
    }
};