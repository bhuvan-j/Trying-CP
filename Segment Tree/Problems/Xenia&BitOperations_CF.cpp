#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000000
int tree[MAX];
void buildtree(int *a,int s,int e,int index){
    if(s==e){
        tree[index]=a[s];
        return;
    }
    int mid=(s+e)/2;
    buildtree(a,s,mid,2*index);
    buildtree(a,mid+1,e,2*index+1);
    int times=log2(e-s+1);
    if(times&1){// if n is odd ( where n is the power of 2 (2^n) )
        tree[index]=tree[2*index] | tree[2*index+1];
    }
    else{
        tree[index]=tree[2*index]^tree[2*index+1];
    }

}

void update(int *tree,int ss,int se,int ind,int up,int index){
    if(ind<ss or ind>se){
        return;
    }

    if(ss==se){
       tree[index]=up;
       return;
    }

    int mid=(ss+se)/2;
    update(tree,ss,mid,ind,up,2*index);
    update(tree,mid+1,se,ind,up,2*index+1);
    int times=log2(se-ss+1);
    if(times&1){// if n is odd ( where n is the power of 2 (2^n) )
        tree[index]=tree[2*index] | tree[2*index+1];
    }
    else{
        tree[index]=tree[2*index]^tree[2*index+1];
    }


}
int main() {
    int n,m;
    cin>>n>>m;
    n=pow(2,n);
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    buildtree(a,0,n-1,1);
    while(m--){
        int i,j;
        cin>>i>>j;
        update(tree,0,n-1,i-1,j,1);
        cout<<tree[1]<<endl;

    }
    
}
