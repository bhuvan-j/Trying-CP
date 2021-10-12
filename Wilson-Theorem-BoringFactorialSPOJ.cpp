
//William Theorem - (p-1)! % p = -1 (or n-1) for all primes numbers.
//Eg - (7-1)! % 7 = 6.5.4.3.2.1 % 7 = 6

//q: Boring factorials spoj
// n! % p
// 2 cases: n>=p or n<p
//  case 1:  1.2.3.4.5.....p......(n-1).(n) % p = 0;  if n>=p
//  case 2:   (p-1)! % p = -1 
//             ==>  1.2.3.4.5..(n-1).(n)...(p-1) % p = -1
//             ==> (n!).(n+1).(n+2).....(p-1) % p = -1  can be written as (n!).(n+1).(n+2).....(p-1)(p) = -1 ( mod p)
//             ==> (n!) = [ -1 / (n+1).(n+1)...(p-1) ] (mod p)

//             ==> (n!) = (-1)  *   [(n+1)(n+2)...(p-1)]^-1 (mod p) --> modulo inverse nikalna hai.  

//      According to Fermat's little theorem: a^p-1 = 1 ( mod p) 
//                                           ==> a^p-2 = a^-1 (mod p) (therefore we have to compute [(n+1)(n+2)....(p-1)]^p-2)
//     
//
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007
#define N 100005
ll fastmoduloexp(ll a, ll b, ll c){
    ll res=1;
    while(b>0){
    if(b&1){
        res*=a;
        res%=c;
    }
    a=(a*a)%c;
    b=b>>1; //b=b/2;
    }
    return res;
}
ll solve(ll n,ll p){
    ll ans=-1;
    for(ll i=(n+1);i<=(p-1);i++){
        ll temp=fastmoduloexp(i,p-2,p);
        ans=(ans*temp)%p;
    
    }
    return (ans+p)%p;
}

int main() {
    ll t,n,p;
    cin>>t;
    while(t--){
        cin>>n>>p;
        if(n>=p){
            cout<<"0"<<endl; // ( 1.2.3.4...p....(n-1).(n) ) % p = 0
        }
        else{
            cout<<solve(n,p)<<endl; 
        }
    }
}
