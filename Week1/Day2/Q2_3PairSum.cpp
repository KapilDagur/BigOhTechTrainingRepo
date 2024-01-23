#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threePairSum(vector<int> array, int target){
    vector<vector<int>> result;
    if(array.size() < 3)
        return result;
    int i = 0, j = array.size()-1, k = 1, length = array.size()-1;
    sort(array.begin(),array.end());
    while(i < length){
        j = i + 1;
        k = length - 1;
        while (j < k)
        {
            int sum = array[i] + array[j] + array[k];
            if(sum == target){
                result.push_back({array[i],array[j],array[k]});
                j++;
                k--;
            }
            else if(sum < target)
                j++;
            else 
                k--;            
        }
        i++;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> array = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> result;
    result = threePairSum(array,sizeof(array)/sizeof(int));
    for(vector<int> pair : result){
        cout<<"[";
        for(int pair_ele : pair){
            cout<<pair_ele<<",";
        }
        cout<<"]";
    }
    return 0;
}
