#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPossible(int *rank,int no_of_prata,int no_of_chef,int curr_min){
    int sum=0;
    for(int i=0;i<no_of_chef;i++){
        int n=1;
        while(rank[i]*n*(n+1)/2<=curr_min){
            n++;
        }
        n--;
        sum+=n; 
    }
    if(sum<no_of_prata){
        return false;
    }
    return true;

}
int mintime(int *rank,int no_of_prata,int no_of_chef){
    int s=0;
    int e=rank[0]*(no_of_prata*(no_of_prata+1)/2);
    int ans=INT_MAX;
    while(s<=e){
        int mid=(s+e)/2;
        if(isPossible(rank,no_of_prata,no_of_chef,mid)){
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
    int no_of_prata,no_of_chef;
    cin>>no_of_prata>>no_of_chef;
    int rank[1000];
    for(int i=0;i<no_of_chef;i++)
    {
        cin>>rank[i];
    }
    cout<<mintime(rank,no_of_prata,no_of_chef)<<endl;
    return 0;
}
