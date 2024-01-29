#include <bits/stdc++.h>
using namespace std;

/*
    Security Check
*/
#ifndef SOLAR_INVERTER_HPP
#include "SolarInverter.hpp"
#endif

/*
    Parent Class : SolarInverter (Solar Inverter class is abstract base class)
    Child Class  : Regalia (Regalia Inverter inherites properties of Solar Inverter & overrides inverter type also)
*/
class Regalia : public SolarInverter{
    public:
        /*
            Regalia Constructor
            @param : current(double), volatge(double)
            @return : void
        */
        Regalia(double current, double voltage) : SolarInverter(current, voltage, false, false){}

        /*
            getInverterType is overridden method of Inverter Base class
            @param : void
            @return : string
        */
        string getInverterType() const override{
            return "Regalia Solar Inverter";
        }
};