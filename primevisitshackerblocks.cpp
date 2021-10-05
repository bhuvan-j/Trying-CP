#include <iostream>
#include<vector>
using namespace std;
#define INT_MAX 1000000 
#define ll long long
void primesieve(int *p){
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
    

}
int main() {
int p[100000]={0};
int a,b;
cin>>a>>b;
primesieve(p);
int csum[100000]={0};
for(int i=1;i<=100000;i++){
    csum[i]=csum[i-1]+p[i];
}

cout<<csum[b]-csum[a]<<" primes between a and b."<<endl;
  return 0;
}
