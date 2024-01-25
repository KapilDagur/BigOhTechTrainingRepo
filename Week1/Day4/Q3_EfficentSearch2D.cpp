#include<bits/stdc++.h>
using namespace std;

/*
    @author : KAPIL DAGUR
*/

/*
    seaching in 2D array(matrix) which is sorted from left to right
    @param : array(vector<vector<int>>& ), target(int)
    @return : pair<int,int> (i.e cordinate of target in matrix)
*/
pair<int,int> search(vector<vector<int>>& array, int target){
    int low = 0,high = array.size()-1;
    
    //Base case of problem...
    if(target < array[0][0] || target > array[array.size()-1][array.size()-1])
        return {-1,-1};

    //Iterating each row & column wise as per condition meet...
    while (low < array.size() || high > 0){
        if(array[low][high] == target){     //for check row & column hit the target value in array
            return {low+1, high+1};
        }
        else if(array[low][high] < target)      //if row value is lesser than target increase to next
            low++;
        else        //if row value is greater than target decresing column for meetup
            high--;
    }
    return {-1,-1};
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25},
    };

    pair<int,int> output = search(arr,8);
    cout<<output.first<<", "<<output.second<<endl;

    return 0;
}
