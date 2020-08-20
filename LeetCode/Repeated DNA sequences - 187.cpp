// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

// Example:

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

// Output: ["AAAAACCCCC", "CCCCCAAAAA"]

// Consider all 4 characters as two bits

class Solution {
public:
    
    int charv(char c){
        switch(c){
            case 'A' : return 0;
            case 'C' : return 1; 
            case 'G' : return 2; 
            case 'T' : return 3; 
        }
        return -1;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10) return {};
        int value = 0;
        for(int i=0;i<10;i++){
            value = (value << 2) | (charv(s[i]));
        }
        
        vector<string> answer;
        bitset<1<<20> A;
        bitset<1<<20> B;
        A.set(value);
        
        int mask = (1<<20) - 1;
        
        for(int i=10;i<s.length();i++){
            value =((value<<2) & mask) | charv(s[i]);
            if(B[value]) continue;
            if(A[value]){
                B.set(value);
                answer.push_back(s.substr(i-10+1,10));
            }
            
            else A.set(value);
        }
        
        return answer;

    }
};