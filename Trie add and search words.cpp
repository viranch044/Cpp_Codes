// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

// Example:

// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
// Note:
// You may assume that all words are consist of lowercase letters a-z.


class Node{
public:
    bool end;
    Node* children[26];
    Node(){
        end = false;
        for(int i=0;i<26;i++) children[i] = NULL;
    }
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node *root = new Node();
    WordDictionary() {
        
    }
    
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.length();
        Node* curr = root;
        for(int i=0;i<n;i++){
            int pos = word[i] - 'a';        
            if(curr->children[pos] != NULL){
                curr = curr->children[pos];
            }
            else{
                Node* temp = new Node();
                curr->children[pos] = temp;
                curr = curr->children[pos];
            }
        }    
        curr->end = true;

    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    
    bool helper(string& word, int k, Node* curr,int n){
        if(k==n){
            if(curr->end) return true;
            else return false;
        }
        if(word[k]!='.'){
            int pos = word[k] - 'a';
            if(curr->children[pos]){
                curr = curr->children[pos];
                return helper(word,k+1,curr,n);
            }
            else return false;
        }
        else{
            bool ans = false;
            for(int i=0;i<26;i++){
                if(curr->children[i]){
                    ans = ans or (helper(word,k+1,curr->children[i],n));
                }
            }
            return ans;
            
            
        }
        
    }
    
    
    bool search(string word) {
        int n= word.length();
        Node* curr = root;
        return helper(word,0,root,n);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */