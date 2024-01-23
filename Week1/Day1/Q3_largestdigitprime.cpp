#include<iostream>
using namespace std;

/*
    Largest Digit prime form them (excluded itself)
    @author : KAPIL DAGUR
*/

/*
    primeDigitNumber Function implements the logic of
    prime digit in a number if number contains any non-prime digit returns false
    @param : num(int)
    @return : bool
*/
bool primeDigitNumber(int num){
    const int PRIMEDIGIT[10]={0,0,1,1,0,1,0,1,0,0}; //defining each prime digit
    while (num != 0)//Loop : for check each digit of number
    {
        if(!PRIMEDIGIT[num % 10])//if any non prime digit got loop terminated..
            return false;
        num /= 10;
    }
    return true; //if no any non prime digit found then return true
}

/*
    largestDigitPrime Function is used to find out largest prime digit number but
    smaller than input number

    @param : number(int)
    @return : int
*/
int largestDigitPrime(int number){
    //As per condition we have to found smaller number from last which is prime exclude itself
    while (number > 0)//checking each number
    {
        if(primeDigitNumber(number))//checking each number digits...
            return number;
        number--;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    cout<<largestDigitPrime(99)<<endl;
    return 0;
}
