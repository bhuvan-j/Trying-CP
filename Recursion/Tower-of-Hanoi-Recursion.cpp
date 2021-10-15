#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long


//  Q -Tower of Hanoi

/* 

*/ 

void hanoi(ll n,char src,char helper,char dest){
    if(n==0){
        return;
    }
     hanoi(n-1,src,dest,helper);
     cout<<"move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
     hanoi(n-1,helper,src,dest);

}

  

int main() {
    ll n;
    cin>>n;
    hanoi(n,'A','B','C');

}
