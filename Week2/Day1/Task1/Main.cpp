#include <bits/stdc++.h>
using namespace std;

#include "MP.hpp"               //Header for MP Class
#include "Mininster.hpp"        //Header for Minister Class
#include "PM.hpp"               //Header for PM Class
#include "Commissioner.hpp"     //Header for Commissioner
/*
    Test Cases of Depict Indian Politics
*/
void test(){
    MP mp1("Constituency 1");               //model 1
    MP mp2("Constituency 2");               //model 2
    Minister minister1("Constituency 3");   //model 3
    Minister minister2("Constituency 4");   //model 4
    PM pm("Constituency 5");                //model 5
    Commissioner commissioner;              //model 6

    mp1.spendMoney(150000);
    commissioner.canArrest(mp1);            //Test 1
    mp2.spendMoney(90000);          
    commissioner.canArrest(mp2);            //Test 2
    minister1.spendMoney(900000);
    commissioner.canArrest(minister1,pm);   //Test 3
    minister2.spendMoney(1400000);         
    commissioner.canArrest(minister2,pm);   //Test 4
}

int main(int argc, char const *argv[])
{
    test();     //test
    return 0;
}
