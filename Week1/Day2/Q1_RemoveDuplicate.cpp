#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& array, int low, int high){
    int pivot = array[high];    //Pivot element for partitioning
    int i =  low - 1;      
    for(int j = low; j <= high; j++){       //Loop for pivot element positition 
        if(array[j] < pivot){
            i++;
            swap(array[i],array[j]);        //
        }
    }
    swap(array[i+1],array[high]);
    return i+1;
}

void quickSort(vector<int>& array, int low, int high){
    if(low < high){
        int mid = partition(array,low,high);
        quickSort(array,low,mid-1);
        quickSort(array,mid+1,high);
    }
}

void sortArray(vector<int>& array){
    
}

void removeDuplicate(vector<int>& array){
    
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 4, 6, 2, 8, 10, 4, 12, 14, 6};
    for(int ele : arr)
        cout<<ele<<", ";
    cout<<endl;
    arr = removeDuplicate(arr);
    for(int ele : arr)
        cout<<ele<<", ";
    return 0;
}
