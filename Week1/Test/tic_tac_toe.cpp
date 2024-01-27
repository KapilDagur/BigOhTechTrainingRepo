#include<bits/stdc++.h>
using namespace std;


//To Check weather a place is occupied or not
inline bool isOccupiedPlace(const vector<vector<bool>>& board, const pair<int,int> turn){
    return board[turn.first][turn.second];
}

//To generate a pair of index for computer turn
inline pair<int,int> computerTern(){
    return {random() % 3, random() % 3};
}

//To Display Tic Tac Toe Board
void displayBoard(const vector<vector<bool>> board){
    cout<<"     Board"<<endl;
    cout<<"---------------"<<endl;
    for(const vector<bool> row : board){
        for(const bool column : row){
            cout<<"| "<<column<<" |";
        }
        cout<<endl<<"---------------"<<endl;
    }
    cout<<endl;
}

//Check game win, lose and draw possibleties..
int check(const vector<vector<bool>>& board, bool tern){

}

int main(int argc, char const *argv[])
{
    vector<vector<bool>> board(3,vector<bool>(3,false));
    // cout<<random();
    displayBoard(board);
    
    return 0;
}
