// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int up = 0;
        ListNode *ans = new ListNode();
        ListNode *temp = ans;
        while(l1 or l2){
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            temp->val = (a + b + up)%10;
            up = (a+ b + up)/10;
            
            int cond1 =0 , cond2 = 0;
            if(l1 and l1->next) cond1 = 1;
            if(l2 and l2->next) cond2 = 1;
            if(up or cond1 or cond2){
                ListNode *curr = new ListNode();
                temp->next = curr;
                temp = temp->next;
            }
            
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        
        if(up) temp->val = up;
        
        
        return ans;
        
    }
};