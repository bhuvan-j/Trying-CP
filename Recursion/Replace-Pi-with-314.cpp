#include <iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;
#define ll long long
//  Q -Replace "pi" with "3.14"

/* 
"xpimghpimwuqpi"---->"x3.14mgh3.14mwuq3.14"
*/

  

void pitonum(char a[],int i){
    if(a[i]=='\0' or a[i+1]=='\0'){
        return;
    }
    if(a[i]=='p' && a[i+1]=='i'){
        // if current location has word "pi" , then replace it with 3.14.
        // pi has 2 boxes occupied. but 3.14 needs 4 boxes. hence we will shift remaining array by 2 boxes to adjust 3.14
    int j=i+2;
    //reaching to the end of the array.
    while(a[j]!='\0'){
        j++;
    }
    // shifting the remaining array to two steps right.
    //xpimghpimwuqpi ---> xpi,_,_,mghpimwuqpi
    while(j>=i+2){
        a[j+2]=a[j];
        j--;
    }
    // now replace pi with 3.14
    a[i]='3';
    a[i+1]='.';
    a[i+2]='1';
    a[i+3]='4';

    //recursive call for remaining part
    pitonum(a,i+4);

    }
    else{
        // if the location doesnt contain "p" simple check in next index.
        pitonum(a,i+1);
        return;
    }
    return;
}

int main() {
    char str[1000];
    cin>>str;
    pitonum(str,0);
    cout<<str;
    return 0;

}
