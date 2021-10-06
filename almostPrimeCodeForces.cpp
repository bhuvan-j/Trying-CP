#include <iostream>
#include<vector>
using namespace std;
const int n= 3000;
#define ll long long
vector<int>primes;
ll almostprime(){
int pr[n+1]={0};
for(int i=2;i<=n;i++){
    if(!pr[i]){
        primes.push_back(i);
        for(int j=2*i;j<=n;j+=i){
            pr[j]++;
        }
    }
}
ll count=0;
for(int i=0;i<primes.size();i++){
    cout<<primes[i]<<" ";
}
cout<<endl;
for(int i=0;i<=n;i++){
    if(pr[i]==2){
        count++;
    }

}
return count;
}
int main() {
cout<<almostprime();
    cout<<endl;
  return 0;
}
