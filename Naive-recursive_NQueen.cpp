#include <iostream>
#include<set>
#include<string>
using namespace std;
//NAIVE APPROACH. CHECK ADVANCED BACKTRACKING USING BITMASK FOR EFFICIENT APPROACH.
bool canplace(int board[][10],int i,int j,int n){
    int x=i;
    int y=j;
    //left diagonal
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
  
   x=i;
     y=j;
     //right diagonal
    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
  
  //upper column
    for(int row=0;row<i;row++){
        if(board[row][j]==1){
            return false;
        }
    }
    return true;
}

bool nqueen(int board[][10],int i,int n){
    //base case
    if(i==n){
        //print the config
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    cout<<"Q"<<" ";
                }
            
                else{
                cout<<"_ ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return false;    //for all answer - return false
        //for one path return true
    }

    for(int j=0;j<n;j++){
        if(canplace(board,i,j,n)){ //check if it allowed to place queen in the box
            board[i][j]=1;  //if yes, assume its correct and solve for remainnig board
            if(nqueen(board,i+1,n)){
                return true;
            };
            // here it means you didnt recieve the sol, so backtrack and remove queen from the box
            board[i][j]=0;
        }
    }

//means u tried all ways but no sol was found. so return false.
 return false;

}


int main() {
  int n;
  int board[10][10]={0};
  cin>>n;
  nqueen(board,0,n);
  return 0;
}
