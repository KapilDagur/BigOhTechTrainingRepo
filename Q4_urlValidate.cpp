#include<iostream>
#include<regex>
using namespace std;


// C++ program to validate URL
// using Regular Expression
#include <iostream>
#include <regex>
using namespace std;

/*
    isValidURL function implements the logic of URL Pattern validation
    in this we use regex expression for compair the url entered init.
    @param : url(string)
    @return : bool
*/ 
bool isValidURL(string url)
{
 
    // Regex Pattern for validate a URL...
    const regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
    
    //Base case if url is empty...
    if (url.empty())
    {
        return false;
    }
    
    //Pattern parsed and match if yes than true else false
    if(regex_match(url, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main(int argc, char const *argv[])
{
    cout<<isValidURL("https://www.bigohtech.com/")<<endl;
    cout<<isValidURL("https:// www.bigohtech.com/")<<endl;
    return 0;
}
