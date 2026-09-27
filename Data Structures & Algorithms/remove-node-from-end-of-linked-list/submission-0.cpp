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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int length = 0;
        while(curr != nullptr){
            length++;
            curr = curr->next;
        }
        int node_from_beginning = length - n;
        if(node_from_beginning == 0) return head->next;
        curr = head;
        for(int i = 0; i < length - 1; i++){
            if((i + 1) == node_from_beginning) curr->next = curr->next->next;
            curr = curr->next;
        }
        return head;
    }
};
