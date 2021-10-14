#include <iostream>
using namespace std;
// QUICK SORT

/* 


*/
int partition(int *a,int s,int e){
    //making 2 regions. one from s to i which is for smaller region and other till j for larger region.

    int i=s-1;
    int j=s;
    int pivot=a[e];
    for(;j<=e-1;){
        if(a[j]<=pivot){
            i=i+1;
            swap(a[i],a[j]);
        }
        j=j+1;
    }
    //bringing pivot element to its correct position.
    swap(a[i+1],a[e]);
    return i+1;

}
void quick_sort(int *a,int s,int e){
    if(s>=e){
        return;
    }

    //partition the array. all smaller elements in the left part and all the bigger elements in the right part.
    // (<elements) PIVOT (>elements)
    int p=partition(a,s,e);
    //sort left part of the array
    quick_sort(a,s,p-1);
    //sort right part of the array
    quick_sort(a,p+1,e);
}

int main() {
    int a[]={1,5,2,6,3,0};

    int n=sizeof(a)/sizeof(int);
    quick_sort(a,0,n-1);   

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    

}
