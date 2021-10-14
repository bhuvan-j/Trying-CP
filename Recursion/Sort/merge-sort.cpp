#include <iostream>
using namespace std;
//MERGE SORT - 
/* 
Mantra - DIVIDE SORT MERGE

-divide and conquer algorithm

- we divide array into 2 parts of size n/2 each.

                     [ 5,6,1,2,4,0 ]
                       |           |
         s--> [5,6,1] <--mid      mid+1--> [2,4,0] <--end

- Now we recursively sort the two arrays,

         [5,6,1]   &   [2,4,0]  
           ||            ||
         [1,6,5]       [0,2,4]

- Merge the 2 sorted arrays using 2 pointer approach

            [0,1,2,4,5,6]

-
*/
void mergesortedarray(int *a,int start, int end){
    int mid=(start+end)/2;
    int i=start;
    int j=mid+1;
    int k=start;
    int temp[100];
    while(i<=mid&&j<=end){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{
                 temp[k++]=a[j++];
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=end){
        temp[k++]=a[j++];
    }

    // copy temp array to original array
    for(int i=start;i<=end;i++){
        a[i]=temp[i];
    }
}

void merge_sort(int a[],int start,int end){
    //base case - 0 or 1 elements
    if(start>=end){
        return;
    }
    //3 steps
    //1. divide
    int mid=(start+end)/2;
     // 2. sort 2 arrays recursively
     merge_sort(a,start,mid);
     merge_sort(a,mid+1,end);
     //3. merge the two sorted arrays.
     mergesortedarray(a,start,end);


}
int main() {
    int a[]={5,4,3,1,2};
    int n=5;
   merge_sort(a,0,4);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

}
