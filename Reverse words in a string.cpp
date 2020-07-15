// Given an input string, reverse the string word by word.

 

// Example 1:

// Input: "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: "  hello world!  "
// Output: "world! hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.


class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string curr = "";
        for(auto i:s){
            if(i!=' ') curr+=i;
            else {
                if(curr!="")
                    st.push(curr);
                curr = "";
            }
        }
        if(curr!="")
            st.push(curr);
        if(st.empty()) return "";
        string ans = "";
        while(st.size()!=1){
            ans+=st.top();
            ans+=' ';
            st.pop();
        }
        ans+=st.top();
        return ans;
        
    }
};