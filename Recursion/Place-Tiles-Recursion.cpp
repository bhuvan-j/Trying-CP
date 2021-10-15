#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long


//  Q -place tiles - number of ways to fill a wall of (4xN) with tiles of (4,1) and (1,4).

/* 
- If we put a (4,1) tile first, remaining wall will have dimensions(4 x (N-1))

- If we put a (1,4) tile , a small area of ( 3 X 4) will be left which cant be fill with vertical tile. 
  hence it will be filed by horizontal tiles. remaining wall will have dimensions (4 x (N-4))

                        |||||   hence, f(n) = f(n-1) + f(n-4)      |||||




                    THE CODE CAN BE OPTIMISED USING DP AND MATRIX EXPONENTIATION.
                    BUT,HERE WE WANT TO LEARN RECURSION SO WE WILL ONLY USE RECURSION.
*/ 

ll placetiles(ll n){
    if(n<=3){
        return 1;
    }
    else if(n==4){
        return 2;
    }
    return placetiles(n-1)+placetiles(n-4);
}

  

int main() {
    ll n;
    cin>>n;
    cout<<placetiles(n);

}
