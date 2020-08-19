// Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

// Example 1:

// Input: "abab"
// Output: True
// Explanation: It's the substring "ab" twice.
// Example 2:

// Input: "aba"
// Output: False
// Example 3:

// Input: "abcabcabcabc"
// Output: True
// Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

class Solution {
public:
    
    
    
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i=n/2;i>=1;i--){
            if(n%i == 0){
                int re = (n/i);
                string temp = s.substr(0,i);
                string kk;
                for(int j=1;j<=re;j++) kk+=temp;
                if(kk == s) return true;
            }
        }
        
        return false;
        
        
        another solution:
        There are 3 major parts in the code.
        Part 1 ---Double the original string to get a new string:s+s
        Part 2 ---Scan the new string from the second charactor to the end with the original string: substr(1,2*s.size()-1).find(s)
        Part 3 ---If you can find it before the beginning of the second half of the new string: s.size()-1,
        that means the original string has a repeated pattern, otherwise it doesn't.

        class Solution {
        public:
            bool repeatedSubstringPattern(string s) 
            {  return (s+s).substr(1,2*s.size()-1).find(s)!=s.size()-1;  }
        };
    }
};