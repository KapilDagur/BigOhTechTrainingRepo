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
    num /= 10;
    while (num >= 10)
    {
        temp = (num % 10)*mul + temp;
        num /= 10;
        mul *= 10;
    }
    temp += last*mul;
    num += temp*10;
}

int main(int argc, char const *argv[])
{
    int x = 984857832;
    swapDigit(x);
    cout<<x<<endl;
    return 0;
}

