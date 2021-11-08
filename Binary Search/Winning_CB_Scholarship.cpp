#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int no_of_stud,int no_of_coupon,int coup_req,int coup_to_take){
    int s=0;
    int e= no_of_stud;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(mid*coup_req<=no_of_coupon+(no_of_stud-mid)*coup_to_take){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;

}

int main() {
    int no_of_stud,no_of_coupon,coup_req,coup_to_take;
    cin>>no_of_stud>>no_of_coupon>>coup_req>>coup_to_take;
    cout<<solve(no_of_stud,no_of_coupon,coup_req,coup_to_take)<<endl;
    return 0;
}
