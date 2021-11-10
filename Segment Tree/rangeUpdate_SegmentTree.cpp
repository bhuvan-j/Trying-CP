#include <iostream>
#include<bits/stdc++.h>
using namespace std;
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

int query(int *tree,int ss,int se,int qs,int qe,int index){
    if(qs<=ss and qe>=se){
        return tree[index];
    }
    else if(qs>se || qe<ss){
        return INT_MAX;
    }
    int mid=(ss+se)/2;
    int left=query(tree,ss,mid,qs,qe,2*index);
    int right=query(tree,mid+1,se,qs,qe,2*index+1);
    return min(left,right);

}

void updateNode(int *tree,int ss,int se,int i,int increment,int index){
    if(i<ss || i>se){
        return;
    }
    if(ss==se){
        tree[index]= tree[index]+ increment;
        return;
    }

    int mid=(ss+se)/2;
    updateNode(tree,ss,mid,i,increment,2*index);
    updateNode(tree,mid+1,se,i,increment,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);

}

void rangeupdate(int *tree,int ss,int se,int l,int r,int increment,int index){
    if(l>se || r<ss){
        return;
    }
    if(ss==se){
        tree[index]+=increment;
        return;
    }
    int mid=(ss+se)/2;
    rangeupdate(tree,ss,mid,l,r,increment,2*index);
    rangeupdate(tree,mid+1,se,l,r,increment,2*index+1);

    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}

int main() {
    int a[]={1,3,2,-5,6,4};
    int n=sizeof(a)/sizeof(int);
    int *tree= new int[4*n+1];
    buildtree(a,tree,0,5,1);

    rangeupdate(tree,0,n-1,3,5,+10,1);

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(tree,0,n-1,l,r,1)<<endl;
    }
    return 0;
}