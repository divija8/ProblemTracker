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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) {
                ListNode *matched = head;
                while(slow != matched){
                    matched = matched->next;
                    slow = slow->next;
                }
            return matched;
            }
        }
    return NULL;
    }
};