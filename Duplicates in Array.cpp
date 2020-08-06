// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

// Find all the elements that appear twice in this array.

// Could you do it without extra space and in O(n) runtime?

// Example:
// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [2,3]

class Solution {
public:
    vector<int> findDuplicates(vector<int>& ve) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int n = ve.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            int curr = abs(ve[i]);
            if(ve[curr-1]<0){     // Appearing second time
                ans.push_back(curr);        
            }
            else {
                ve[curr-1]*=-1;
            }
        }
        
        
        return ans;
    }
};