/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

void insertCopyinbw(Node* head){
    Node* temp = head;
    while(temp !=NULL){
        Node * nextele = temp->next;
        Node* copy = new Node(temp->val);
        copy->next = nextele;
        temp->next = copy;
        temp = nextele;
    }
}

void connectrendom(Node* head){
     Node* temp = head;
    while(temp != NULL){
        Node* copy = temp->next;
        if(temp->random){
            copy->random = temp->random->next;
        } else{
            copy->random = NULL;
        }
        temp = temp->next->next;
    }

}
Node* getcopyLL(Node* head) {
    Node* temp = head;
    Node* dummy = new Node(-1);
    Node* rest = dummy;
    while(temp != NULL){
        rest->next = temp->next;
        rest = rest->next;

        temp->next = temp->next->next;
        temp = temp->next;

    }
        return dummy->next;
}

    Node* copyRandomList(Node* head) {
        insertCopyinbw(head);
        connectrendom(head);
        return getcopyLL(head);
    }
};