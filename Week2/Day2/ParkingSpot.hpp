#include <bits/stdc++.h>
using namespace std;

#ifndef PARKINGSPOT_HPP
#define PARKINGSPOT_HPP 1

enum SpotType{
    COMPACE,
    LARGE,
    HANDICAPPED,
    MOTARCYCLE,
    ELECTRIC
};

class ParkingSpot
{
private:
    int spot_number;    //To store the spot number
    SpotType type;      //To store the spot type
    bool occupied;      //Flag for occupy or free spot status
public:
    ParkingSpot(int spot_number, SpotType type); //Declaration of Parameterized Constructor
    int getSpotNumber() const;              //Function declaration for get spot number 
    SpotType getSpotType() const;           //Function declaration for get spot type
    bool isOccupied() const;                //Function declaration for get occupy status 
    void occupySpot();                      //Function declaration for occupy spot
    void freeSpot();                        //Function declaration for free spot

};

//Defination of Parameterized Constructor
ParkingSpot::ParkingSpot(int spot_number, SpotType type)
{
    this->spot_number = spot_number;
    this->type = type;
    occupied = false;
}

//Defination of getSpotNumber for get number for spot
int ParkingSpot::getSpotNumber() const{
    return this->spot_number;
}

//Defination of getSpotType for get type of spot
SpotType ParkingSpot::getSpotType() const{
    return this->type;
}

//Defination of isOccupied for get status of occupy spot
bool ParkingSpot::isOccupied() const{
    return this->occupied;
}

//Definataion of occupySpot for occupy spot in Parking
void ParkingSpot::occupySpot(){
    this->occupied = true;
}

//Defination of 
void ParkingSpot::freeSpot(){
    this->occupied = false;
}

#endif