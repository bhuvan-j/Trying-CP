#include <iostream>
#include<set>
#include<string>
#include<cmath>
using namespace std;
bool canplace(int mat[][9],int i,int j,int n, int number){
    for(int x=0;x<n;x++){
        //check if the number is in row or column
        if(mat[i][x]==number||mat[x][j]==number){
            return false;
        }
    }
    int rn=sqrt(n);
    //starting x of the subgrid
    int sx=(i/rn)*rn;
   // starting y of the subgrid
    int sy=(j/rn)*rn;

    //check if number is in the subgrid
    for(int x=sx;x<sx+rn;x++){
        for(int y=sy;y<sy+rn;y++){
            if(mat[x][y]==number){
                return false;
            }

        }
    }

    //if it is not there return true
return true;
    }

bool sudoku(int mat[][9],int i,int j,int n){
    if(i==n){
        //if i is n means whole matrix is covered and solved. simply print it and return true.
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //it means we have reached the end column and moving out of the matrix.
    //we have to go to next row
    if(j==n){
        return sudoku(mat,i+1,0,n);
    }

    //if the box is already filled simply skip that box
    if(mat[i][j]!=0){
        return sudoku(mat,i,j+1,n);
    }


    for(int no=1;no<=n;no++){//no.can be from 1 to n
        if(canplace(mat,i,j,n,no)){ // if the no is placable in that box
            mat[i][j]=no; // place it
            bool next= sudoku(mat,i,j+1,n); // solve the leftover 
            if(next){
                return true; // if the leftover is solved. means whole is solved. return true
            }
        }
    }
//backtracking
mat[i][j]=0;

return false;
}


int main() {
    
  int mat[9][9]={
      {5,3,0,0,7,0,0,0,0},
      {6,0,0,1,9,5,0,0,0},
      {0,9,8,0,0,0,0,6,0},
      {8,0,0,0,6,0,0,0,3},
      {4,0,0,8,0,3,0,0,1},
      {7,0,0,0,2,0,0,0,6},
      {0,6,0,0,0,0,2,8,0},
      {0,0,0,4,1,9,0,0,5},
      {0,0,0,0,8,0,0,7,9}
  };


sudoku(mat,0,0,9);

}
