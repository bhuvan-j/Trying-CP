//Mobius function
//u(n)=1 if n has even number of prime factors
//u(n)=0 if n has any prime factor that has power >=2
//u(n)= -1 for odd number of prime factors.

/* findings-  1) all prime nos will have u as -1.
              2) all perfect squares will have u as 0. */
  



#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>v;
void sieve(){
     bitset<10000>b;
     b.set();
     b[0]=b[1]=0;
     for(int i=3;i<b.size();i++){
         if(i%2==0){
             b[i]=0;
         }
     }
     for(int i=0;i<b.size();i++){
         if(b[i]==1){
             v.push_back(i);
             for(int j=i*i;j<b.size();j+=i){
                 b[j]=0;
             }
         }
     }
 } 

void call_mobius(ll n){
vector<int> a(n+1,1);
int prime_count[n+1]={0};
int u[n+1]={0};
for(int i=0;i<v.size();i++){
    if(v[i]>n){break;}
    for(int j=v[i];j<=n;j+=v[i]){
        a[j]*=v[i];
        prime_count[j]++;
    }
}
    
for(int i=0;i<n+1;i++){
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

for(int i=0;i<=n;i++){
    cout<<i<<"->"<<u[i]<<"\t";
}


}

int main() {
    sieve();
    call_mobius(10);
return 0;
}
