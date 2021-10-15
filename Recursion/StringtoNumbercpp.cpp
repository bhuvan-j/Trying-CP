#include <iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;
#define ll long long
//  Q - string to integer

/* 
"1234"--->1234

f("1234") = f("123")*10 + ("4"-"0")

*/

  

ll printnum(string str,ll s,ll e){
    if(s>e){return 0;}

    return printnum(str,s,e-1)*10 + (str[e]-'0');
 
}

int main() {
    string str="12348499";
    ll n= str.length();
    cout<<printnum(str,0,n-1);

}
