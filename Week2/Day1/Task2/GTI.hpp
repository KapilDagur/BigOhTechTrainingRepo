#include <bits/stdc++.h>
using namespace std;

/*
    Security Check for non repeatation
*/
#ifndef SOLAR_INVERTER_HPP
#include "SolarInverter.hpp"
#endif


/*
    Parent Class : SolarInverter (Solar Inverter class is abstract base class)
    Child Class  : GTI (GTI Inverter inherites properties of Solar Inverter & overrides inverter type also)
*/
class GTI : public SolarInverter{
    public:
        /*
            GTI Constructor for init
            @param : current(double), voltage(double)
            @return : void
        */
        GTI(double current, double voltage) : SolarInverter(current, voltage, false, true){}

        /*
            getInverterType is overridden method of Inverter Base class
            @param : void
            @return : string
        */
        string getInverterType() const override{
            return "GTI Solar Inverter";
        }
};