// Given two binary trees, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

// Example 1:

// Input:     1         1
//           / \       / \
//          2   3     2   3

//         [1,2,3],   [1,2,3]

// Output: true


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool SameTree(TreeNode* p, TreeNode* q){
        if(p==NULL and q==NULL) return true;
        
        else if(p!=NULL and q!=NULL){
            bool curr = (p->val == q->val); 

            bool left = SameTree(p->left,q->left);
            bool right = SameTree(p->right,q->right);

            if(left and right and curr) return true;
            else return false;
        }
        
        return false;

    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return SameTree(p,q);
    }
};