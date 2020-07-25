// Given an unsorted integer array, find the smallest missing positive integer.

// Example 1:

// Input: [1,2,0]
// Output: 3
// Example 2:

// Input: [3,4,-1,1]
// Output: 2
// Example 3:

// Input: [7,8,9,11,12]
// Output: 1
// Note:

// Your algorithm should run in O(n) time and uses constant extra space.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // pushing all negatives to the right
        int n = nums.size();
        int rightpos = n-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<1){
                if(i!=rightpos){
                    swap(nums[i],nums[rightpos]);
                }
                rightpos--;
            }
        }
        
        // marking all positives in range from 0 to rightpos+1 
        for(int i=0;i<=rightpos;i++){
            int curr = abs(nums[i]);
            if(curr<=rightpos+1){
                // condition beacuase of more than one occurence
                if(nums[curr-1]>0)
                    nums[curr-1]*=-1;
            }
        }
        
        // answer will be first postive index+1 in 0 to rightpos+1
        for(int i=0;i<=rightpos;i++){
            if(nums[i]>0) {
                return i+1;
            }
        }
        return rightpos+2;
    }
};