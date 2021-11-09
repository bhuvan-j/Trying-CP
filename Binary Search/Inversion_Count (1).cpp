#include <iostream>
using namespace std;

int merge(int *a,int low,int mid,int high){
    int cnt=0;
    int c[1000];
    int k=low;
    int i=low;
    int j=mid+1;
    while(i<=mid and j<=high){
        if(a[i]<=a[j]){
            c[k++]=a[i++];
        }
        else{
            cnt=cnt+(mid-i)+1;
            c[k++]=a[j++];
    
    }
    }
    while(i<=mid){
        c[k++]=a[i++];
    }
    while(j<=high){
        c[k++]=a[j++];
    }
    for(int i=low;i<=high;i++){
        a[i]=c[i];
    }
    
return cnt;

}
int countInversions(int *a,int low,int high){
    
    if(low>=high){
        return 0;
    }
    int count=0;
    int mid=(low+high)/2;
    count+=countInversions(a,low,mid);
    count+=countInversions(a,mid+1,high);
    count+=merge(a,low,mid,high);
    return count;
}
int main() {
    int a[]={8,4,1,2};
    cout<<countInversions(a,0,3);
    cout<<endl;
    return 0;
}
