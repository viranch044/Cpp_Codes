// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

// Example:

// Input:  [1,2,1,3,2,5]
// Output: [3,5]
// Note:

// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int k = 0;
        for(auto i:nums){
            k = k^i;
        }
        int x = 0,y= 0,is_set;
        for(int i=0;i<32;i++){
            int curr = 1<<i;
            is_set = k&curr;
            if(is_set) break;
        }
        for(auto i:nums){
            if(i & is_set) x = x^i;
            else y = y^i;
        }
        return {x,y};
    }
};