#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int make_change(int *coins,int money,int n){
    int count=0;
    while(money>0){
        int idx=upper_bound(coins,coins+n,money)-coins-1;
        cout<<coins[idx]<<"+";
        money-=coins[idx];
        count++;
    }
    cout<<endl;
    return count;
    
}
int main() {
    
    int coins[]= {1,2,5,10,20,50,100,200,500,1000,2000};
    int money;
    cin>>money;
    cout<<make_change(coins,money,sizeof(coins)/sizeof(int))<<" coins minimum according to greedy approach";


    
}
