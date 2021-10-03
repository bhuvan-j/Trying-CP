#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;

int main() {
    ll primes[]= { 2,3,5,7,11,13,17,19}; //8nos. subset = (2^8)-1;
    ll n;
    cin>>n;
    ll noofsubsets=(1<<8)-1;
    ll ans=0;
    for(int i=1;i<=noofsubsets;i++){
        ll denom = 1ll;
        ll noofones= __builtin_popcount(i);
        for(int j=0;j<8;j++){
            if(i&(1<<j)){denom*=primes[j];}

        }
        if (noofones&1){
            ans+=(n/denom);
        }
        else{
            ans-=(n/denom);
        }
    }
    cout<<ans;
  
    return 0;

}
