#include <iostream>
using namespace std;
bool rat_in_a_maze(char maze[10][10], int sol[][10],int i,int j, int m,int n){
if(i==m && j==n){
    sol[i][j]=1;
    //printpath
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<sol[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    return true;
}
if(i>m ||j >n || maze[i][j]=='X'){
    return false;
}

//assuming there is a path from this node/box
sol[i][j]=1;

//checking if theres a path from neighbours. recursive call
 bool rt=rat_in_a_maze(maze,sol,i,j+1,m,n);
 bool dwn=rat_in_a_maze(maze,sol,i+1,j,m,n);

 //Backtracking. 
 sol[i][j]=0;

 if(rt || dwn){
     return true;
 }
 
 return false;


}

int main() {
    
    char maze[10][10]={
        "0000",
        "00X0",
        "000X",
        "0X00"
    };

    int sol[10][10]={0};
    bool ans=rat_in_a_maze(maze,sol,0,0,3,3);
    if(ans==false){
        cout<<"path doesnt exist"<<endl;
    }
    return 0;


}
