// Given a non-empty array of integers, return the k most frequent elements.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
// Note:

// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
// It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
// You can return the answer in any order.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int> m;
        int n = nums.size();
        for(auto i:nums){
             m[i]++;
        }
        unordered_map<int,vector<int>> p;
        for(auto j:m){
            p[j.second].push_back(j.first);
        }
        vector<int> res;
        int flag = 0;
        for(int i=n;i>=1;i--){
            for(auto j:p[i]){
                if(k>0) {
                    res.push_back(j);
                    k--;
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) break;
        }
        return res;
    }
};