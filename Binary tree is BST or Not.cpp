// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:

//     2
//    / \
//   1   3

// Input: [2,1,3]
// Output: true
// Example 2:

//     5
//    / \
//   1   4
//      / \
//     3   6

// Input: [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.



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
    
    vector<int> in_tr;
    
    // Recursive 
    
    
    bool isBST(TreeNode* root,long long int mini, long long int maxi){
        if(!root) return true;
        else{
            bool left = isBST(root->left,mini,root->val);
            bool right = isBST(root->right,root->val,maxi);
            long long int ro = root->val, le = LLONG_MIN, ri = LLONG_MAX;
            if(root->left) le = root->left->val;
            if(root->right) ri = root->right->val;
            
            return (left and right and (ro>le) and (ro<ri) and (ro<maxi) and (ro>mini));
        }
    }   
    
    // By Inorder Traversal
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        
	    in_tr.push_back(root->val);
        inorder(root->right);
    }
    
    bool isBST_Inorder(TreeNode* root){
        if(in_tr.size() ==0) return true;
        else{
        
            long long int prev = LLONG_MIN;
            for(int i=0;i<in_tr.size();i++){
                
                if(in_tr[i]<=prev) return false;
                else prev = in_tr[i];
            }
        }
        return true;
    }
    
    
    
    bool isValidBST(TreeNode* root) {
        
        //recursive
        return isBST(root,LLONG_MIN,LLONG_MAX);
        
        // inoder
        inorder(root);
        return isBST_Inorder(root);
        
    }
};