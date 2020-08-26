// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Example 1:

// Input: [3,2,3]
// Output: 3
// Example 2:

// Input: [2,2,1,1,1,2,2]
// Output: 2

class Solution {
public:
    
    
    // Finding candidate for majority elements
    int candidate(vector<int>& nums,int n){
        int maj_ind = 0, cnt = 1;
        for(int i=1;i<n;i++){
            if(nums[maj_ind] == nums[i]) cnt++;
            else cnt--;
            if(cnt == 0){
                maj_ind = i;
                cnt = 1;
            }
        }
        
        return nums[maj_ind];
    }
    
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand = candidate(nums,n), cnt = 0;
        for(auto i:nums){
            if(i==cand) cnt++;
        }
        
        // chack if it is majority or not
        
        if(cnt>(n/2)) return cand;
        return cand;
    }
};