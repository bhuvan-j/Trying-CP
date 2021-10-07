#include <iostream>
using namespace std;
#define ll long long
ll gcd(int a,int b){
return (b==0?a:gcd(b,a%b));
}
ll lcm(int a,int b){
    return (a*b/(gcd(a,b)));
}
ll x,y,hcf;
void extended_euclid(ll a,ll b){
    if(b==0){
        x=1;
        y=0;
        hcf=a;
        return;
    }
    extended_euclid(b,a%b);
    int cx=y;
    int cy=x-(a/b)*y;
    x=cx;
    y=cy;

}
ll inversemodulo(ll a,ll m){
    //exists only and only if gcd(a,m)==1
extended_euclid(a,m);
return (x+m)%m;
}
int main() {
    cout<<inversemodulo(17,8);
    return 0;


}
