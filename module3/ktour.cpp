#include<iostream>
#include<vector>
#define N 9
using namespace std;

bool isSafe(int x,int y,int sol[N][N]){
    return (x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1);
}

bool KTsolver(int sol[N][N],int x,int y,int mv,int xMove[N],int yMove[N]){
    int k,nx,ny;
    if (mv == N*N) 
        return true;
    
    for (k=0;k < 8;k++){
        nx = x + xMove[k];
        ny = y + yMove[k];
        if (isSafe(nx,ny,sol)){
            sol[nx][ny] = mv;
            if (KTsolver(sol,nx,ny,mv+1,xMove,yMove))
                return true;
            else
                sol[nx][ny] = -1;
        }
    }
    return false; 
}

void printSolution(int sol[N][N]){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++)
            cout << sol[i][j] << "\t";
        cout << endl;
    }
}

int main(){
    int sol[N][N];
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    sol[0][0] = 0;
    if (!KTsolver(sol,0,0,1,xMove,yMove)) {
        cout << "Solution does not exist";
    }
    else
        printSolution(sol);
}