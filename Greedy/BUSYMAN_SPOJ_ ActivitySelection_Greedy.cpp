#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
int main() {
    
    int t,activities;
    int s,e;
    vector<pair<int,int>>v;
    cin>>t;
    while(t--){
        cin>>activities;
        for(int i=0;i<activities;i++){
            cin>>s>>e;
            v.push_back(make_pair(s,e));
        }
        //Activity selection
        //sort
        sort(v.begin(),v.end(),compare); //sort acc to end time

        int count=1; //first activity will always happen
        int fin=v[0].second;
        for(int i=1;i<v.size();i++){
            if(v[i].first>=fin){
                fin=v[i].second;
                count++;
            }
        }

        cout<<count<<" activities can be done"<<endl;
        v.clear();
    }

    
}
