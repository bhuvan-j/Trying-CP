#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// 0-1 knapsack

int knapsack(int *a,int *profit,int i,int cap){
    if(i<0){
        return 0;
    }

    if(a[i]<=cap){
        return 
        max( (profit[i]+knapsack(a,profit,i-1,cap-a[i])),knapsack(a,profit,i-1,cap));
    }

    else return knapsack(a,profit,i-1,cap);
   
}
int main() {
    int a []= {1,2,3,5,2,8,9,2,1};
    int profit[]={40,20,3,100,33,57,21,45,22};
int n= 9;
int capacity=8;
    cout<<knapsack(a,profit,n-1,capacity);
  
}
