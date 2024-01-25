#include<bits/stdc++.h>
using namespace std;

/*
    breadthFirstSearch traverse matrix as BFS Algorithms
    @param : grid, visited, i, j
    @return : void
*/
void breadthFirstSearch(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
    visited[i][j] = true;   //setting matrix node as visisted
    int row = grid.size();      // getting row of grid
    int col = grid[0].size();       //getting column of grid
    queue<pair<int,int>> que;       //allocating queue as per bfs requirement
    vector<int> rltr = {-1,0,1,0};      //
    vector<int> cltr = {0,1,0,-1};
    que.push({i, j}); 

    while(!que.empty()){        //Iteration for visit each adjecent node
        int ii = que.front().first;     //getting i'th of node(row no.)
        int jj = que.front().second;    //getting j'th of node(column no.)
        que.pop();      //pop the element from queue
        for(int dir = 0; dir < 4; dir++){   //Iteration for direction
            int n_row = ii + rltr[dir];     //calculating nth row for visit 
            int n_col = jj + cltr[dir];     //calculating nth column for visit
            //Condition for valid row and column move and as well as island and visited first time 
            if(n_row >= 0 && n_row < row && n_col >= 0 && n_col < col && grid[n_row][n_col] == '1' && !visited[n_row][n_col]){
                visited[n_row][n_col] = true;   //setting as visited
                que.push({n_row,n_col});    //appending into queue for feather working
            }
        }

    }
}

/*
    numberOfIslands func. perform operation to find out island
    @param : grid(vector<vector<char>>)
    @return : int
*/
int numberOfIslands(vector<vector<char>>& grid){
    int row = grid.size();      //Store no. of row of grid
    int col = grid[0].size();       //Store no. of column od grid
    vector<vector<bool>> visit(row,vector<bool>(col, false));   //Flags for node is visited or not
    int number = 0;     //Count number of islands
    for(int i = 0; i < row; i++){   //Iteration for visit each islands row
        for(int j = 0; j < col; j++){   //Iterator for visit each islands column
            if(grid[i][j] == '1' && !visit[i][j]){
                number++;
                breadthFirstSearch(grid, visit, i, j);  //Calling breadthFirstSearch func.
            }
        }
    }
    return number;  //returning number
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