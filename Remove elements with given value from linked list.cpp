// Remove all elements from a linked list of integers that have value val.

// Example:

// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5


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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            if(temp->val == val)
            {
                temp = temp->next;
                
            }
            else break;
        }
        head = temp;
        prev = temp;
        if(temp == NULL) return NULL;
        temp = temp->next;
        while(temp!=NULL){
            if(temp->val == val){
                prev->next = temp->next;
            }
            else{
                prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};