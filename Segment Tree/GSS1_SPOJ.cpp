#include <iostream>
#include<climits>
#define MAX 5000
using namespace std;

struct treenode{
    int totalsum;
    int prefixsum;
    int suffixsum;
    int maxsubarraysum;
};

treenode tree[4*MAX+1];

void buildtree(int *a,treenode *tree,int s,int e,int index){
    if(s==e){
        tree[index].totalsum=a[s];
        tree[index].prefixsum=a[s];
        tree[index].suffixsum=a[s];
        tree[index].maxsubarraysum=a[s];
        return;
    }
    int mid=(s+e)/2;
    buildtree(a,tree,s,mid,2*index);
    buildtree(a,tree,mid+1,e,2*index+1);
        tree[index].totalsum=tree[2*index].totalsum+tree[2*index+1].totalsum,
        tree[index].prefixsum=std::max(tree[2*index].totalsum+tree[2*index+1].prefixsum,tree[2*index].prefixsum),
        tree[index].suffixsum=std::max(tree[2*index+1].totalsum+tree[2*index].suffixsum,tree[2*index+1].suffixsum),
        tree[index].maxsubarraysum=std::max(tree[2*index].maxsubarraysum,std::max(tree[2*index+1].maxsubarraysum,tree[2*index].suffixsum+tree[2*index+1].prefixsum));

}

treenode maxsumquery(treenode *tree,int ss,int se,int qs,int qe,int index){
    if(qs>se or qe<ss){
        treenode x=(treenode){INT_MIN,INT_MIN,INT_MIN,INT_MIN};
        return x;
    }
    if(ss>=qs && se<=qe){
        return tree[index];
    }
    int mid=(ss+se)/2;
    treenode a=maxsumquery(tree,ss,mid,qs,qe,2*index);
    treenode b=maxsumquery(tree,mid+1,se,qs,qe,2*index+1);

    treenode c;
        c.totalsum=a.totalsum+b.totalsum;
        c.prefixsum=std::max(a.totalsum+b.prefixsum,a.prefixsum),
        c.suffixsum=std::max(b.totalsum+a.suffixsum,b.suffixsum),
        c.maxsubarraysum=std::max(a.maxsubarraysum,std::max(b.maxsubarraysum,a.suffixsum+b.prefixsum));
    return c;
}


int main() {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    buildtree(a,tree,0,n-1,1);
    int l,r;
    cin>>l>>r;
    treenode ans=maxsumquery(tree,0,n-1,l,r,1);
    cout<<ans.maxsubarraysum<<endl;
    return 0;
}
