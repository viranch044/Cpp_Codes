// Given two binary strings, return their sum (also a binary string).

// The input strings are both non-empty and contains only characters 1 or 0.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

class Solution {
public:
    string addBinary(string a, string b) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n= a.length();
        int m = b.length();
        int k = max(n,m);
        int carry[k+1];
        string res;
        carry[k] = 0;
        int A,B,curr;
        for(int i=k;i>0;i--){
            A = (n>0 and a[n-1]=='1') ? 1:0;
            B = (m>0 and b[m-1]=='1') ? 1:0;
            curr = (A^B)^carry[i];
            if(curr) res+='1';
            else res+='0';
            carry[i-1] = (A&B) | (carry[i]&(A^B));
            n--;
            m--;
        }
        if(carry[0]==1) res+='1';
        reverse(res.begin(), res.end());
        return res;
    }
};