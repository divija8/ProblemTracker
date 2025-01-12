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
        ListNode* temp = head;
        int N = 0;
        while(temp!=NULL){
            temp = temp->next;
            N++;
        }
        int index = N-n;
        if(index == 0) {
            return head->next;
        }
        temp = head;
        for(int i = 0;i<N-1;i++){
            if((i+1) == index){
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};