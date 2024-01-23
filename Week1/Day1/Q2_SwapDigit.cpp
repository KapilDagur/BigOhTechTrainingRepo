#include<iostream>
using namespace std;
/*
    @author : KAPIL DAGUR
*/


/*
    swapDigit function implements the logic of swapping first and last
    digit of input number
    @param : int
    @return : void
*/
void swapDigit(int& num){
    int mul = 1, temp = 0, last = num % 10;
    num /= 10;// remove last digit from number
    while (num >= 10) //for make number stable till reach end digit
    {
        temp = (num % 10)*mul + temp;
        num /= 10;
        mul *= 10;
    }
    temp += last*mul; //appending last digit as first digit
    num += temp*10; //appending first digit as last digit
}

int main(int argc, char const *argv[])
{
    int x = 984857832;
    swapDigit(x);
    cout<<x<<endl;
    return 0;
}

