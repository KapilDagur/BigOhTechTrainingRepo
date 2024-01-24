#include<iostream>
using namespace std;

/*
    @author : KAPIL DAGUR
*/

/*
    printPattern function prints the pattern as per given problem statement
    @param : number(int)
    @return : void

*/
void printPattern(int number){
    for(int i = 0; i < number; i++){
        for(int j = 0; j < number; j++){
            if(i == j)  //Condition for print '\'  
                cout<<"\\";
            else if(i == number - j - 1)    //Condition for print '/' 
                cout<<"/";
            else        //print * for else condition
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
