#include <bits/stdc++.h>
using namespace std;

#ifndef MINISTER_HPP
#include "Mininster.hpp"
#endif

#ifndef PM_HPP
#define PM_HPP

class PM : public Minister{
public:

    PM(const string& constituency) : Minister(constituency){
        this->vehicle = "Aircraft";
    };

    bool isExceedsSpendingLimit() const override{
        return this->current_spending > 10000000;
    }

    bool getPermission() const{
        return true;
    }

};

#endif