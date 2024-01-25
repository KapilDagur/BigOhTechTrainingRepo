#include <bits/stdc++.h>
using namespace std;

bool checkBoard(int k_i, int k_j){
    return k_i >= 0 && k_i < 8 && k_j >= 0 && k_j < 8;
}

bool checkCamelAttack(char board[][8], char c , int i, int j){

    int k = 0;
	// Check the lower right diagonal
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
    // Check horizantol Downwards
    int k = 0;
    while (checkBoard(i + ++k, j)){
	    if (board[i + k][j] == c)
	        return true;
	    if (board[i + k][j] != '.')
	        break;
    }

    // Check horizantol Upwards
    k = 0;
    while (checkBoard(i + --k, j)){
	    if (board[i + k][j] == c)
	        return true;
	    if (board[i + k][j] != '.')
	        break;
    }

    // Check vertical right
    k = 0;
    while (checkBoard(i, j + ++k)){
	    if (board[i][j + k] == c)
	        return true;
	    if (board[i][j + k] != '.')
	        break;
    }

    // Check vertical left
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
bool checkBoard(char board[][8]){
	int i,j;
	for(i = 0; i < 8; i++)
		for(j = 0; j < 8; j++)
			if(board[i][j] == 'k')
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
			
	return 0;
}

// Driver Code
int main(){
    char board[][8] = 
	{
        {'.', '.', '.', 'k', '.', '.', '.', '.'},
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	    {'.', '.', '.', 'H', '.', '.', '.', '.'},
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	    {'.', '.', '.', '.', '.', '.', '.', '.'}, 
		{'.', '.', '.', '.', '.', '.', '.', '.'}, 
		{'.', '.', '.', '.', '.', '.', '.', '.'}, 
	    {'.', '.', '.', '.', '.', '.', '.', '.'}
    };
	cout<<checkBoard(board)<<endl;	
    return 0;
}