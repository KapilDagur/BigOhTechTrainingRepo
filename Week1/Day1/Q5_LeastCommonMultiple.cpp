#include<iostream>
using namespace std;
/*
    Laast Common Multiple implementation
    @author : KAPIL DAGUR

*/

/*
    gcd is a recursive Function implements the G.C.D logic
    for two number
    @param int 
    @return int
*/
int gcd(int num1, int num2){
    if(num2 == 0)
        return num1;
    return gcd(num2,num1%num2);
}

/*
    least Common Multiple Function implement the L.C.M logic
    for Nth natural number sequencally...
    @param : int
    @return : int
*/
int leastCommonMultiple(int num){
    num++;
    int lcm = 2;
    for(int i = 3; i < num; i++){
        lcm = lcm * i / gcd(lcm,i);
    }
    return lcm;   
}



int main(int argc, char const *argv[])
{
    cout<<leastCommonMultiple(4)<<endl;
    return 0;
}
