#include <bits/stdc++.h>
using namespace std;

/*
    Security Check for PM Class non-repeatation
*/
#ifndef PM_HPP
#include "PM.hpp"
#endif

//Commissioner Class
class Commissioner{
public:
    void canArrest(const MP& mp){           //Polymorphism(for mp is currepted or not)
        if(mp.isExceedsSpendingLimit()){    //If mp exceed spend limit of 100000
            cout<<"MP member exceed spending limit Arrested, Constituency : "<<mp.getConstituency()<<endl;
        }
        else{
            cout<<"MP is Not Arrested "<<endl;
        }
    }

    void canArrest(const Minister& minister, const PM& pm){     //Polymorphism(for mininster is currepted or not)
        if(minister.isExceedsSpendingLimit() && pm.getPermission()){    //If yes we need PM Permission to arrest
            cout<<"Mininster exceed spending limit Arrested with PM permission, Constituency : "<<minister.getConstituency()<<endl;
        }
        else{
            cout<<"Minister is Not Arrested"<<endl;
        }
    }

};