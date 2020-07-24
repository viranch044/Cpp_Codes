#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define inf LLONG_MAX
#define bp __builtin_popcountll
#define pb push_back
#define ff first
#define ss second
#define P pair<ll,ll>
#define N 100001
#define all(a) a.begin(),a.end()
#define LG 20
#define int ll
#define nl '\n'
#define sp " "
#define vi vector<int>
#define f(n) for(int i=0;i<n;i++)
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define ps(x,y) fixed<<setprecision(y)<<x
#define F(i,a,b) for(int i = a ; i < b ; i++)

// Segment Tree Implementation for range min queries and segment tree array starts from index 1...

void buildTree(int *tree,int *a,int index,int s,int e){    // index is current index in (segment tree's array) and s and e are ranges in original array

    if(s>e){
        return;
    }

    // base case (leaf Node)
    if(s==e){
        tree[index] = a[s];
        return;
    }

    //recursive case
    int mid = (s+e)/2;

    //Left Subtree
    buildTree(tree,a,2*index,s,mid);

    //right Subtree
    buildTree(tree,a,2*index+1,mid+1,e);

    int left = tree[2*index];
    int right = tree[2*index + 1];

    tree[index] = min(left,right);

}

// Query
// For minimum in the given range (l,r)
int query(int *tree,int index, int s, int e, int l,int r){
    // 3 case

    // No overlap
    if(l>e or r<s) return INT_MAX;

    // complete overlap
    if(l<=s and r>=e) return tree[index];

    // Partial overlap -- Call both sides
    int mid = (s+e)/2;

    int leftAns = query(tree,2*index,s,mid,l,r);
    int rightAns = query(tree,2*index+1,mid+1,e,l,r);

    return min(leftAns,rightAns);

}

void update(int *tree,int index,int s,int e,int i,int value) {  // i is the index at which we have to update the value to value...
    // No overlap
    if(i<s or i>e) return;

    // Reached leaf node
    if(s==e){
        tree[index] = value;
        return;
    }

    int mid = (s+e)/2;
    update(tree,2*index,s,mid,i,value);
    update(tree,2*index+1,mid+1,e,i,value);
    tree[index] = min(tree[2*index],tree[2*index +1]);
}

// Range Update increment a range with given value O(n) worst case
void updateRange(int *tree,int index,int s,int e,int rs,int re,int inc) {  // i is the index at which we have to update the value to value...
    // No overlap
    if(rs>e or re<s ) return;

    // Reached leaf node
    if(s==e){
        tree[index]+=inc;
        return;
    }

    int mid = (s+e)/2;
    updateRange(tree,2*index,s,mid,rs,re,inc);
    updateRange(tree,2*index+1,mid+1,e,rs,re,inc);
    tree[index] = min(tree[2*index],tree[2*index +1]);
}


signed main(){
    int n;
    cin>>n;
    int a[n];
    f(n) cin>>a[i];

    // build the tree array

    int *tree = new int[4*n + 1];
    buildTree(tree,a,1,0,n-1);



}