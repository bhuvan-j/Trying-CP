#include <iostream>
using namespace std;

int main() {
    float n=1,people,num,denom,p;
    people=0,num=denom=365;
    cin>>p;
    if(p==1){
        cout<<366<<" people";
        return 0;
    }
    while(n>1-p){
        n*=(num/denom);
        num--;
        people++;
    }
    cout<<people<<" people";
    return 0;

}
