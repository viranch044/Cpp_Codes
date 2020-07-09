// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:

// The solution set must not contain duplicate triplets.

// Example:

// Given array nums = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left,right = nums.size()-1;
        vector<vector<int>> res;
        for(int i=0;i<n-1;i++){
            if((i!=0 and nums[i-1]!=nums[i]) or i==0 ){                                 // First condition is for avoiding same pairs
                    int curr = nums[i]*-1;
                    left = i+1;
                    right = n-1;
                    unordered_map<int,bool> m;
                    while(left<right){
                        if(nums[left]+nums[right]>curr) right--;
                        else if(nums[left]+nums[right]<curr) left++;
                        else{
                        if(!m[nums[left]])                                              // map to avoid same duplcate pairs
                        {
                            res.push_back({nums[i],nums[left],nums[right]});
                            m[nums[left]] = true;
                        }
                        left++;
                        right--;
                    }
                }
            }
            
            
        }
        return res;
    }
};
