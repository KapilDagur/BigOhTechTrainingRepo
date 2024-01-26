#include <bits/stdc++.h>
using namespace std;

int mostWaterCover(int array[], int size){
    int first = 0;      
    int last = size-1;  
    int most_water = 0; 
    while (first < last)    //Loop for iteration for find max coverage of area
    {
        most_water = max(most_water,min(array[first],array[last])*(first-last));      //Calculating the area
        if(array[first] > array[last])  //2 Pointer approch find max
            last--;     //if last element lesser than first element
        else
            first++;    //else this condition
    }
    return most_water;  // returning most_water
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,8,6,2,5,4,8,3,7};
    cout<<mostWaterCover(arr,sizeof(arr)/sizeof(int));
    return 0;
}
