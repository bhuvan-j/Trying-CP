#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;
ll fexp(int a,int n){
    if(n==0){
        return 1;
    }
if(n%2==0){
    return fexp(a,n/2)*fexp(a,n/2);
}
else return a*fexp(a,n/2)*fexp(a,n/2);
}
int main() {
    ll a,n;
    cin>>a>>n;
    cout<<fexp(a,n);
  
    return 0;

}
