#include <bits/stdc++.h>
using namespace std;

/*
    Security Check for non repeatation
*/
#ifndef INVERTER_HPP
#include "Inverter.hpp"
#endif
/*
    Parent Class : Inverter (Inverter class is abstract base class)
    Child Class  : Zelio (Zelo Inverter inherites properties of Inverter & overrides inverter type also)
*/
class Zelio : public Inverter{
    public:
        /*
            Zelio Constructor for init obj.
            @param : current(double), voltage(double)
            @return : void(None)
        */
        Zelio(double current, double voltage) : Inverter(current, voltage) {}
        
        /*
            getInverterType is overridden method of Inverter Base class
            @param : void
            @return : string
        */
        string getInverterType() const override {
            return "Zelio Inverter";    //Return Type of Inverter
        }
};