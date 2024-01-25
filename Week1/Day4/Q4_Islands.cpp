#include<bits/stdc++.h>
using namespace std;

/*
    breadthFirstSearch traverse matrix as BFS Algorithms
    @param : grid, visited, i, j
*/
void breadthFirstSearch(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
    visited[i][j] = true;
    int row = grid.size();
    int col = grid[0].size();
    queue<pair<int,int>> que;
    vector<int> rltr = {-1,0,1,0};
    vector<int> cltr = {0,1,0,-1};
    que.push({i, j}); 

    while(!que.empty()){
        int ii = que.front().first;
        int jj = que.front().second;
        que.pop();
        for(int dir = 0; dir < 4; dir++){
            int n_row = ii + rltr[dir];
            int n_col = jj + cltr[dir];
            if(n_row >= 0 && n_row < row && n_col >= 0 && n_col < col && grid[n_row][n_col] == '1' && !visited[n_row][n_col]){
                visited[n_row][n_col] = true;
                que.push({n_row,n_col});
            }
        }

    }
}

int numberOfIslands(vector<vector<char>>& grid){
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<bool>> visit(row,vector<bool>(col, false));
    int number = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == '1' && !visit[i][j]){
                number++;
                breadthFirstSearch(grid, visit, i, j);
            }
        }
    }
    return number;
}

/*
    Test Cases for Number Of Islands
*/

void test(){
    //Test 1 input
    vector<vector<char>> grid1 = 
    {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout<<"Number of Islands is Test 1 : "<<numberOfIslands(grid1)<<endl;

    //Test 2 input
    vector<vector<char>> grid2 = 
    {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout<<"Number of Islands is Test 2 : "<<numberOfIslands(grid2)<<endl;

}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}