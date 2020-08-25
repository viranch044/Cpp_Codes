// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Note:

// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like ? or *.
// Example 1:

// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input:
// s = "aa"
// p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input:
// s = "cb"
// p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
// Example 4:

// Input:
// s = "adceb"
// p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
// Example 5:

// Input:
// s = "acdcb"
// p = "a*c?b"
// Output: false


// First reduce pattern by removing continuous * in it. Then By Dp it's simple question.

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, n = s.length(), m = p.length();
        string re;
        for(int i=0, j=0;i<m;i++){
            for(j = i;j+1<m&&(p[j+1]==p[j] && p[j]=='*');j++);
            i = j;
            re+=p[j];
        }
        
        // re is updated p;
        
        p = re;
        
        cout<<p<<endl;
        
        
        m = p.length();
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        
        dp[0][0] = 1;
        if(p[0]=='*') dp[0][1] = 1;
        else{
            for(int i=1;i<=m;i++) dp[0][i] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0) dp[i][j] = 0;
                else{
                    if(p[j-1]==s[i-1] or p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                    else if(p[j-1]=='*') dp[i][j] = dp[i-1][j] | dp[i][j-1];
                    else dp[i][j] = 0;
                }
            }
        }
        
        return dp[n][m];
    }
};