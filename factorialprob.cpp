#include <iostream>
using namespace std;
#define INT_MAX 1000000 
int main() {
  int t;
  int n,k;
  cin>>t;
  while(t--){
      cin>>n>>k;
      int ans=INT_MAX;
      for(int i=2;i*i<=k;i++){
          if(k%i==0){
              int occ=0;
              while(k%i==0){
                  occ++;
                  k/=i;
              }
              int cnt=0;
              long long p=i;
              while(p<=n){
                  cnt+=(n/p);
                  p=p*i;
              }
              ans=min(ans,cnt/occ);

          }
      }
      if(k>1){
          int cnt=0;
          long long p=k;
          while(p<=n){
                  cnt+=(n/p);
                  p=p*k;
              }
              ans=min(ans,cnt);


      }
      if(ans==INT_MAX){
          cout<<"0";
      }
      else{
      cout<<ans<<endl;}

  }
  return 0;
}
