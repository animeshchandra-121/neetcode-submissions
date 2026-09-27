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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL; ListNode* prev_of_left = NULL;
        ListNode* end = NULL; ListNode*  next_after_right = NULL;
        int i = 1;
        ListNode* curr = head;
        while(curr && i <= right){
            if(i < left){
                prev_of_left = curr;
            }
            if(i == left){
                prev = curr;
            }
            if(i == right){
                end = curr;
                next_after_right = end->next;
            }
            curr = curr->next;
            i++;
        }
        end->next = NULL;
        end = reverse(prev);
        if(prev_of_left){
            prev_of_left->next = end;
        }else{
            head = end;
        }
        prev->next = next_after_right;
        return head;
    }
    ListNode* reverse(ListNode *head) {
        ListNode *prevNode = NULL;
        ListNode *currNode = head;
        while (currNode) {
            ListNode *nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
};