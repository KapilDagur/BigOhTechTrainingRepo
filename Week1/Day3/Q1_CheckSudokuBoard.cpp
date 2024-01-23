#include<bits/stdc++.h>
using namespace std;


bool isAllRowsValid(vector<vector<char>>& sudoku_board){
    int i = 0, j = 0,k;
    //For Row wise checking of each number...
    while (i < 9)
    {
        j = 0;
        while (j < 9)
        {
            if(sudoku_board[i][j] == '.')
                j++;
            else{
                k = j + 1;
                while (k < 9){
                    if(sudoku_board[i][j] == sudoku_board[i][k])
                        return false;
                    k++;
                }
            }
            j++;     
        }
        i++;
    }
    return true;
}

bool isAllColumnsValid(vector<vector<char>>& sudoku_board){
    int i = 0, j = 0,k;
    //For column wise checking of each number...
    while (i < 9)
    {
        j = 0;
        while (j < 9)
        {
            if(sudoku_board[j][i] == '.')
                j++;
            else{
                k = j + 1;
                while (k < 9){
                    if(sudoku_board[j][i] == sudoku_board[k][i])
                        return false;
                    k++;
                }
            }
            j++;     
        }
        i++;
    }
    return true;
}

bool isGridValid(vector<vector<char>>& sudoku_board, int row, int col, int value){
    int subCol = col - col % 3;
    int subRow = row - row % 3;
    for(int i = subRow; i < subRow + 3; i++){
        for(int j = subCol; j < subCol + 3; j++){
            if(sudoku_board[i][j] == value && (i != row || j != col)){
                return false;
            }
        }
    }
    return true;
}

bool isAllGridValid(vector<vector<char>>& sudoku_board){
    for(int i = 0; i < sudoku_board.size(); i++){
        for(int j = 0; j < sudoku_board.size(); j++){
            if(!isGridValid(sudoku_board, i, j, sudoku_board[i][j]))
                return false;
        }
    }
    return true;
}


bool isValidSudoku(vector<vector<char>>& sudoku_board){
    return isAllRowsValid(sudoku_board) && isAllColumnsValid(sudoku_board) && isAllGridValid(sudoku_board);
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> sudoku_board1 = 
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout<<isAllGridValid(sudoku_board1);


    vector<vector<char>> sudoku_board2 = 
    {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout<<isAllColumnsValid(sudoku_board2);
    return 0;
}

