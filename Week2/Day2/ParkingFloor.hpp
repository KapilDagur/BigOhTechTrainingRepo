#include <bits/stdc++.h>
using namespace std;
/*
    Security Check for ParkingSpot class Non-repeatation
*/
#ifndef PARKINGSPOT_HPP
#include "ParkingSpot.hpp"
#endif

/*
    Security Check for ParkingFloor class Non-repeatation
*/
#ifndef PARKINGFLOOR_HPP
#define PARKINGFLOOR_HPP 1

class ParkingFloor{
private:
    int floor_number;
    vector<ParkingSpot> parking_spot;
public:
    /*ParkingFloor Class Constructor for init*/
    ParkingFloor(int floor_number, int spot_capacity);
    int getFloorNumber() const;     //To get number of floor
    const vector<ParkingSpot>& getSpots() const;    //To get Parking spots


};

//Defination of ParkingFloor Constructor
ParkingFloor::ParkingFloor(int floor_number, int spot_capacity){
    this->floor_number = floor_number;      //setting floor number
    parking_spot.reserve(spot_capacity);    //reserving fixed amout of size for parking spot
    for(int i = 0; i < floor_number; i++){
        SpotType type = static_cast<SpotType>(i % 5);   //Cycle for parking spot
        parking_spot.emplace_back(i, type);
    }
}

//Defination of getFloorNumber of parking building
int ParkingFloor::getFloorNumber() const{
    return this->floor_number;
}

//Defination of getSpots of parking spot in particular floor
const vector<ParkingSpot>& ParkingFloor::getSpots() const{
    return this->parking_spot;
}

#endif  //End of ParkingFloor header