#include <iostream>
#include<set>
#include<string>
#include<bitset>
using namespace std;

//most advanced and optimised version of N-Queen problem

int done=0;
int ans=0;
void solve(int rowmask,int ld, int rd){
    if(rowmask==done){
        // if rowmask = 1111 (for n= 4)
        // means all row are filled with queen. means we get an answer. so ans++
        ans++;
        return;
    }

    int safeplaces = done & (~(rowmask | ld | rd));

    /*for ex =>
        row mask = 00100
        ld= 01000
        rd=00010

        if we add ld | rd| rowmask = 01110

        means all the position with 1 are not safe.
        now if we take ~ of it , it will invert bits = 10001
        now all the set bits are safe places where we can put queen

        */



    while(safeplaces){
        int p = safeplaces &(-safeplaces);
        // it is a trick to retrieve the set bit.


        safeplaces=safeplaces-p;
        solve(rowmask | p /* adding your current position to original rowmask as this position is now filled. */,
                 (ld<<1) /* broadcasting the left diagonal ka effect to next row*/  | (p<<1) /* abh jo queen rakha uski wajah se jo left diagonal me effect aaega wo*/ , 
                 (rd|p)>>1 /* same concept as ld */ );
    }
    return;
    
}


int main() {
  int n;

  cin>>n; // lets say n=4;
  
  done=((1<<n)-1); // 10000 -1 = 1111 (4 ones)
  solve(0,0,0); // initially rowmask is 0 , left diagonal is 0 and right diagonal is 0.
  //it means that initially all the positions are safe to put the queen in that row.
  cout<<endl<<ans;
  return 0;
}
