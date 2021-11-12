#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int a[N];
struct segmenttree_of_vectors{
    vector<int> st[4*N+1];
    void build(int start,int end,int index){
        if(start==end){
            st[index].push_back(a[start]);
            return;
        }
        int mid=(start+end)/2;
        build(start,mid,2*index);
        build(mid+1,end,2*index+1);
        merge(st[2*index].begin(),st[2*index].end(),
            st[2*index+1].begin(),st[2*index+1].end(),
            back_inserter(st[index]));
    }
    int query(int start,int end,int l,int r,int k,int index){
        if(start>r or l>end){
            return 0;
        }
        if(start>=l && end<=r){
            return st[index].size()
            -(
                upper_bound(st[index].begin(),st[index].end(),k)
            -st[index].begin()
            );
        }
        int mid=(start+end)/2;
        int left=query(start,mid,l,r,k,2*index);
        int right=query(mid+1,end,l,r,k,2*index+1);
        return left+right;
    }
} tree;
int main() {
    int n,i,j,k;
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    tree.build(0,n-1,1);

    int q;
    cin>>q;
    while(q--){
        int l,r,k;
        cin>>i>>j>>k;
        l=i^ans;
        r=j^ans;
        k^=ans;
        l--;r--;
        ans=tree.query(0,n-1,l,r,k,1);
        cout<<ans<<endl;
    }

}
