#include<bits/stdc++.h>
using namespace std;
#define nl '\n'




signed main(){
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int k;
        cin>>k;
        int n = s.length();
        map<char,int> arr;
        int curr = 0, last = 0, i = 0, ans =-1;
        while(i<n){
            if(arr[s[i]]==0){ // New character came
                if(curr==k){   // we have to remove a charater from backside jiska count zero ho jaye
                    int j = last;
                    bool flag = 0;
                    while(j<i){
                        if(!flag){
                            arr[s[j]]--;
                            if(arr[s[j]] == 0) {
                                flag = 1;
                            }
                        }
                        else break;
                        j++;
                    }
                    last = j;
                    arr[s[i]]++;
                    ans = max(ans,i-last+1);

                }
                else{
                    
                    // less than k are there (distinct)
                    curr++;
                    arr[s[i]]++;
                }

            }
            
            // existing Character 
            else{
                
                // k distinct character 
                if(curr == k){
                    arr[s[i]]++;
                    ans = max(ans,i-last+1);
                }
                // less than k distinct characters
                else{
                    arr[s[i]]++;
                }
            }
            i++;
        }

        cout<<ans<<nl;

    }

}