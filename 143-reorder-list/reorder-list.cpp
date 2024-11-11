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
        if ( !head or !head->next or !head->next->next) return;
        ListNode *slow, *fast;
        slow = head;
        fast = head;
        while( fast and fast->next) {
            // ?f = curr;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = nullptr, *curr = slow, *next;
        while ( curr ) {    //start -> the point where to reverse from 
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* first = head, *second = prev;
        while ( second->next ) {
            ListNode* temp1 = first->next;
            ListNode* temp2  = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }

        return;
    }
};