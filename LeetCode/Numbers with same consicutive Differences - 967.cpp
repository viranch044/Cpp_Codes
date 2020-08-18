// Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

// Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

// You may return the answer in any order.

 

// Example 1:

// Input: N = 3, K = 7
// Output: [181,292,707,818,929]
// Explanation: Note that 070 is not a valid number, because it has leading zeroes.
// Example 2:

// Input: N = 2, K = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]


class Solution {
public:
    
    vector<int> ans;
    vector<long long int> p;
    
    void powers(){
        p.resize(10,0);
        p[0] = 1;
        for(int i=1;i<10;i++){
            p[i] = 10*p[i-1];
        }
    }
    void temp(int n, int curr,int pos, long long int number, int k){
        number += p[pos]*curr ;
        if(pos == n-1){
            if(curr!=0) ans.push_back(number);
            else if(pos==0 and curr == 0) ans.push_back(number);
            return;
        }
        
        if(k==0) temp(n,curr,pos+1,number,k);
        else{
            if(curr+k <= 9) temp(n,curr+k,pos+1,number,k);
            if(curr-k>= 0) temp(n,curr-k,pos+1,number,k);
        }
        
        
        number -= p[pos]*curr;
        
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        powers();
        long long int number = 0;
        for(int i=0;i<=9;i++){
            temp(N,i,0,number,K);
        }
        
        return ans;
    }
};