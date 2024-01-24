#include <bits/stdc++.h>
using namespace std;

bool checkBoard(int k_i, int k_j){
    return k_i >= 0 && k_i < 8 && k_j >= 0 && k_j < 8;
}

bool checkCamelAttack(char board[][8], char c , int i, int j){

    int k = 0;

    while (checkBoard(i + ++k, j + k)){
	    if (board[i + k][j + k] == c)
	        return true;
	    if (board[i + k][j + k] != '.')
	        break;
    }

    // Check the lower left diagonal
    k = 0;
    while (checkBoard(i + ++k, j - k)){
	    if (board[i + k][j - k] == c)
	        return true;
	    if (board[i + k][j - k] != '.')
	        break;
    }

    // Check the upper right diagonal
    k = 0;
    while (checkBoard(i - ++k, j + k)){
	    if (board[i - k][j + k] == c)
	        return true;
	    if (board[i - k][j + k] != '.')
	        break;
    }

    // Check the upper left diagonal
    k = 0;
    while (checkBoard(i - ++k, j - k)){
	    if (board[i - k][j - k] == c)
	        return true;
	    if (board[i - k][j - k] != '.')
	        break;
    }
    return false;
}

bool checkElephantAttack(char board[][8], char c, int i, int j){
    // Check downwards
    int k = 0;
    while (checkBoard(i + ++k, j)){
	    if (board[i + k][j] == c)
	        return true;
	    if (board[i + k][j] != '.')
	        break;
    }

    // Check upwards
    k = 0;
    while (checkBoard(i + --k, j)){
	    if (board[i + k][j] == c)
	        return true;
	    if (board[i + k][j] != '.')
	        break;
    }

    // Check right
    k = 0;
    while (checkBoard(i, j + ++k)){
	    if (board[i][j + k] == c)
	        return true;
	    if (board[i][j + k] != '.')
	        break;
    }

    // Check left
    k = 0;
    while (checkBoard(i, j + --k)){
	    if (board[i][j + k] == c)
	        return true;
	    if (board[i][j + k] != '.')
	        break;
    }
    return false;
}

// Function to check if Queen can attack the King
bool checkQueenAttack(char board[][8], char c, int i, int j){
    // Queen's moves are a combination of both the Camel and the Elephant
    if (checkCamelAttack(board, c, i, j) || checkElephantAttack(board, c, i, j))
	    return true;
	return false;
}

// Check if the Horse can attack the king
bool checkHorseAttack(char board[][8], char c, int i, int j){
    // All possible moves of the Horse
    int x[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int y[] = {1, -1, 1, -1, 2, -2, 2, -2};

    for(int k = 0; k < 8; k++){
	    int m = i + x[k];
	    int n = j + y[k];

    	if (checkBoard(m, n) && board[m][n] == c)
	        return true;
    }
    return false;
}

// Function to check if any of the two kings is unsafe or not
int checkBoard(char board[][8]){
    for (int i = 0; i < 8; i++){
	    for (int j = 0; j < 8; j++){
			if (board[i][j] == 'k'){
				// For Horse Attack
				if (checkHorseAttack(board, 'N', i, j))
					return 1;

				// For Elephant Attack
				if (checkElephantAttack(board, 'R', i, j))
					return 1;

				// For Camel Attack
				if (checkCamelAttack(board, 'B', i, j))
					return 1;

				// For Queen Attack
				if (checkQueenAttack(board, 'Q', i, j))
					return 1;
			}

			// Check for all pieces which can attack Black King
			if (board[i][j] == 'K'){
				//For Horse Attack
				if (checkHorseAttack(board, 'n', i, j))
					return 2;

				// For Elephant Attack
				if (checkElephantAttack(board, 'r', i, j))
					return 2;

				// For Camel Attack
				if (checkCamelAttack(board, 'b', i, j))
					return 2;

				// For Queen Attack
				if (checkQueenAttack(board, 'q', i, j))
					return 2;
			}
		}
	}
	return 0;
}

void test(char board[][8]){
    if (checkBoard(board) == 0)
	    cout <<"Both Kings are safe";

    else if (checkBoard(board) == 1)
	    cout <<"White king is unsafe";

    else
	    cout <<"Black king is unsafe";
}

// Driver Code
int main(){
    char board[][8] = {
                        {'.', '.', '.', 'k', '.', '.', '.', '.'},
				        {'p', 'p', 'p', '.', 'p', 'p', 'p', 'p'},
					    {'.', '.', '.', '.', '.', 'b', '.', '.'},
					    {'.', '.', '.', 'R', '.', '.', '.', '.'},
					    {'.', '.', '.', '.', '.', '.', '.', '.'}, 
					    {'.', '.', '.', '.', '.', '.', '.', '.'}, 
					    {'P', '.', 'P', 'P', 'P', 'P', 'P', 'P'}, 
					    {'K', '.', '.', '.', '.', '.', '.', '.'}
                    };
	test(board);
    return 0;
}