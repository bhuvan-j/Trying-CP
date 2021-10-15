#include <iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;
#define ll long long
//  Q - no. to spellings

/* 
2048 ----> two zero four eight


*/
// map<ll,string> m;
vector<string>m={"zero","one","two","three","four","five","six","seven","eight","nine"};
  

void printword(ll n){
    if(n==0){return;}// BASE CASE
    ll temp=n%10;
   
    printword(n/10);   // FIRST PRINT ALL BEFORE ELEMENTS THROUGH RECURSION
    //THEN PRINT LAST ELEMENT
    cout<<m[n%10]<<" "; //POST ORDER IN EULER PATH.
    
}

int main() {
    // m[0]="zero";
    // m[1]="one";
    // m[2]="two";
    // m[3]="three";
    // m[4]="four";
    // m[5]="five";
    // m[6]="six";
    // m[7]="seven";
    // m[8]="eight";
    // m[9]="nine";
    

    printword(9876543210);

}
