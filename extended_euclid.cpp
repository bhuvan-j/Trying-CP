#include <iostream>
using namespace std;
#define ll long long
ll gcd(int a,int b){
return (b==0?a:gcd(b,a%b));
}
ll lcm(int a,int b){
    return (a*b/(gcd(a,b)));
}
int x,y,GCD;
void extended_euclid(int a,int b){
    if(b==0){
        x=1;
        y=0;
        GCD=a;
        return;
    }
    extended_euclid(b,a%b);
    int cx=y;
    int cy=x-(a/b)*y;
    x=cx;
    y=cy;
    cout<<x<<" "<<y<<endl;
return;
}
int main() {
    extended_euclid(18,30);
    cout<<x<<" "<<y;
    return 0;


}
