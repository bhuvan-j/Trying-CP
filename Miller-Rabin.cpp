//miller rabin is a primamility test. checks whether a no. is prime or not.
//it uses Fermat's little theorem(FLT) and euclids lemma.
//FLT -> a^(p-1)%p=1 where p is a prime no. 
// Euclids lemma -> if  x*y%p=0   , atleast x or y is 
//divisible by p. (where p is prime.)
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
//(a*b)%n
ll modular_multiplication(ll a, ll b, ll n){
    ll res=0;
    while(b){
        if(b&1ll){res+=a;
        res%=n;}
        a=2*a;
        a%=n;
        b/=2;
        
    }
 return res%n;
}
//(a^b)%n
ll modular_exponentiation(ll a, ll b, ll n){
    ll res=1;
    while(b){
    if(b%1ll){
        res=modular_multiplication(a,res,n);  
    }
    a=modular_multiplication(a,a,n);
    a%=n;
    b/=2;
    }
    return res;
}

bool miller_rabin(ll n)
{
if(n==1){return false;}
if(n==2){return true;}
if(!(n&1)){return false;}
//if u r here means n is odd. i.e n-1 is even = (some odd no. d)*2^s
ll d=n-1 /*here d is even*/;
ll s=0;
while(d%2==0){
    s++;
    d/=2;
}
//now d will become odd. and we can write (n-1)=d*(2^s)
// flt = a^(d*2^s)%n = 1 for n to be prime.
// means it is enough to check a^d%n 
//(as if square is divisible then, root is also dvisible.
// so power of 2 doesnt make a diff.)

vector<ll>a({2,3,5,7,11,13,17,19,23});
//a represent random numbers.
// here we r taking a as first 9 primes. 
//it is seen that it gives good accuracy till 10^18 numbers.
    
    
// 2 conditions for n to be prime:
    // (a ^ d ) % n = 1
    //a ^ ( d* (2^i) ) % n =  n-1 for all i from0 to s-1.
    // a is a random no.
    // n = (odd no. d) * (2^s)
    

for(int i=0;i<a.size();i++){
    if(a[i]>n-2) continue; //we r taking mod from n so it should be less than n.
    //calculate a[i]^d%n
    ll ad= modular_exponentiation(a[i],d,n);
    if(ad%n==1){continue;} // can be prime.
    bool prime=false;
    for(int r=0;r<=s-1;r++){
        //(2^r)%n;
        ll rr=modular_exponentiation(2,r,n);
        //a^(d*2^r)%n
        ll ard=modular_exponentiation(ad,rr,n);
        if(ard%n==n-1){
            prime=true;
            break;
        }
    }
    if(prime==false){return false;}
}
    return true;
}



void solve(){
    ll n;
    cin>>n;
    if(miller_rabin(n)){cout<<"prime\n";return;}
    cout<<"not prime \n";
    return;
}



int main() {
    solve();
    return 0;
}
