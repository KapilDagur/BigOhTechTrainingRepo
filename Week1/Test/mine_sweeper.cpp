#include<bits/stdc++.h>
using namespace std;
/*
    KAPIL DAGUR
*/

// time();

//For User Input Validation
inline bool isValidInputByUser(pair<int,int>& input, int size){
    int temp;
    if(input.first > size){
        cout<<"Row is higher than Size";
        cout<<"Re input Row : ";
        cin>>temp;
        input.first = temp;
        isValidInputByUser(input,size);
    }
    if(input.second > size){
        cout<<"Column is higher than Size";
        cout<<"Re input Column : ";
        cin>>temp;
        input.second = temp;
        isValidInputByUser(input,size);
    }
    return input.first < size
         && input.first > 0 
         && input.second < size 
         && input.second > 0;
}

//For User Input
pair<int,int> userInput(){
    int row, col;
    cout<<"Enter Row Number : ";
    cin>>row;
    cout<<"Enter Column Number : ";
    cin>>col;
    cout<<endl;
    return {row-1,col-1};
}

//For input functioning
pair<int,int> input(int size){
    pair<int,int> user_term = userInput();
    while(!isValidInputByUser(user_term,size)){
        user_term = userInput();
    };
    return user_term;
}

//For get a random position for place bomb
inline pair<int,int> randomPosition(int size){
    return {time(NULL) % size, time(NULL) % size};  //To generate random pair with cordinates
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
    int max_attempt = size*size - size;
    int attempt = 0;
    vector<vector<char>> board(size,vector<char>(size,'.'));
    cout<<"Wait Board is creating"<<endl;
    generateRandomBoard(board); //To Generate Board with Random Placed bomb
    pair<int,int> user;
    cout<<endl<<"Hey Board is created "<<endl;
    cout<<endl<<"Enter Your Attempt : ";
    cin>>attempt;
    while (attempt > 0 && attempt < max_attempt)
    {
        attempt--;
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
    while(true){
        if(size > 1){
            res = mineSweeperGame(size);
            break;
        }
        else{
            cout<<"Error : IllegelInputError (Size should be greater than one)"<<endl;
            cout<<"Input Again !!"<<endl;
        }
    }
    res ? cout<<endl<<"You Won" : cout<<endl<<" You Lose ";
}

int main(int argc, char const *argv[])
{
    init();
    return 0;
}
