//Mobius function( denoted by u)
//u(n)=1 if a number have even number of prime factors
//u(n)= -1 if a number has odd number of prime factors
//(for above all these factors have power<2)
//u(n)=0 if number has prime factors with power >=2. 
//Eg: u(9)=0 because 9 = 3^2.
//u(6) = 1 because 6 = 2*3.
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007
#define N 100005
vector<ll>v;
vector<int>u(N+1,0);
int freq[N]; //cnt(x)
int p2[N]; // gives 2^i
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
void call_mobius()
{
    
    vector<ll>prime_count(N,0);
    vector<int>a(N,1);
    for(auto i : v){
        if(i>N){break;}
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
    return;
}
// Codeforces q: number of coprime subsequences.

//corprime subsequences= gcd of all elements is 1.
//gcd(a1,a2,a3,a4......an)=1
//Total no. of subsequences = (2^n)-1 (excluding empty one)

//WE WILL USE INCLUSION EXCLUSION PRINCIPLE.

// let number of numbers divisible by a number x = cnt(x).
//then subsequences in which all elemets are divisible by x = (2^cnt(x))-1
//by inclusion exclusion:
// ans= total - (subseq by diff value of x)

//= total - sub(2)-sub(3)-sub(5) and so on...........

//(but if we remove 2 and 3,we r removing subseq (6) two times 
//as subseq of 6 is div by 2 and 3 both. 
//hence we will add subseq(6) one time. )

//= total - sub(2)-sub(3)- sub(5) + sub(2.3) + sub(3.5) + sub(2.5)  - sub(2.3.5) and so on...........
// if we see, all numbers with odd no. of prime factors are subtracted.
// and all numbers with even no. of prime factors are added.
// all squares are not considered.
// and also all numbers with >=2 powers of primes are not considered because they are already considered during their primes.
// THATS WHAT WE COMPUTED IN MOBIUS FUNCTION :)
void solve(){
    ll n;ll ans=0;
    call_mobius();
    cin>>n;
    ll b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
        freq[b[i]]++;
    }
    p2[0]=1;
    for(int i=1;i<N;i++){
        p2[i]=p2[i-1]*2; 
        p2[i]%=m;
           }
    for(ll i=1;i<N;i++){
        ll cnt=0;
        for(ll j=i;j<N;j+=i){
            cnt+=freq[j];
        }
        ll subseq= p2[cnt]-1; //2^cnt-1
        ans+=u[i]*subseq;
        ans%=m;
    }
    ans+=m;
    cout<<ans% m;
}


int main() {
    sieve();
   solve();
}
