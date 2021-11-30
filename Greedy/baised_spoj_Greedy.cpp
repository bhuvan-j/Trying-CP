#include <iostream>
using namespace std;
int main() {
    int t;
    int arr[10000];
    cin>>t;
    while(t--){
        memset(arr,0,sizeof(arr));
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string name;int rank;
            cin>>name>>rank;
            arr[rank]++;
        }

        int actual_rank=1;
        int sum=0;
        for(int i=1;i<=n;i++){
            while(arr[i]){
            sum+=abs(actual_rank-i);
            arr[i]--;
            actual_rank++;
            }

        }
        cout<<sum<<endl;

    }
}
