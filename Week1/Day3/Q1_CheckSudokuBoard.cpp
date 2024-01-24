#include <iostream>
#include <vector>
using namespace std;

/*
    @author : KAPIL DAGUR
*/

/*
    isValidSudoku function checks the input sudoku_board is valid or not
    in this we use vector for store occurance and if more than one occure
    than we can say that not a valid sudoku

    @param : sudoku_board(vector<vector<char>>)
    @return : bool
*/
bool isValidSudoku(vector<vector<char>>& sudoku_board){

    //Vector for check occurance of sudoku element
    //if occurace greater than once means not a valid as per sukodu condition
    vector<vector<bool>> cols(9, vector<bool> (9, false));
    vector<vector<bool>> grid(9, vector<bool> (9, false));

    for(int i = 0; i < 9; ++i)
    {
        vector<bool> rows(9, false);
        for(int j = 0; j < 9; ++j)
        {
            //Checking element of sudoku board and if non digit element continue
            if(!isdigit(sudoku_board[i][j]))
                continue;

            //Finding the actual index of element
            int idx = sudoku_board[i][j] - '1';

            //Validation for non existing if exist means element occure twice which is not happen
            //in sudoku game
            if(rows[idx] == true)
                return false;
            //setting the element in vector for feather check
            rows[idx] = true;

            //Checking column wise element in backup vector if exist the not valid condition as per sudoku game 
            if(cols[j][idx] == true)
                return false;

            //if arrived first time then setting it        
            cols[j][idx] = true;

            //finding grid index for validation of occurance
            int gridIdx = ((i/3) * 3) + (j/3);
          
            //Validating already exist or not
            if(grid[gridIdx][idx] == true)
                return false;
            
            //if arrived first time than setting it            
            grid[gridIdx][idx] = true;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> sudoku_sudoku_board1 = 
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

    cout<<isValidSudoku(sudoku_sudoku_board1)<<endl;

    vector<vector<char>> sudoku_sudoku_board2 = 
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
    cout<<isValidSudoku(sudoku_sudoku_board2)<<endl;
    return 0;
}

