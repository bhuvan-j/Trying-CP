#include <iostream>
#include<vector>
using namespace std;
#define INT_MAX 1000000 
#define ll long long
void primesieve(int *p,int n){
    for(int i=3;i<=100000;i+=2){
        p[i]=1;
    }
    for(long long i=3;i<=100000;i+=2){
        if(p[i]==1){
            for(ll j=i*i;j<=100000;j+=i){
                p[j]=0;
            }
        }
    }
    p[2]=1;
    for(int i=0;i<=n;i++){
        if(p[i]==1){
        cout<<i<<" ";}
    }
    

}
int main() {
int p[100000]={0};
int n;
cin>>n;
primesieve(p,n);
  return 0;
}
