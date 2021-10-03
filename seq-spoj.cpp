#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long
#define m 1000000000
ll k;
vector<ll> a ,b,c;
vector<vector<ll>> multiply(vector<vector<ll>> a , vector<vector<ll>> b){
vector<vector<ll>> c(k+1,vector<ll>(k+1));
for(int i=1;i<=k;i++){
    for(int j=1;j<=k;j++){
        for(int x=1;x<=k;x++){
            c[i][j]=(c[i][j]+(a[i][x]*b[x][j])%m)%m;
        } 
    }
}
return c;


}
vector<vector<ll>> pow(vector<vector<ll>> t, ll p){
    if(p==1){
        return t;
    }
    if(p&1){
        return multiply(t,pow(t,p-1));
    }
    vector<vector<ll>> x = pow(t,p/2);
    return multiply(x,x);
}
ll compute(ll n){
    if(n==0){return 0;}
    if(n<=k){return b[n-1];}

    vector<ll> f1(k+1);
    for(int i=1;i<=k;i++){
        f1[i]=b[i-1];
    }

    vector<vector<ll>>t(k+1,vector<ll>(k+1));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(i<k){
                if(j==i+1){
                    t[i][j]=1;
                }
                else{
                    t[i][j]=0;
                }

            }
            else{
                t[i][j]=c[k-j];

            }
        }
    }
    t=pow(t,n-1);
    ll res=0;
    for(int i=1;i<=k;i++){
        res+=(t[1][i]*f1[i])%m;
        res%=m;
    }
    return res;




}
int main() {
   ll t,n,num;
   cin>>t;
   while(t--){
       cin>>k;
       // ai = bi for i<k
       for(int i=0;i<k;i++){
           cin>>num;
           b.push_back(num);
       }
       //coeff
       for(int i=0;i<k;i++){
           cin>>num;
           c.push_back(num);
       }
       cin>>n;
       cout<<compute(n)<<endl;

       b.clear();
       c.clear();
   }
return 0;
}
