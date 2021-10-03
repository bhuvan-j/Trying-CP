#include <iostream>
#include<map>
#define ll long long
#define m 1000000007
using namespace std;
map<ll,ll>ma;
ll fib(ll n){
    if(ma.find(n)!=ma.end()){
    return ma[n];
    }
    if(n%2==0){
        return ma[n]= (fib(n/2)*fib(n/2)+ (fib((n/2) -1)*fib((n/2) -1 )))%m;
    }
    else return ma[n] = (fib(n/2)*fib((n/2)+1)+fib(n/2)*fib((n/2)-1))%m;
}
int main() {
   //fibonacci
   ll n;
   cin>>n;
   ma[0]=ma[1]=1;

   cout<<fib(n-1);

    return 0;

}
