#include<bits/stdc++.h>
using namespace std;

/*
    findMax inline function return the max between start to end(possition) in input array 
*/
inline int findMax(const vector<int>& input, int start, int end){
    int max = input[start]; //setting first element
    for(int i = start+1; i < end; i++){     //Iteration for find max via compair pervious one
        if(max < input[i]){     //compairsion b/w previous and current indexed element
            max = input[i];     //If condition true setting new max in place of prev max
        }
    }
    return max; //Returning max
}

/*
    maxOfKthSliderWindow func. return the max of Kth size window 
    here we use slider window algorithm
*/
vector<int> maxOfKthSliderWindow(vector<int> input, int k){
    if(input.size() < k)    //Base case
        return {};
    int j = k, size = input.size();
    vector<int> output;
    while(j <= size){   //Sliding window as slider window alog
        output.push_back(findMax(input, j-k, j));   //Appending maximum element into vector
        j++;
    }
    return output;  //returning output
}

/*
    Test Case
*/
void test(){
    //Test 1
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int K = 3;
    vector<int> output = maxOfKthSliderWindow(arr, K);
    cout<<"Test 1 : ";
    for(int item : output)
        cout<<item<<" ";
    cout<<endl;

    cout<<"Test 2 : ";
    arr = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    K = 4;
    output = maxOfKthSliderWindow(arr, K);
    for(int item : output)
        cout<<item<<" ";
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}