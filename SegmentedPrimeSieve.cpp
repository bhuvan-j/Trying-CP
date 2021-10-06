#include <iostream>
#include<vector>
using namespace std;
#define ll long long
# define range 100000 //n-m;
int p[range]={0};
vector<int> primes;
void sieve(){

    for(ll int i=2;i<=range;i++){
        if(p[i]==0){
            primes.push_back(i);
            for(ll int j=i*i;j<range;j+=i){
                p[j]=1;
            }
        }
    }

}



int main() {
    sieve();
    int t;
    cin>>t;
    while(t--){
int n,m;
cin>>m>>n;
bool segment[n-m+1]={0}; //prime

for(auto x: primes){
    if(x*x>n){
        break;
    }
    int start = (m/x)* x;
    if(x>=m&&x<=n){
        start=2*x;
    }
    for(int i=start;i<=n;i+=x){
        segment[i-m]=1; //not-prime
    }
}
for(int i=m;i<=n;i++){
    if(segment[i-m]==0 and i!=1){
        cout<<i<<" ";
    }
}
cout<<endl;

    }
  return 0;
}
