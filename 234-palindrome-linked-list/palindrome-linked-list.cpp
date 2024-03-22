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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *prev = NULL;
        while(slow!=NULL){
            ListNode *temp= NULL;
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        ListNode *left = head;
        ListNode *right = prev;
        while(right!=NULL){
            if(left->val != right->val){
                return false;
            }
            left=left->next;
            right=right->next;
        }
       return true;
    }
};