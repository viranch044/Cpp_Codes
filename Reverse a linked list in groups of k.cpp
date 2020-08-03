// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// Example:

// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

// Note:

// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be changed.


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode *var = head, *prev = NULL, *temp = head, *start = NULL, *ageka = NULL;
        
        
        // ageka is storing First of the current part so that we can point it to lat of next portion
        // var is for checking if next portion's length is less than k or not
        int i = k;
        
        bool flag = true;
        while(flag){
            i = k;
            ListNode* k = var;
            while(i!=0 and var){
                var = var->next;
                i--;
            }
            
            // cout<<i<<endl;
            
            if(i==0){
                start = temp;
                while(temp!=var){
                    ListNode *nexti = temp->next;
                    temp->next = prev;
                    prev = temp;
                    temp = nexti;
                }
                
                // First Portion 
                if(ageka == NULL){
                    head = prev;
                    ageka = start;
                }
                else{
                    ageka->next = prev;
                    ageka = start;
                }
                
                // point last portion's starting to Null
                if(!var) ageka->next = NULL;
            }
            else{
                
                // point last valid portion's start to last incomplte portion's start
                ageka->next = k;
                flag = false;
            }
            
        }
        
        return head;
        
        
    }
};