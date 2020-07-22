// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]




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
#define ss second
#define ff first
#define pb push_back
class Solution {
public:
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root) return {};
        
        
        deque<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;
        q.push_back({root,0});
        unordered_map<int,vector<int>> m;
        int maxi = INT_MIN;
        while(!q.empty()){
            auto FR = q.front();
            auto BA = q.back();
            TreeNode* le = FR.ff;
            TreeNode* ri = BA.ff;
            int ll = FR.ss;
            int rl = BA.ss;
            maxi = max(max(ll,rl),maxi);
            if(ll == rl){
                // new level has come
                // so if even level then pop from left and push at back
                if(ll%2 == 0){
                    q.pop_front();
                    m[ll].pb(le->val);
                    if(le->left!=NULL){
                        q.push_back({le->left,ll+1});
                    }
                    if(le->right!=NULL){
                        q.push_back({le->right,ll+1});
                    }
                }
                // else pop from right and push at front
                else{
                    q.pop_back();
                    m[rl].pb(ri->val);
                    if(ri->right!=NULL){
                        q.push_front({ri->right,rl+1});
                    }
                    if(ri->left!=NULL){
                        q.push_front({ri->left,rl+1});
                    }
                }
            }
            else{
                if(ll<rl){
                    q.pop_front();
                    m[ll].pb(le->val);
                    if(le->left!=NULL){
                        q.push_back({le->left,ll+1});
                    }
                    if(le->right!=NULL){
                        q.push_back({le->right,ll+1});
                    }
                }
                else{
                    q.pop_back();
                    m[rl].pb(ri->val);
                    if(ri->right!=NULL){
                        q.push_front({ri->right,rl+1});
                    }
                    if(ri->left!=NULL){
                        q.push_front({ri->left,rl+1});
                    } 
                }
                
            }
        }
        for(int i=0;i<=maxi;i++){
            ans.pb(m[i]);
        }
        
        return ans;
    }
};