// We're going to make our own Contacts application! The application must perform two types of operations:

// add name, where name is a string denoting a contact name. This must store  as a new contact in the application.
// find partial, where partial is a string denoting a partial name to search the application for. It must count the number of contacts starting with  and print the count on a new line.
// Given  sequential add and find operations, perform each operation in order.

// Sample Input

// 4
// add hack
// add hackerrank
// find hac
// find hak
// Sample Output

// 2
// 0


#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;



struct Node{
    int freq;
    char curr;
    Node* letters[26];
};

Node* createNewNode(char curr){
    Node* temp = new Node;
    temp->curr = curr;
    temp->freq = 1;
    for(int i=0;i<26;i++) temp->letters[i] = nullptr;
    return temp;
}

void insertelementinTrie(string s,Node* root){
    for(auto i:s){
        int pos = i-'a';
        if(root->letters[pos] != nullptr){
            root = root->letters[pos];
            root->freq++;
        }
        else{
            Node* temp = createNewNode(i);
            root->letters[pos] = temp;
            root = root->letters[pos];
        }
    }
}

int prefix_match(string s,Node* root){
    int ans =0;
    for(auto i:s){
        int pos = i - 'a';
        if(root->letters[pos] == nullptr) return 0;
        else {
            root = root->letters[pos];
            ans = root->freq;
        }
    }
    return ans;
}

signed main(){
    Node* root = createNewNode('-');
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string a,s;
        cin>>a>>s;
        if(a=="add"){
            insertelementinTrie(s,root);
        }
        else{
            cout<<prefix_match(s,root)<<nl;
        }
    }
}
