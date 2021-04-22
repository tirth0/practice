#include<iostream>
#include<vector>

using namespace std;

bool isSafe(vector<vector<int>> & maze,int x,int y,int r,int c){
    return (x>=0 && y>=0 && x<r && y<c && maze[x][y]==1);
}

bool mazeSolve(vector<vector<int>> & maze,int sx,int sy,int dx,int dy,int r,int c){

    if (!isSafe(maze,sx,sy,r,c))
        return false;

    if (sx==dx && sy==dy)
        return true;

    maze[sx][sy] = 0;

    //move right
    if (mazeSolve(maze,sx,sy+1,dx,dy,r,c))
        return true;
    //move left
    if (mazeSolve(maze,sx,sy-1,dx,dy,r,c))
        return true;
    //move up
    if (mazeSolve(maze,sx-1,sy,dx,dy,r,c))
        return true;
    //move down    
    if (mazeSolve(maze,sx+1,sy,dx,dy,r,c))
        return true;
    
    return false;
}

int main(){
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 1}
    };
    if (mazeSolve(maze,0,0,3,3,4,4))
        cout << "Impressive";
    else
        cout << "fail";
    return 0;
}