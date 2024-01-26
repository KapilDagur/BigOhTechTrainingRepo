#include<bits/stdc++.h>
using namespace std;

/*
    findMedianSortedArrays func. find the median two sorted array
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();   //Variables for storing lenth of both vector(array)
        int i = 0, j = 0, start = 0;    //required Variable for program (iteratation var ect.)
        vector<int> mergedArray(n1+n2); 
        while(i < n1 && j < n2){    //Merging sorted array 
            if(nums1[i] < nums2[j]){
                mergedArray[start++] = nums1[i++];
            }
            else{
                mergedArray[start++] = nums2[j++];
            }
        }

        //For those element whose left in array 1(num1) 
        while(i < n1){
            mergedArray[start++] = nums1[i++];
        }

        //For those element whose left in array 2(num2)
        while(j < n2){
            mergedArray[start++] = nums2[j++];
        }

        int m = mergedArray.size();
        int mid = 0 + (m-1)/2;
        if(m % 2 != 0){
            return mergedArray[mid];
        }

        return (double)(mergedArray[mid] + mergedArray[mid+1])/2;
    }
int main(int argc, char const *argv[])
{
    vector<int> arr1 = {1,3,5,7,9};
    vector<int> arr2 = {2,4,6,8,10};


    cout<<findMedianSortedArrays(arr1,arr2);
    return 0;
}
