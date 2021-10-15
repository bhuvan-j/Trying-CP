#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long


//  Q -ladders Problem. No. of ways to reach the top of stairs if allowed jumps are 1,2,3.

/* 
- To reach Nth step, one has to first reach either (N-1), (N-2) or (N-3) steps.
   from there they can take 1,2 or 3 steps respectively to reach Nth step.

- hence if we find number of ways to reach (n-1), (n-2) and (n-3)th step,
  we can get number of ways for nth step.

                   f(n) = f(n-1) + f(n-2) + f(n-3)
*/ 

ll ladderprob(ll n){
    if(n<=0){
        return 1;
    }
     return ladderprob(n-1) + ( n>=2 ? ladderprob(n-2):0 ) + (n>=3 ? ladderprob(n-3):0 );
}

  

int main() {
    ll n;
    cin>>n;
    cout<<ladderprob(n);

}
