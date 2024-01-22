#include<iostream>
using namespace std;

/*
    @author : KAPIL DAGUR
*/

/*
    primeDigitNumber Function implements the logic of
    prime digit in a number if number contains any non-prime digit returns false
    @param : num(int)
    @return : bool
*/
bool primeDigitNumber(int num){
    int PrimeDigit[10]={0,0,1,1,0,1,0,1,0,0};
    while (num != 0)
    {
        if(!PrimeDigit[num % 10])
            return false;
        num /= 10;
    }
    return true;
}

/*
    largestDigitPrime Function is used to find out largest prime digit number but
    smaller than input number

    @param : number(int)
    @return : int
*/
int largestDigitPrime(int number){
    while (number > 0)
    {
        if(primeDigitNumber(number))
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
