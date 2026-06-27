/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

ListNode *collisionpoint(ListNode *head1, ListNode *head2,int d){
    while(d){
        d--;
        head2 = head2->next;
    }
    while(head1 != head2){
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}

    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode *t1 = head1;
        ListNode *t2 = head2;
        int n1 =0,n2=0;
        while(t1 != NULL){
            t1 = t1->next;
            n1++;
        }
        while(t2 != NULL){
            t2 = t2->next;
            n2++;
        }
        if(n1 <n2){
            return collisionpoint(head1,head2,n2-n1);
        }
        else{
            return collisionpoint(head2,head1,n1-n2);
        }
        // return 0;
    }
};