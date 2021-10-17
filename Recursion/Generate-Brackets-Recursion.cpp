#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//generate brackets

void generate_brackets(char *output,int n,int ind,int open,int close){
    if(ind==2*n){
        output[ind]='\0';
        cout<<output<<endl;
        return;
    }

    if(open<n){
        output[ind]='(';
        generate_brackets(output,n,ind+1,open+1,close);
    }
    if(close<open){
        output[ind]=')';
        generate_brackets(output,n,ind+1,open,close+1);
    }

  return;
}
int main() {
  int n;
  cin>>n;
   char output[1000];
   generate_brackets(output,n,0,0,0);
}
