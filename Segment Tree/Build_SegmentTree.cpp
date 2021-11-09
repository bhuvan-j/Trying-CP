#include <iostream>
#include<bits/stdc++.h>
void buildtree(int *a,int *tree,int s,int e,int index){
    if(s==e){
        tree[index]=a[s];
        return;
    }
    int mid=(s+e)/2;
    buildtree(a,tree,s,mid,2*index);
    buildtree(a,tree,mid+1,e,2*index+1);
    tree[index]=std::min(tree[2*index],tree[2*index+1]);
    return;
}
using namespace std;
int main() {
    int a[]={1,3,2,-5,6,4};
    int n=sizeof(a)/sizeof(int);
    int *tree= new int[4*n+1];
    buildtree(a,tree,0,5,1);

    for(int i=1;i<=13;i++){
cout<<tree[i]<<" ";
    }
    return 0;
}
