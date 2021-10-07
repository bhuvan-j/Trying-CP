#include <iostream>
using namespace std;
#define ll long long
ll gcd(int a,int b){
return (b==0?a:gcd(b,a%b));
}
ll lcm(int a,int b){
    return (a*b/(gcd(a,b)));
}
ll FastModExp(ll a, ll b,ll c){
    ll res=1;
    while(b>0){
        if(b&1){
            res*=a;
            res%=c;
        }
        a=(a*a)%c;
        b=b>>1;
    }
    return res%c;
}

int main() {
    cout<<FastModExp(5,3,100);
    return 0;


}
