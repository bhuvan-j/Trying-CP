#include <iostream>
using namespace std;
//BUBBLE SORT - 
/* 
- n-1 passes
- In each pass , the heaviest element goes to the end.
- In ith pass, ith largest goes to end. thats why (n-1) passes.
- Pairwise comparison.

eg- 5 4 3 1
1st pass - (4 5) 3 1 -> 4 (3 5) 1 -> 4 3 (1 5)  (length of unsorted array is now n-1 as 1 element is sorted from right.)
2nd pass - (3 4) 1 5 -> 3 (1 4) 5 -> 3 1 (4 5) (length of unsorted array is now n-2 as 2 elements are sorted from right.)
3rd pass - (1 3) 4 5  
*/
void bubble_sort(int a[], int n){
    //base case
    if(n==1){ //array of length 1 is always sorted.
        return;
    }

    //recursive case
    //pairwise comparison
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
    //first, heaviest element is pushed to end. then recursively sorting remaining (n-1) elements.
    bubble_sort(a,n-1);
}


//Now we will try to convert iteration to recursive. whole function as recursive.
void bubble_sort_completely_recursive(int a[],int j, int n){
    //base 
    if(n==1){return ;}

    if(j==n-1){
        // it means pairwise comparison has been done 1 time and u r pointing to the last element.
        // 4  3  1  5 <---(5 is sorted now)
        //          ^
        //          |
        // its time for next pass. starting from 0th index. but we will not consider last element as it is sorted now.
        // from 0 to n-1.
        
        return bubble_sort_completely_recursive(a,0,n-1);

    }

    if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
    }
    bubble_sort_completely_recursive(a,j+1,n);

}

int main() {
    int a[]={5,4,3,1,2};
    int n=5;
    bubble_sort_completely_recursive(a,0,n);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

}
