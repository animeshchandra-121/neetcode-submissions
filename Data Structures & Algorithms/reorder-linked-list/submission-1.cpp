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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        return;
        ListNode* middle = find_middle(head);
        ListNode* left = head;
        ListNode* right = reverse(middle->next);
        middle->next = nullptr;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        bool isleft = true;
        while(left && right){
            if(isleft){
                tail->next = left;
                left = left->next;
                isleft = false;
            }else{
                tail->next = right;
                right = right->next;
                isleft = true;
            }
            tail = tail->next;
        }
        tail->next = left?left:right;
    }
    ListNode* find_middle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
