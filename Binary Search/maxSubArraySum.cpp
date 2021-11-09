#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int merge(int *a,int low,int mid,int high){
    int leftsum=INT_MIN;
    int rightsum=INT_MIN;
    int i=mid;
    int j=mid+1;
    while(i>=low){
        if(leftsum+a[i]>leftsum){
            leftsum=leftsum+a[i];
            i--;
        }
        else{
            break;
        }
    }
    while(j<=high){
        if(rightsum+a[j]>rightsum){
            rightsum=rightsum+a[j];
            j++;
        }
        else{
            break;
        }
    }
    return leftsum+rightsum;
}
int maxSubarraySum(int *a,int low,int high){
    if(low>high){
        return 0;
    }

    else if(low==high){
        return a[low];
    }

    int mid=(low+high)/2;
    int x=maxSubarraySum(a,low,mid);
    int y=maxSubarraySum(a,mid+1,high);
    int z=merge(a,low,mid,high);
    return max({x,y,z});
}
int main() {
    int a[]={-10,5,10};
    cout<<maxSubarraySum(a,0,2);
    cout<<endl;
    return 0;
}
