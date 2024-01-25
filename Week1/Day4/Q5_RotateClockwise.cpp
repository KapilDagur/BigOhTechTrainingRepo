#include<iostream>
#include<vector>
using namespace std;

void rotateClockwise90Degree(vector<vector<int>>& array){
    int size = array.size(), temp;
    for(int i = 0; i < size/2; i++){
        for(int j = 0; j < size-i-1; j++){
            temp = array[i][j];
            array[i][j] = array[size-1-j][i];
            array[size-1-j][i] = array[size-1-i][size-1-j];
            array[size-1-i][size-1-j] = array[j][size-1-i];
            array[j][size-1-i] = temp;
        }
    }
}


void printMatrix(vector<vector<int>>& array){
    int size = array.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            cout<<array[i][j]<<" ";
        cout<<endl;
    }
}

void test(){
    vector<vector<int>> arr1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout<<"Test 1 :"<<endl;
    rotateClockwise90Degree(arr1);
    printMatrix(arr1);

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