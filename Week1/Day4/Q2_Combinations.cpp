#include<bits/stdc++.h>
using namespace std;
/*
    recursiveCombination find all combination as per target
*/
void recursiveCombination(vector<string>& output,
                          string str, string target, 
                          map<string,vector<char>> input, 
                          int idx){
    if(idx == target.size()){   //base condition
        return output.push_back(str);   //Returning the output
    }

    string sub_str(1, target[idx]);
    auto itr = input.find(sub_str);     //iterator for find a valid pair 
    if(itr != input.end()){
        vector<char> alphabets = itr->second;   //getting value of pair
        for(char alpha : alphabets){    //binding each alphabets with str..
            recursiveCombination(output, str+alpha, target, input, idx+1); //Recursive call for next alphabet
        } 
    }
}

void possibleStrings(map<string,vector<char>> input, vector<string>& output, string target){
    recursiveCombination(output, "", target, input, 0);
}


int main(int argc, char const *argv[])
{
    //Input map
    map<string,vector<char>> input = {
        {"1", { 'Z','Y','A' }},
        {"2", { 'B', 'O'}},
        {"23", {'L'}},
        {"3", {'U','P'}},
    };
    //output vector for store result.
    vector<string> output;
    string target = "123";  //target string
    possibleStrings(input,output,target);   //Calling for generate all ways
    for(string str:output)
        cout<<str<<" ";
    return 0;
}
