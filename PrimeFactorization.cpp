#include <iostream>
#include<vector>
#include<bitset>
using namespace std;
#define ll long long
vector<int>prime;
bitset<100000>b;
// void sieve(){
//     b.set();
//     b[0]=b[1]=0;
//     for(ll int i=2;i<=100000;i++){
//         if(b[i]){
//             prime.push_back(i);
//             for(ll j=i*i;j<=100000;j+=i){
//                 b[j]=0;
//             }
//         }
//     }
//     for(int i=0;i<prime.size();i++){
//         cout<<prime[i]<<" ";

//     }
//     cout<<endl;

// }


int main() {
// sieve();
ll int n;
cin>>n;

// for(auto x : prime){
//     if(x>n){
//         break;
//     }
//     if(n%x==0){
//         while(n%x==0){
//             cout<<x<<" ";
//             n/=x;
//         }
//     }
// }
vector<pair<int,int>>ans;
for(int i=2;i*i<=n;i++){
    if(n%i==0){
        int cnt=0;
        while(n%i==0){
            cnt++;
            n/=i;
        }
        ans.push_back(make_pair(i,cnt));
    }
}
if(n!=1){
    ans.push_back(make_pair(n,1));
}
for(int i=0;i<ans.size();i++){
    cout<<ans[i].first<<"^"<<ans[i].second<<endl;
}
  return 0;
}
