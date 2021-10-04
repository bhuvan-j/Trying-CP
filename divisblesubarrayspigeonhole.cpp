#include <iostream>
using namespace std;
#define ll long long
ll a[1000005],freq[1000005];
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll sum=0;
         memset(freq,0,sizeof(freq));
        freq[0]=1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            freq[(sum+n)%n]++;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            if(freq[i]>=2){
                int m= freq[i];
                ans+=((m)*(m-1)/2);
            }
        }
        cout<<ans<<endl;



    }
    return 0;
}
