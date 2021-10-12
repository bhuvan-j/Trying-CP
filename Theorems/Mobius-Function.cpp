//Mobius function( denoted by u)
//u(n)=1 if a number have even number of prime factors
//u(n)= -1 if a number has odd number of prime factors
//(for above all these factors have power<2)
//u(n)=0 if number has prime factors with power >=2. 
//Eg: u(9)=0 because 9 = 3^2.
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v;
void sieve(){
    bitset<10000>b;
    b.set();
    b[0]=b[1]=0;
    for(int i=3;i<b.size();i++){
        if(i%2==0){
            b[i]=0;
        }
    }
    for(ll i=0;i<b.size();i++){
        if(b[i]==1){
            v.push_back(i);
            for(ll j=i*i;j<b.size();j+=i){
                b[j]=0;
            }
        }
    }
}
void call_mobius(ll n)
{
    vector<int>u(n+1,0);
    vector<ll>prime_count(n+1,0);
    vector<int>a(n+1,1);
    for(auto i : v){
        if(i>n){break;}
        for(int j=i;j<a.size();j+=i){
            a[j]*=i;
            prime_count[j]++;
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i]==i){
            if(prime_count[i]%2==0){
    u[i]=1;
            }
            else{
    u[i]=-1;
            }

        }
        else{
            u[i]=0;
        }
    }
    for(int i=0;i<u.size();i++){
        cout<<u[i]<<" ";
    }
    return;
}

int main() {
    sieve();
   call_mobius(10);
}
