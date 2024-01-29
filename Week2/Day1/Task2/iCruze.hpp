#include <bits/stdc++.h>
using namespace std;

/*
    Security Check for non repeatation
*/
#ifndef INVERTER_HPP
#include "Inverter.hpp"
#endif
/*
    Parent Class : Inverter
    Child Calss  : iCruze 
*/
class iCruze : public Inverter{
    public:
        /*
            iCruze Constructor for init
            @param : current(double), voltage(double)
            @return : void
        */
        iCruze(double current, double voltage) : Inverter(current, voltage) {}
        
        /*
            getInverterType is overridden method of Inverter Base class
            @param : void
            @return : string
        */
        string getInverterType() const override{
            return "iCruze Inveter";
        }
};