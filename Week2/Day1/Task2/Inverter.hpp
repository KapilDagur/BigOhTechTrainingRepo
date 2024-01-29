#include<bits/stdc++.h>
using namespace std;


/*
    Security Check for non repeatation
*/
#ifndef INVERTER_HPP
#define INVERTER_HPP 1


/*
    Super Class for all kind or invertor
*/
class Inverter{
    //Data Member
    protected:
        double current; //To store current
        double voltage;   //To store voltage
        double power;    //To store power
    
    public:
        /*
            Abstract class Inverter Constructor for init
            @param : current(double), voltage(double)
            @return : void
        */
        Inverter(double current, double voltage){
            this->current = current;
            this->voltage = voltage;
            this->power = current * voltage;
        }

        /*
            getPowerRating method returns the rating of Inverter
            @param : void
            @return : double
        */
        double getPowerRating() const{
            return this->power;
        }
        /*
            Virtual fucntion for drived class to override it
            @param : void
            @return : string
        */
        virtual string getInverterType() const {
            return "Generic Invertor";
        }
};

#endif