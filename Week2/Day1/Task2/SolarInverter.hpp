#include<bits/stdc++.h>
using namespace std;

/*
    Security Check for non repeatation
*/
#ifndef INVERTER_HPP
#include "Inverter.hpp"
#endif
#ifndef SOLAR_INVERTER_HPP
#define SOLAR_INVERTER_HPP 1

/*
    Parent Class : SolarInverter (Solar Inverter class is abstract base class)
    Child Class  : Regalia (Regalia Inverter inherites properties of Solar Inverter & overrides inverter type also)
*/
class SolarInverter : public Inverter{
    //Visiablity Mode
    protected:
        bool has_battery;   //For batter options
        bool grid_on;   //For Grid Options
    
    public:
        /*
            SolarInverter Constructure for init.
            @param : current(double), voltage(double), battery(bool), grid(bool)
            @return : void(None)
        */
        SolarInverter(double current, double voltage, bool battery, bool grid) : Inverter(current,voltage){
            this->has_battery = battery;    //setting battery value(true/false)
            this->grid_on = grid;   //setting grid value (true/false)
        }

        /*
            getInverterType is overridden method of Inverter Base class
            @param : void
            @return : string
        */
        string getInverterType() const override{
            return "Solar Inverter";    //Type/Cataogry of Inverter 
        }

        /*
            hasBattery method return the value of battery option i.e (Battery supported or not)
            @param : void
            @return : bool
        */
        bool hasBattery() const {
            return this->has_battery;
        }

        /*
            isGridOn method return the value of grid option i.e (grid on or not)
            @param : void
            @return : bool
        */
        bool isGridOn() const {
            return this->grid_on;
        }
};
#endif