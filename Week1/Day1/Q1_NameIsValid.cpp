#include<iostream>
#include<map>
using namespace std;

/*
    @author : KAPIL DAGUR
*/


/*
    isContainVowelMoreThanOnce function checks the any particular
    vowel doesn't come more than one..
    @param : string
    @return : bool
*/
bool isContainVowelMoreThanOnce(string name){
    map<char,int> vowel_counter; // creating a map for backup the occurance of vowel
    vowel_counter.insert({'A',0});
    vowel_counter.insert({'E',0});
    vowel_counter.insert({'I',0});
    vowel_counter.insert({'O',0});
    vowel_counter.insert({'U',0});
    vowel_counter.insert({'a',0});
    vowel_counter.insert({'e',0});
    vowel_counter.insert({'i',0});
    vowel_counter.insert({'o',0});
    vowel_counter.insert({'u',0});

    //Counting Occurance of Vowel in Given Name...
    for(int i = 0; i < name.length(); i++){
        //Checking each vowel by index wise...
        if(name[i]=='a' || name[i]=='e' || name[i]=='i' || name[i]=='o' || name[i]=='u' ||
           name[i]=='A' || name[i]=='E' || name[i]=='I' || name[i]=='O' || name[i]=='U'){
                vowel_counter[name[i]]++; //Putting each occurance of vowel into adjecent map
                if(vowel_counter[name[i]] > 1) //If any vowel comes more than once during scanning the return
                    return true; 
           }
    }
    return false;
}

/*
    isContainSBetweenTT function checks the string and if any found return false
    @param : string
    @return : bool
*/
bool isContainSBetweenTT(string name){
    int i = 0,j = name.length()-1;
    //Find S from starting and last if Two S meent the loop terminated
    while(i < j){
        if(name[i] != 's' || name[i] != 'S')
            i++;

        if(name[j] != 's' || name[j] != 'S'){
            j--;
        }
        if((name[i] == 's' || name[i] == 'S') && (name[j] == 's' || name[j] == 'S'))
            break;
    }
    //if we found to S from front to last then this loop work for find T if yes then true else false
    while(i < j){
        if(name[i] == 't' || name[i] == 'T')
            return true;
        i++;
    }
    return false;
}

/*
    isValidName function checks both conditions
    @param : string
    @return : bool
*/
bool isValidName(string name){
    //checking both conditions...
    if(!isContainVowelMoreThanOnce(name) && !isContainSBetweenTT(name)){
        return true;
    }
    return false;
}



int main(int argc, char const *argv[])
{
    cout<<isValidName("heso mat ell");
    return 0;
}

