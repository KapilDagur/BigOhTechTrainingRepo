#include<iostream>
#include<vector>
using namespace std;

/*
    @author : KAPIL DAGUR
*/
/*
    @param : array(vector<vector<int>>
*/

void printSpiralClockWise(vector<vector<int>> array){
    int size = array.size();
    for(int i = 0; i < size/2; i++){
        //Vertical Print Iterator(from left to right)
        for(int j = i; j < size-1-i; j++){
            cout<<array[i][j]<<" ";
        }

        //Horizontal Print Iterator(from up to down)
        for(int j = i; j < size-1-i; j++){
            cout<<array[j][size-i-1]<<" ";
        }

        //Vertical Print Iterator(from right to left)
        for(int j = size-i-1; j > i; j--){
            cout<<array[size-i-1][j]<<" ";
        }

        //Horizontal Print Iterator(from down to up)
        for(int j = size-i-1; j >i; j--){
            cout<<array[j][i]<<" ";
        }
    }
    if(array.size()%2 != 0)     //For odd matrix exceptional case bcz loop doesn't reach the centre
        cout<<array[array.size()/2][array.size()/2];

    cout<<endl;
}

void printSpiralAntiClockWise(vector<vector<int>> array){
    int size = array.size();
    for(int i = 0; i < size/2; i++){
        //
        for(int j = size-1-i; j > i; j--){
            cout<<array[i][j]<<" ";
        }
        for(int j = i; j < size-i-1; j++){
            cout<<array[j][i]<<" ";
        }
        for(int j = i; j < size-i-1; j++){
            cout<<array[size-i-1][j]<<" ";
        }
        for(int j = size-i-1; j > i; j--){
            cout<<array[j][size-i-1]<<" ";
        }
    }
    if(array.size()%2 != 0)     //For odd matrix exceptional case bcz loop doesn't reach the centre
        cout<<array[array.size()/2][array.size()/2];

    cout<<endl;
}

/*
    Test Cases for spiral pattern(clockwise & anticlockwise both)
*/

void test(){
    vector<vector<int>> arr = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    cout<<"Test 1 : "<<endl;
    cout<<"Clockwise : ";
    printSpiralClockWise(arr);
    cout<<"AntiClockwise :";
    printSpiralAntiClockWise(arr);
    
    vector<vector<int>> arr1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout<<"Test 2 : "<<endl;
    cout<<"Clockwise : ";
    printSpiralClockWise(arr1);
    cout<<"AntiClockwise : ";
    printSpiralAntiClockWise(arr1);
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
