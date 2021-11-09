#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void pairofroses(int *arr,int n,int m){
    int diff=INT_MAX;
    int p1=-1;
    int p2=-1;

    for(int i=0;i<n-1;i++){
        if(arr[i]>m){
            continue;
        }
        int tofind=m-arr[i];
        int ind=lower_bound(arr+i+1,arr+n,tofind)-arr;
        if(ind>=n){
            continue;
        }

        if(arr[ind]==tofind){
            if(arr[ind]-arr[i]<diff){
                diff=arr[ind]-arr[i];
                p1=arr[i];
                p2=arr[ind];
            }
        }

    }

    cout<<p1<<" and "<<p2<<endl;

}
int main() {
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    sort(a,a+n);
    pairofroses(a,n,m);
    return 0;

}
