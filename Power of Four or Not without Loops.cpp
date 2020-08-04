// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

// Example 1:

// Input: 16
// Output: true
// Example 2:

// Input: 5
// Output: false
// Follow up: Could you solve it without loops/recursion?


class Solution {
public:
    
    // power of four = power of two, with the set bit appearing at an odd position
    
    // 0x55555555 is the 32 bit number whose all odd bits are set starting from 1st from left
    // 0xAAAAAAAA is the 32 bit number whose all even bits are set starting from 1st from left 

    bool isPowerOfFour(int num) {
        return num > 0 and (num & (num - 1)) == 0 and (num & 0x55555555);
    }
    
};