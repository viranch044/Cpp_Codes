#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define nl '\n'
#define sp " "
#define vi vector<int>
#define f(n) for(int i=0;i<n;i++)





int bits(int x){
    int c =0;
    while(x){
        c++;
        x = x>>1;
    }
    return  c;
}

signed main(){

    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec[31];
        f(31){
            vec[i].pb(LLONG_MAX);
            vec[i].pb(LLONG_MIN);
        }
        int x;
        f(n){
            cin>>x;
            int bit = bits(x);
            if(x<vec[bit][0]) vec[bit][0]=x;
            if(x>vec[bit][1]) vec[bit][1]=x;
        }
        int ans = LLONG_MIN;

        for(int i=1;i<31;i++){
            for(int j=1;j<31;j++){
                if(vec[i][0]==LLONG_MAX or vec[j][0]==LLONG_MIN) continue;
                int curr = ((1<<j)-1)*(vec[i][1]) - ((1<<i)-1)*(vec[j][0]);
                ans = max(ans,curr);
            }
        }
        cout<<ans<<nl;
    }



}
