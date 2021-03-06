#include <iostream>
using namespace std;
int ans=-1;
bool canplace(int *stalls,int n,int c,int min_sep){
    int last_cow=stalls[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(stalls[i]-last_cow>=min_sep){
            last_cow=stalls[i];
            cnt++;
            if(cnt==c){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int stalls[]={1,2,4,8,9};
    int n=5;
    int c=3;

    int s=0;
    int e=stalls[n-1]-stalls[0];
    while(s<=e){
        int mid=(s+e)/2;
        bool cowsrakhpaye= canplace(stalls,n,c,mid);
        if(cowsrakhpaye){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;

}
