#include <iostream>
using namespace std;

bool isSafe(int arr[][10],int row,int col,int n){

    //Column Check
    for(int i=0;i<row;i++){
        if(arr[i][col]==1)
            return false;
    }

    //Left Diagonal
    int x=row;
    int y=col;
    while(x>=0 && y>=0){
        if(arr[x][y]==1)
            return false;
        x--;
        y--;
    }

    //Right Diagonal
    x = row;
    y = col;

    while(x>=0 && y<=n){
        if(arr[x][y]==1)
            return false;
        x--;
        y++;
    }

    return true;
}

bool NQueenConfig(int arr[][10],int row,int n){

    if(row==n){
        //BaseCase
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1)
                    cout << "Q " ;
                else
                    cout << "* ";
            }
            cout << endl;
        }
        cout << endl;
        //True for just one Configuration
        return false;
    }
    //Recursive Case
    for(int col=0;col<n;col++){

        if(isSafe(arr,row,col,n)){
            arr[row][col] = 1;
           bool ifPossible = NQueenConfig(arr,row+1,n);
           if(ifPossible){
               return true;
           }
           //Backtrack
           arr[row][col] = 0;
        }
    }
    return false;

}
int main() {
    int n;
    cin >> n;
    int arr[10][10] = {0};
    NQueenConfig(arr,0,n);
    return 0;
}
