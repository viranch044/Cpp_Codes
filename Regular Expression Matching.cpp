// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

// Note:

// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like . or *.
// Example 1:

// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input:
// s = "aa"
// p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// Example 3:

// Input:
// s = "ab"
// p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
// Example 4:

// Input:
// s = "aab"
// p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
// Example 5:

// Input:
// s = "mississippi"
// p = "mis*is*p*."
// Output: false


For Dp approch 

if both character are equal or curr_char == '.' then check dp[i-1][j-1];
else if curr_char == '*' then 2 things  1. Take zero occurence of previous char 
                                        2. if(curr_char is matching with character before or prev_char is '.' * then chack dp[i-1][j] with consideration that char into * )

class Solution {
public:
    bool isMatch(string s, string p) {
        
        // Recursive Approch
        
        if(p.length()== 0){
            return (s.length()==0);
        }
        if(p.length()>1 and p[1]=='*'){
            if(isMatch(s,p.substr(2))) 
                return true;
            if(s.length()>0 and (s[0]==p[0] or p[0]=='.')){
                return isMatch(s.substr(1),p);
            }
            return false;
        }
        else{
            if(s.length()>0 and (s[0]==p[0] or p[0]=='.')){
                return isMatch(s.substr(1),p.substr(1));
            }
            return false;
        }
        
        // Dp approch
        
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+2,vector<int>(m+2));
        
        dp[0][0] = 1;
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*') dp[0][i] = dp[0][i-2];
        }
        
        for(int i=1;i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(j==0) dp[i][j] = 0;
                else if(s[i-1] == p[j-1] or (p[j-1]=='.')){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    int val = 0;
                    val = val | dp[i][j-2];
                    if(p[j-2]=='.' or (p[j-2]==s[i-1])) {
                        val = val | dp[i-1][j];
                    }
                    dp[i][j] = val;
                }
                else dp[i][j] = 0;
            }
        }
        
        
        return dp[n][m];
    }
};