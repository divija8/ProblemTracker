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
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = head, *prev = NULL, *Nnode;
        while(temp != NULL){
            Nnode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = Nnode;
        }
        return prev;

    }
};

