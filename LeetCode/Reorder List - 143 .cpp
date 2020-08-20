// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example 1:

// Given 1->2->3->4, reorder it to 1->4->2->3.
// Example 2:

// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

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
        if(!head) return;
        ListNode *ff = head, *ss = head, *temp = NULL;
        
        while(ss!=NULL and ss->next!=NULL){
            temp = ff;
            ff = ff->next;
            ss = ss->next->next;
        }
        
        if(ss!=NULL) {
            temp = ff;
            ff = ff->next;
        }
        
        temp->next = NULL;
        
        ListNode *prev = temp, *curr = ff;
        
        while(curr!=NULL){
            ListNode* tt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tt;
        }
        
        // cout<<prev->next->val<<" | ";

        
        ListNode* start = head;
        while(start!=NULL){
            // cout<<prev->val<<" | ";

            ListNode* tt = start->next;
            ListNode* nn = (prev!=NULL) ? prev->next : NULL;
            start->next = prev;
            if(prev!=NULL)
                start->next->next = tt;
            start = tt;
            prev = nn;
        }
        
    }
};// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example 1:

// Given 1->2->3->4, reorder it to 1->4->2->3.
// Example 2:

// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

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
        if(!head) return;
        ListNode *ff = head, *ss = head, *temp = NULL;
        
        while(ss!=NULL and ss->next!=NULL){
            temp = ff;
            ff = ff->next;
            ss = ss->next->next;
        }
        
        if(ss!=NULL) {
            temp = ff;
            ff = ff->next;
        }
        
        temp->next = NULL;
        
        ListNode *prev = temp, *curr = ff;
        
        while(curr!=NULL){
            ListNode* tt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tt;
        }
        
        // cout<<prev->next->val<<" | ";

        
        ListNode* start = head;
        while(start!=NULL){
            // cout<<prev->val<<" | ";

            ListNode* tt = start->next;
            ListNode* nn = (prev!=NULL) ? prev->next : NULL;
            start->next = prev;
            if(prev!=NULL)
                start->next->next = tt;
            start = tt;
            prev = nn;
        }
        
    }
};