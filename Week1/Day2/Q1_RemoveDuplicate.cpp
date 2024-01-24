#include<bits/stdc++.h>
using namespace std;
/*
    @author : KAPIL DAGUR
*/


/*
    partition function make partition in array and place the pivot element at there specific position
    @param : array(vector<int>& ), low(int), high(int)
    @return : int
*/
int partition(vector<int>& array, int low, int high){
    int pivot = array[high];    //Pivot element for partitioning
    int i =  low - 1;      
    for(int j = low; j <= high; j++){       //Loop for pivot element positition 
        if(array[j] < pivot){
            i++;
            swap(array[i],array[j]);        //Swapping if found any smaller element from pivot bcz
        }                                   //before pivot all element are 
    }
    swap(array[i+1],array[high]);
    return i+1;
}

/*
    quickSort function implements the algorithm of sort in efficent manner
    space complexity : O(1)
    time complexity : O(n*log(n))
    @param : array(vector<int>& ), low(int), high(int)
    @return : void
*/
void quickSort(vector<int>& array, int low, int high){
    if(low < high){
        int mid = partition(array,low,high);// stores the pivot element position(or we can say tha partitioning position)

        //Recurrsive call
        quickSort(array,low,mid-1);     // Recurrsive call for before pivot element 
        quickSort(array,mid+1,high);    // Recurrsive call for after pivot element 
    }
}

/*
    removeDuplicate function removes duplicate element from array(vector)
    @param : array (vector<int>&)
    @return : void
*/
void removeDuplicate(vector<int>& array){
    if(array.size() == 0 || array.size() == 1)
        return;
    int i = 1;
    quickSort(array,0,array.size());        //Sorting array
    while(i < array.size()){        //Loop for iterate each element
        if(array[i-1] == array[i]){
            array.erase(array.begin() + i);     //Erasing duplicate element if exist
            i = i - 1;      //Setting position for prev element bcz we remove next element
        }
        i++;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 4, 6, 2, 8, 10, 4, 12, 14, 6};
    for(int ele : arr)
        cout<<ele<<", ";
    cout<<endl;
    removeDuplicate(arr);
    for(int ele : arr)
        cout<<ele<<", ";
    return 0;
}
