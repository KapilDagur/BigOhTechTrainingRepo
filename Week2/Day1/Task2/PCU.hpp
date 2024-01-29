#include<bits/stdc++.h>
using namespace std;

/*
    Security Check for non repeatation
*/
#ifndef SOLAR_INVERTER_HPP
#include "SolarInverter.hpp"
#endif

/*
    Parent Class : SolarInverter (Solar Inverter class is abstract base class)
    Child Class  : PCU (PCU Inverter inherites properties of Solar Inverter & overrides inverter type also)
*/
class PCU : public SolarInverter{
    //Visiablity Mode
    public:
        /*
            PCU Constructor
            @param : current(double), voltage(double)
            @return : void
        */
        PCU(double current, double voltage) : SolarInverter(current, voltage, true, false){}

        /*
            getInverterType is overridden method of Inverter Base class
            @param : void
            @return : string
        */
        string getInverterType() const override{
            return "PCU Solar Inverter";
        }
};