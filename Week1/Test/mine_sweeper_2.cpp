#include<bits/stdc++.h>
using namespace std;
/*
    KAPIL DAGUR
*/

//For User Input Validation
inline bool isValidInputByUser(const pair<int,int>& input, int size){
    return (isdigit(input.first)
         && isdigit(input.second)
         && input.first < size
         && input.first > 0 
         && input.second < size 
         && input.second > 0
         );
}

//For User Input
pair<int,int> userInput(){
    int row, col;
    cout<<"Enter Row Number : ";
    cin>>row;
    cout<<"Enter Column Number : ";
    cin>>col;
    return {row-1,col-1};
}

//For input functioning
pair<int,int> input(int size){
    pair<int,int> user_term;
    while(true){
        user_term = userInput();
        if(isValidInputByUser(user_term,size))
            continue;
        else
            break;
    };
    return user_term;
}

//For get a random position for place bomb
inline pair<int,int> randomPosition(int size){
    return {random() % size, random() % size};  //To generate random pair with cordinates
}

//For generate a random board placed with random bombs
void generateRandomBoard(vector<vector<char>>& board){
    int term = board.size();
    int size = board.size();
    pair<int,int> position; 
    while (term > 0)
    {
        position = randomPosition(size);    //To get random position
        if(board[position.first][position.second] == '.'){
            board[position.first][position.second] = 'B';
            term--;
        }
    }
}

//For Display Board Status
void displayBoard(const vector<vector<char>> board){
    for(int i = board.size()*5; i > 0; i--)
        cout<<"-";
    cout<<endl;
    for(const vector<char> row : board){
        for(const char column : row){
            cout<<"| "<<column<<" |";
        }
        cout<<endl;
        for(int i = board.size()*5; i > 0; i--)
            cout<<"-";
        cout<<endl;
    }
    cout<<endl;
}

//Check is any bomb placed at user input or not
inline bool checkBomb(const vector<vector<char>>& board, const pair<int,int>& user_input){
    return board[user_input.first][user_input.second] == 'B';
}

//mine Sweeper Game top level
bool mineSweeperGame(int size){
    int i = 0, j = 0;
    int attempt = size*size - size;    int score = 0;
    vector<vector<char>> board(size,vector<char>(size,'.'));
    generateRandomBoard(board); //To Generate Board with Random Placed bomb
    pair<int,int> user;
    while (attempt)
    {
        user = input(size); //For User Input
        if(checkBomb(board, user)){
            displayBoard(board);    //To Display The Board Status
            return false;
        }
        board[user.first][user.second] = 'M';
    }
    return true;
}

//Mine sweeper game top most
void init(){
    int size;
    cout<<"Enter Size of Board : ";
    cin>>size;
    bool res;
    if(size > 1){
        res = mineSweeperGame(size);
    }
    else{
        cout<<"Error : IllegelInputError (Size should be greater than one)"<<endl;
        cout<<"Input Again !!"<<endl;
    }
    res ? cout<<endl<<"You Won" : cout<<endl<<" You Lose ";
}

int main(int argc, char const *argv[])
{
    init();
    return 0;
}
