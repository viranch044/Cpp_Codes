#include<bits/stdc++.h>
using namespace std;
#define int ll
#define nl '\n'
#define f(n) for(int i=0;i<n;i++)


signed main(){
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        f(n) cin >> a[i];
        f(m) cin >> b[i];

        int f = 0, s = 0;
        while (f != n) {
//            cout<<a[f]<<sp<<b[0]<<nl;
            if (a[f] <= b[0]) f++;
            else {
                int temp = a[f];
                a[f] = b[0];
//                cout<<a[f]<<nl;
                s = 1;
                int pos = 0;
                while (s < m) {
                    if (b[s] < temp) {
                        pos = s;
                        s++;
                    } else break;
                }
                int curr = b[pos];
                b[pos] = temp;
                for (int i = pos - 1; i >= 0; i--) {
                    int temp2 = b[i];
                    b[i] = curr;
                    curr = temp2;
                }
            }
        }
        for (auto i:a) cout << i << sp;
        cout << nl;
        for (auto i:b) cout << i << sp;
    }

}