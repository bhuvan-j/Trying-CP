#include <iostream>
using namespace std;
void alloccur(int *a,int i,int n, int key){
    if(i==n){
        return;
    }
    if(a[i]==key){
        cout<<i<<endl;
    }
    alloccur(a,i+1,n,key);
    
}

int main() {
    int a[]={1,2,3,4,7,2,3,0,7,6};
    int n=sizeof(a)/sizeof(int);
   alloccur(a,0,n,7);
} 
