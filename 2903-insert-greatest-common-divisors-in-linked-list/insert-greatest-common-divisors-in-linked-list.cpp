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
    int gcd(int a, int b) {
        while(b!= 0){
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *temp = head;
        while(temp != NULL && temp->next != NULL) {
            int x = temp->val;
            int y = temp->next->val;
            int res = gcd(x, y);
            ListNode *gcdNode = new ListNode(res);
            gcdNode->next = temp->next;
            temp->next = gcdNode;
            temp = gcdNode->next;
        }
        return head;
    }
};