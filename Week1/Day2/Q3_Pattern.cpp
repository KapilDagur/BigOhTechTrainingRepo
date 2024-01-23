#include<iostream>
using namespace std;

void printPattern(int number){
    for(int i = 0; i < number; i++){
        for(int j = 0; j < number; j++){
            if(i == j)
                cout<<"\\";
            else if(i == number - j - 1)
                cout<<"/";
            else
                cout<<"*";
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    printPattern(10);
    return 0;
}
