#include <iostream>
using namespace std;
#define ll long long
#define m 1000000000
ll strtoint(string x, ll mod){
    ll ans=0;
    for(int i=0;i<x.size();i++){
        ans=(ans*10)%mod+x[i]-'0';
        ans%=mod;
    }
    return ans;}
ll power(ll x, ll y){
    if(y==0){
        return 1;
    }
    ll blabla=(power(x,y/2)%m)*(power(x,y/2)%m);
    blabla%=m;
    if(y%2==0){
        return blabla;
    }
    return x*blabla;
}
int main() {
    ll t;
    cin>>t;
    string a,b;
    while(t--){
        cin>>a>>b;
        ll x= strtoint(a,m);
        ll y= strtoint(b,m-1);


        //x^y
        ll ans=power(x,y);
        cout<<ans<<endl;

    }
    return 0;
}
