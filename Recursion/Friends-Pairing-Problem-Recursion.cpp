#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long


//  Q -friends pairing problem -
 //   n friends want to go to a party on bikes.each friend can go as single or as a couple. 
//    find the number of ways in which n friends can go to party.

/* 
- eg:  (1,2,3) --> (1),(2),(3) or (1,2),3 or (2,3),1 or (1,3),2 ---total 4 ways.

-   if a guy X goes alone, remaining (n-1) people can go in f(n-1)ways.
         hence, 1*f(n-1) ways.

-   if he want to pair up with someone, he has to choose someone from (n-1) people. 
        - choosing can happen in (n-1) C (1) ways = n-1 ways.
        - and remaining (n-2) people can go in f(n-2) ways.

        - hence (n-1)*f(n-2) ways.


- TOTAL : F(N-1) + (N-1)*F(N-2)
*/ 

ll friendspairing(ll n){
    if(n==0||n==1){
        return 1;
    }
     return friendspairing(n-1) + (n-1)*friendspairing(n-2);
}

  

int main() {
    ll n;
    cin>>n;
    cout<<friendspairing(n);

}
