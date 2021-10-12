//recursion basics
// recursion is answering laerger problems buy solving same but smaller problems
//BIG ----> small
//Parts of recursion = 1) Base case. 2) Recursive call

#include <iostream>
using namespace std;
#define ll long long
ll factorial(ll n){
    if(n==0){return 1;}.  // base case
    return n*factorial(n-1); // recursive call
}
int main() {
    ll n;
    cin>>n;
    cout<<factorial(n);
    
    return 0;
}
