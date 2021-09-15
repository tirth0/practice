#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n";
using namespace std;

void displayBoard(vector<vector<int>> board){
    for (int i=0;i<board.size();i++){
        for (int j=0;j<board[0].size();j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(vector<vector<int>> board,int row,int col,int N){
    int i,j;
    for (i=0;i<col;i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		if (board[i][j]) 
			return false; 

    for (i=row,j=col;j>=0 && i<N;i++,j--)
        if (board[i][j])
            return false;

    return true;
}

bool NQsolver(vector<vector<int>> & board, int col,int N){
    if (col>=N)
        return true;
    
    for (int i=0;i<N;i++){
        if (isSafe(board,i,col,N)){
                board[i][col] = 1;
            if (NQsolver(board,col+1,N))
                return true;
            board[i][col] = 0; 
        }
    }
    return false;
}

int main(){
    vector<vector<int>> board = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int N = 4;
    if (!NQsolver(board,0,4))
        cout << "No Solution";
    else 
        displayBoard(board);
    return 0;
}
