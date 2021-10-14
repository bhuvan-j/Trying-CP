#include <iostream>
using namespace std;
//Q- INVERSION COUNT 
// given an array, we have to find all pair such that i<j but arr[i]>arr[j].
//-----------------------------------------------------------------------------
/* 
- DIVIDE AND CONQUER.
- SIMILAR TO MERGE SORT.
given - [1,5,2,6,3,0]
-divide the array into 2 parts.
           [1,5,2]         [6,3,0]

- total number of inverted pairs =
             pairs in part 1 + pairs in part 2 + cross-pairs

- Recursively find pairs of part 1 and part 2.
          (5,2)           (6,3),(3,0),(6,0)-----------------       (+4 )

-now we have to find cross pairs.

-if we SORT part 1 and part 2, it will make NO difference in cross pairs.
- because relative position of number will be same. (part 1 will always be before part 2.)

-SORT-
[1,2,5]                 [0,3,6]

- HERE COMES THE TRICK!!!
    -start merging the two arrays ;)

    [0,_,_,_,_,_]  0 comes first. 
        means (0 is smaller than 1).
        as it is smaller than 1 , it will also be smaller than all other numbers in part 1 because the array is sorted. 
        hence, 0 can make pairs with all (1,2,5).
        HENCE WE GET 3 PAIRS FROM HERE.----------------------     ( +3 )

    [0,1,_,_,_,_] it will not contribute to our answer.
    [0,1,2,_,_,_] it will not contribute to our answer.

    [0,1,2,3,_,_] 3 is smaller than 5. we get 1 pair from here. (5.3)----- ( +1 )

    [0,1,2,3,5,_] it will not contribute to our answer.
    [0,1,2,3,5,6] it will not contribute to our answer.


We get total pairs = 4+3+1 = 8.


*/

//Notice similarity with merge sort

int merge(int *a, int s, int e){
    int mid=(s+e)/2;
    int i=s;
    int j= mid+1;
    int k=s;
    
    int temp[100];
    int count=0;
    while(i<=mid && j<=e){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
            count+=(mid-i+1);  // j will be smaller from ith position to end position of first part which is the mid position.

        }
    }
        while(i<=mid){
            temp[k++]=a[i++];
            
        }
        while(j<=e){
            temp[k++]=a[j++];
            
        }
        for(int i=s;i<=e;i++){
            a[i]=temp[i];
        }
        return count;
    }

int inversioncount(int *a,int s, int e){
    if(s>=e){
        return 0;
    }
    int mid=(s+e)/2;
    int x= inversioncount(a,s,mid);       // part 1 count
    int y= inversioncount(a,mid+1,e);     // part 2 count
    int z= merge(a,s,e);                  // count of cross inversions
    return x+y+z;

}

int main() {
    int a[]={1,5,2,6,3,0};
    int n=sizeof(a)/sizeof(int);
    cout << inversioncount(a,0,n-1);
    

}
