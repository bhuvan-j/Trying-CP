#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool ispossible(int *a,int n,int m,int minh){
    int sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>minh){
            sum+=(a[i]-minh);
        }
    }
    if(sum>=m){
        return true;
    }
    return false;
}
int solve(int *a,int n,int m){
    int s=a[0];
    int e=a[n-1];
    int ans=INT_MIN;
    while(s<=e){
        int mid=(s+e)/2;
        if(ispossible(a,n,m,mid)){
            ans=max(ans,mid);
            s=mid+1;
        }
        else{
            e=s-1;
        }
    }
    return ans;

}

int main() {
    int n,m;
    cin>>n>>m;
    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<solve(a,n,m)<<endl;
    return 0;
}
