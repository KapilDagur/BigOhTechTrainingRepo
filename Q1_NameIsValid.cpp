#include<iostream>
#include<map>
using namespace std;


bool isContainVowelMoreThanOnce(string);

bool isContainSBetweenTT(string name){
    int i = 0,j = name.length()-1;
    while(i < j){
        if(name[i] != 's' || name[i] != 'S'){
            i++;
        }
        if(name[j] != 's' || name[j] != 'S'){
            j--;
        }
        if((name[i] == 's' || name[i] == 'S') && (name[j] == 's' || name[j] == 'S'))
            break;
    }
    if(i < j){
        for(; i < j; i++){
            if(name[i] == 't' || name[i] == 'T')
                return true;
        }
    }
    return false;
}

bool isValidName(string name){
    if(isContainVowelMoreThanOnce(name) || isContainSBetweenTT(name)){
        return true;
    }
    return false;
}

bool isContainVowelMoreThanOnce(string name){
    map<char,int> vowel_counter;
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
        if(name[i]=='a' || name[i]=='e' || name[i]=='i' || name[i]=='o' || name[i]=='u' ||
           name[i]=='A' || name[i]=='E' || name[i]=='I' || name[i]=='O' || name[i]=='U'){
                vowel_counter[name[i]]++;
                if(vowel_counter[name[i]] > 1)
                    return true;
           }
    }
    return false;
}


int main(int argc, char const *argv[])
{
    cout<<isValidName("heso mat ll");
    return 0;
}

