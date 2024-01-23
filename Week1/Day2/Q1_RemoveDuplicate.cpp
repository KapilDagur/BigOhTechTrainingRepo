#include<iostream>
#include<vector>
using namespace std;

vector<int> removeDuplicate(vector<int> array){
    vector<int> result;
    int i = 0, j, length = array.size();
    while(i < length){
        j = 0;
        while (j < i)
        {
            if(array[i] == array[j]){
                break;
            }
            j++;
        }
        if(j == i)
            result.push_back(array[i]);
        i++;
    }
    array.clear();
    for(int ele:result)
        array.push_back(ele);
    result.clear();
    return array;
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
