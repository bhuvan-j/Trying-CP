
#include <iostream>
#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define m 1000000007
using namespace std;
int main() {
    int n;
    cin>>n;
    int sum=0;
    int temp=n;
    while(temp>0){
        sum+=(temp%10);
        temp/=10;
    }
    ll s=0;
    while(n%2==0){
        s+=2;
        n/=2;
    }
    for(int i=3;i<=sqrt(n);i=i+2){
        while(n%i==0){
            int temp1=i;
            while(temp1>0){
                s+=(temp1%10);
                temp1/=10;
            }
            n/=i;
        }
    }
     if (n > 2)
    {  while(n>0)
    {
        s=s+(n%10);
        n/=10;
    }
    }
    cout<<sum<<" "<<s;
    if(sum==s){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

    return 0;



}