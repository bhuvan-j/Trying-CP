#include <iostream>
#include<vector>
#include<bitset>
using namespace std;
const int n= 10000000;
bitset<10000005> b; 
vector<int> v;
#define ll long long
void bitsieve(){

    b.set(); //1,1,1,1,.....
    b[0]=b[1]=0;
    for(ll int i=2;i<=n;i++){
        if(b[i]){
            v.push_back(i);
            for(ll int j = i*i;j<=n;j+=i){
                b[j]=0;
            }
        }
    }
}

int main() {
    bitsieve();
    for(int i=0;i<=100;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
  return 0;
}
