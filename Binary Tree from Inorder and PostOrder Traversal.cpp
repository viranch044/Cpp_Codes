// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7


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
#define spa " "
class Solution {
public:
    
    TreeNode *func(vector<int>& inorder,vector<int>& postorder,int si,int ei,int sp,int ep,int curr){
        
//         cout<<si<<spa<<ei<<spa<<sp<<spa<<ep<<endl;
        
//         cout<<curr<<endl;
        int split_index ;
        for(int i=si;i<=ei;i++){
            if(inorder[i] == postorder[ep]) {
                split_index = i;
                break;
            }
        }
        // cout<<split_index<<endl;
        TreeNode* le;
        TreeNode *ri;
        if(split_index == ei){
            ri = NULL;
        }
        else{
            int end_post = ep-1;
            ri = func(inorder,postorder,split_index+1,ei,ep-(ei-split_index),ep-1,postorder[end_post]);
        }
        if(split_index == si){
            le = NULL;
            
        }
        else{
            int end_post = sp+(split_index-si-1);
            le = func(inorder,postorder,si,split_index-1,sp,end_post,postorder[end_post]);
        }
        TreeNode *temp = new TreeNode(curr);
        temp->left = le;
        temp->right = ri;
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n==0) return NULL;
        return func(inorder,postorder,0,n-1,0,n-1,postorder[n-1]);
    }
};