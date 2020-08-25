#include<bits/stdc++.h>
using namespace std;



int power(int x,int y){
    if(y==0) return 1;
    int temp = power(x,y/2);

    int curr = (temp*temp)%mod;
    if(y%2) return (curr*x)%mod;
    else return curr;
}


void dfs(int x,vector<vector<int>>& edge, vector<int>& vec, vector<bool>& vis, int n, vector<int>& c){
    
    vis[x] = true;
    for(auto j:edge[x]){
        if(!vis[j]){
            dfs(j,edge,vec,vis,n,c);
            vec[x-1]+= vec[j-1] ;
            c.pb(vec[j-1]*(n-vec[j-1]));
        }
    }
    vec[x-1]++;
}



signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> edge(n+1);
        vi vec(n);
        f(n-1){
            int x,y;
            cin>>x>>y;
            edge[x].pb(y);
            edge[y].pb(x);
        }

        vector<bool> vis(n+1);
        vi c;

        dfs(1,edge,vec,vis,n,c);
        // for(auto i:c) cout<<i<<nl;
        

        sort(all(c),greater<int>());

        int m;
        cin>>m;

        vi val(m);
        f(m) cin>>val[i];

        sort(all(val), greater<int>());

        int ans = 0;
        if(m>n-1){
            int temp = 1;
            for(int i=0;i<=(m-n+1);i++) {
                temp = (temp*val[i])%mod;
            } 
            ans+=(temp*c[0]);
            ans = ans%mod;

            for(int i=1;i<n-1;i++){
                ans+=(c[i]*val[(m-n+1+i)]);
                ans = (ans)%mod;
            }
        } 
        else{
            for(int i=0;i<m;i++){
                ans+=(c[i]*val[i]);
                ans = (ans)%mod;
            }

            for(int i=m;i<n-1;i++) {
                ans+=(c[i]);
                ans = ans%mod;
            }
        }

        cout<<ans<<nl;

    }

}