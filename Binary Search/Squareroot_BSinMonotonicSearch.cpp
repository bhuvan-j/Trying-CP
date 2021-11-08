#include <iostream>
using namespace std;
float ans=-1;
int square_root(int n,int p){
    int s=0;
    int e=n;

    while(s<=e){
        int mid=(s+e)>>1;
        if(mid*mid==n){
            ans=mid;
            break;
        }
        else if(mid*mid<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }

    //floating part
    float inc=0.1;
    for(int i=1;i<=p;i++){
        while(ans*ans<=n){
            ans+=inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    square_root(n,3);
    cout<<ans<<endl;

}
