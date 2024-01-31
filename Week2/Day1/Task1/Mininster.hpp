#include <bits/stdc++.h>
using namespace std;

/*
    @author : KAPIL DAGUR
*/

/*
    Security Check for MP class
*/
#ifndef MP_HPP
#include "MP.hpp"
#endif


/*  
    Security Check for Minister class
*/
#ifndef MINISTER_HPP
#define MINISTER_HPP 1
class Minister : public MP{
public:
    Minister(const string& constituency) : MP(constituency){}
    bool isExceedsSpendingLimit() const override{       //Overridden function of base class ie MP class
        return current_spending > 1000000;              //if Minister spend than there limit
    }

};

#endif  //end of header