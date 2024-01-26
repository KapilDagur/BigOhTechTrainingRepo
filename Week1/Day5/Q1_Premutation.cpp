// C++ program to print all interleavings of given two strings 
#include <bits/stdc++.h>
using namespace std;

vector<string> permutations; //Global variable for store permutations 

/*
    generate permuation recurssively
*/
void permutationRecurssive(char str1[], int str1_i, char str2[], int str2_i, char perm[], int index){ 
    //Base condition means 
    if (str1_i == 0 && str2_i == 0) 
        return  permutations.push_back(string(perm));   //Appending pemutation into vector(array of string)

    if (str1_i > 0) //Checking is string1 is not ended
    {
        perm[index] = str1[0]; //putting the first elemenet of string 1 into perm 
        permutationRecurssive(str1 + 1, str1_i -1 ,str2, str2_i , perm, index + 1); //Recurssive call 
    } 
    if (str2_i > 0) //Checking is string2 is not ended
    { 
        perm[index] = str2[0]; //putting the first element of string 2 into perm
        permutationRecurssive(str1, str1_i, str2+1, str2_i-1, perm, index+1); //Recurssive call
    } 
} 

/*
    getPermutations of given problems
*/
void getPermuatations(char str1[], char str2[], int m, int n) 
{
    char *perm= new char[((m + n + 1)*sizeof(char))]; // Allocating dynamic object(memory) for sharing
    perm[m + n] = '\0';  //Setting null terminator
    permutationRecurssive(str1, m, str2, n, perm, 0);   //Calling permutation Recursive function     
    free(perm); //Deallcoating memory
}

void test(){
    //Test 1
    char str1[] = "AB"; 
    char str2[] = "CD"; 
    getPermuatations(str1, str2, strlen(str1), strlen(str2)); 
    cout<<"Test 1 : ";
    for(string item : permutations)
        cout<<item<<" ";
    cout<<endl;
    permutations.clear();

    //Test 2 
    char str3[] = "AB";
    char str4[] = "C";
    getPermuatations(str3, str4, strlen(str3), strlen(str4)); 
    cout<<"Test 2 : ";
    for(string item : permutations)
        cout<<item<<" ";
    cout<<endl;
}

int main() 
{
    //Calling Test Func.
    test();
    return 0; 
}