//Write a program to find the n-th ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//
//Example:
//
//Input: n = 10
//Output: 12
//Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.



#include<bits/stdc++.h>
using namespace std;

int main(){
    long int ugly[10001];
    ugly[1]=1;
    int i2=1,i3=1,i5=1;
    int index=2;
    while(index!=10001){
        long int x=2*ugly[i2],y=3*ugly[i3],z=5*ugly[i5];
        long int mini=min(x,min(y,z));
        ugly[index]=mini;
        index++;
        if(mini==x) i2++;
        if(mini==y) i3++;
        if(mini==z) i5++;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ugly[n]<<endl;
    }
}