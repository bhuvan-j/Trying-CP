#include <iostream>
using namespace std;
int first_occurence(int a[],int n,int key){
int s=0;
int e=n-1;
int ans= -1;
//update ans in a direction where index gets lower and lower

while(s<=e){
    int mid=(s+e)/2;
    if(a[mid]==key){
        ans= mid;
        e=mid-1;

    }
    else if(a[mid]>key){
        e=mid-1;
    }
    else{
        s=mid+1;
    }
}
return ans;
}


int last_occurence(int a[],int n,int key){
int s=0;
int e=n-1;
int ans= -1;
//update ans in a direction where index gets greater and greater

while(s<=e){
    int mid=(s+e)/2;
    if(a[mid]==key){
        ans= mid;
        s=mid+1;

    }
    else if(a[mid]>key){
        e=mid-1;
    }
    else{
        s=mid+1;
    }
}
return ans;
}

int main() {
    int a[]={1,2,5,8,8,8,8,10,12,15};
    int key;
    int n= sizeof(a)/sizeof(int);
    cin>> key;
    cout<<first_occurence(a,n,key);
    cout<<endl<<last_occurence(a,n,key);
}
