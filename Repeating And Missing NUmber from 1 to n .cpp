// You are given a read only array of n integers from 1 to n.

// Each integer appears exactly once except A which appears twice and B which is missing.

// Return A and B.

// Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Note that in your output A should precede B.

// Example:

// Input:[3 1 2 5 3] 

// Output:[3, 4] 

// A = 3, B = 4


vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int xoall = 0, xoele = 0;
    
        // xor all eles given in array
        for(auto i:A) xoele^=i;
        
        // xor from 1 to n
        for(int i=1;i<=n;i++) xoall^=i;
            
        // by doing xor of both of them we will have missing^repeating
        int com = xoall^xoele;

        int x = 1;
        // finding leftmost set bit
        while(!(x&com)){
            x = x<<1;
        }


        // dividing in two sets such of that particular bit set and unset
        int a = 0, b= 0;
        for(auto i:A){
            if(x&i) a^=i;
            else b^=i;
        }
        for(int i=1;i<=n;i++){
            if(i&x) a^=i;
            else b^=i;
        }

        for(auto i:A){
            if(i==a) {
                return {a,b};
            }
            if(i==b){
                return {b,a};
            }
        }
}
