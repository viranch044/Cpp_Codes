// Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

// The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

// Example 1:

// Input: 

//            1
//          /   \
//         3     2
//        / \     \  
//       5   3     9 

// Output: 4
// Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

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
    
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        deque<TreeNode*> q;
        q.push_back(root);
        int ans = 0;
        while(!q.empty()){
            while(!q.empty() and q.front()==NULL) q.pop_front();
            while(!q.empty() and q.back()==NULL) q.pop_back();
            
            
            int curr = q.size();
            ans = max(ans,curr);
            
            for(int i=0;i<curr;i++){
                TreeNode* t = q.front();
                q.pop_front();
                
                if(t){
                    q.push_back(t->left);
                    q.push_back(t->right);
                }
                else{
                    q.push_back(NULL);
                    q.push_back(NULL);
                }
            }
            
        }
        return ans;
        
        
    }
};