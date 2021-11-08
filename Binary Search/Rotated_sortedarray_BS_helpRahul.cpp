#include <iostream>
using namespace std;
int find_key_in_rotated_sorted_array(int *a,int n,int key){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[s]<=a[mid]){
            if((a[s]<=key)&&(a[mid]>=key)){
            e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        else{
            if(a[mid]<=key && a[e]>=key){
                s=mid+1;
            }
            else{
                e=mid-1;
            }

        }
    }

        return -1;
}
int main() {
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;

    cout<<find_key_in_rotated_sorted_array(a,n,key)<<endl;

}
