#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPossible(int *a,int n,int m,int curr_min){
    int studused=1;
    int pages_reading=0;
    for(int i=0;i<n;i++){
        if(pages_reading+a[i]>curr_min){
            studused++;
            pages_reading=a[i];
            if(studused>m){
                return false;
            }
        }
        else{
            pages_reading+=a[i];
        }
    }
    return true;

}
int findPages(int *a,int n,int m){
    if(n<m){
        return -1;
    }
    int sum_of_all_pages=0;
    for(int i=0;i<n;i++){
        sum_of_all_pages+=a[i];
    }

    int s=a[n-1];
    int e= sum_of_all_pages;
    int ans=INT_MAX;
    while(s<=e){
        int mid=(s+e)/2;
        if(isPossible(a,n,m,mid)){
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
    int n,m;
    cin>>n>>m;
    int a[1000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<findPages(a,n,m)<<endl;
    return 0;
}
