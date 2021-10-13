#include <iostream>
using namespace std;
#define ll long long
//Computing a^n

//Naive and inefficient function
int power(int a,int n){
    if(n==0){return 1;}
    return a*power(a,n-1);  //a^n= a * a^(n-1)
    // depth of call stack will be n. hence space complexity = O(n)

}

// //fast exponentiation.
int fast_power(int a,  int n){
    if(n==0){return 1;}
    ll sub=fast_power(a,n>>1);    //fast_powe(a,n/2);
    if(n&1){ // if n is odd
        return a*sub*sub;
    }
    return sub*sub;
} // this has logN time.

int main() {
    cout<<fast_power(2,3);
    
} 
