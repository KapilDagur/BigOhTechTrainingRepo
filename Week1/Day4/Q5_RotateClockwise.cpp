#include<iostream>
#include<vector>
using namespace std;

/*
    rotateClockwise90Degree func. implement the logic of 90 degree rotation of array
    @param : array(vector<vector<int>>&)
    @return : void
*/
void rotateClockwise90Degree(vector<vector<int>>& array){
    int size = array.size(), temp;  //size of array(n x n matrix)
    for(int i = 0; i < size/2; i++){    //Iteration 1/2 of array for rotate
        for(int j = 0; j < size-i-1; j++){  //Iteration for column for swap each relevant position element
            temp = array[i][j]; //storing first element (0,0) cordianate 
            array[i][j] = array[size-1-j][i];   //Putting value of Cordinate (N,0) in (0,0)
            array[size-1-j][i] = array[size-1-i][size-1-j];     //Putting value of Cordinate (N,N) in (N,0)
            array[size-1-i][size-1-j] = array[j][size-1-i];     //Putting value of Cordinate (N,0) in (N,N)
            array[j][size-1-i] = temp;      //Putting Value of Cordinate (0,0) in (N,0) 
        }
    }
}

/*
    printMatrix func. perform print operation for Matrix
    @param : array(vector<vector<int>>&)
    @return : void
*/
void printMatrix(vector<vector<int>>& array){
    int size = array.size();
    for(int i = 0; i < size; i++){  //Row Traverse iterator
        for(int j = 0; j < size; j++)   //Column Traverse iterator
            cout<<array[i][j]<<" ";
        cout<<endl;
    }
}

/*
    Test Cases for Program
*/
void test(){
    //Test 1
    vector<vector<int>> arr1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout<<"Test 1 :"<<endl;
    rotateClockwise90Degree(arr1);
    printMatrix(arr1);

    //Test 2
    vector<vector<int>> arr2 = {
        {1,2},
        {3,4}
    };
    cout<<"Test 2 :"<<endl;
    rotateClockwise90Degree(arr2);
    printMatrix(arr2);
}
int main(int argc, char const *argv[])
{
    test();
    return 0;
}