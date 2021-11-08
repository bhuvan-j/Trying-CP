#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool ispossible(int *a,int k,int n, int mintime){
    int painter=1;
    int paint=a[0];
    for(int i=1;i<n;i++){
        if(paint+a[i]>mintime){
            painter++;
            paint=a[i];
            if(painter>k){
                return false;
            }
        }
        else{
            paint=paint+a[i];
        }
    }
return true;
}
int solve(int *a,int k,int n){
    int s=a[n-1];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    int e=sum;
    int ans=INT_MAX;
    while(s<=e){
        int mid=(s+e)/2;
        if(ispossible(a,k,n,mid)){
            ans=min(ans,mid);
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;

}

int main() {
    int k,n;
    cin>>k>>n;
    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<solve(a,k,n)<<endl;
    return 0;
}
