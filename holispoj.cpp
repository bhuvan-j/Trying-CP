#include <iostream>
#include<list>
using namespace std;
class graph{
    int v;
    list<pair<int,int>> *l;
    public:
    graph(int V)
    {
        v=V;
        l = new list<pair<int,int>>[v];

    }
    void addedge(int u,int b,int cost){
        l[u].push_back(make_pair(b,cost));
        l[b].push_back(make_pair(u,cost));
    }

    int dfs_helper(int node,bool* visited,int* count,int &ans){
        visited[node]=true;
        count[node]=1;
        for(auto nbr_p: l[node]){
            if(!visited[nbr_p.first]){
                count[node]+=dfs_helper(nbr_p.first,visited,count,ans);
                int nx=count[nbr_p.first];
                int ny= v- nx;
                ans+=(2*min(nx,ny)*nbr_p.second);

            }
        }
        return count[node];
    }
    int dfs(){
        bool *visited= new bool[v]{false};
        int *count= new int[v]{0};
        int ans=0;
        dfs_helper(0,visited,count,ans);
        return ans;
    }
};
int main() {
    graph g(4);
    g.addedge(0,1,3);
    g.addedge(1,2,2);
    g.addedge(3,2,2);
    cout<<g.dfs();
    
    return 0;
}
