#include <iostream>
using namespace std;
int lastoccur(int *a,int n, int key){
    if(n==0){
        return -1;
    }
    int i=lastoccur(a+1,n-1,key);
    if(i==-1){
        if(a[0]==key){
            return 0;
        }
        else{
            return -1;
        }
    }
    return i+1;
}
int firstoccur(int * a, int n, int key){
    if(n==0){return -1;}
    if(a[0]==key){return 0;}
    
        int i=firstoccur(a+1,n-1,key);
        if(i==-1){return -1;}
        return i+1;

}
int main() {
    int a[]={1,2,3,4,7,2,3,0,7,6};
    int n=sizeof(a)/sizeof(int);
    cout<<lastoccur(a,n,7);
} 
