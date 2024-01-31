#include <bits/stdc++.h>
using namespace std;

/*
    Security Check for ParkingFloor class Non-repeatation
*/
#ifndef PARKINGFLOOR_HPP
#include "ParkingFloor.hpp"
#endif


/*
    Security Check for ParkingLot class Non-repeatation
*/
#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP 1

/*
    Parking Lot Class
*/
class ParkingLot{
private:
    vector<ParkingFloor> parking_floors;    //Array for store Parking Floor
    int max_capacity;                       //Maximum capacity of parking in parking lot

public:
    //ParkingLot Construtor for initilization
    ParkingLot(int number_of_floors, int capacity_per_floor);
    int getMaxCapacity() const;                                 //Getter for max capacity
    const vector<ParkingFloor>& getFloors() const;              //Getter for floors in parking lot
};

//Defination of ParkingLot Constructor for parameterized constructor 
ParkingLot::ParkingLot(int number_of_floors, int capacity_per_floor){
    max_capacity = number_of_floors * capacity_per_floor;   //calculating and putting maximum capacity of parking lot
    parking_floors.reserve(number_of_floors);               //Fixing the size of Floor
    for(int i = 1; i <= number_of_floors; i++)  {       //Iteratation for allocating Parking floors
        parking_floors.emplace_back(i, capacity_per_floor);     //Putting floor in parking lot
    }

}

//Defination of getMaxCapacity function for get capacity
int ParkingLot::getMaxCapacity() const{
    return max_capacity;
}

//Defination of getFloors function for get floors in parking lot
const vector<ParkingFloor>& ParkingLot::getFloors() const{
    return parking_floors;
}

#endif      //End of ParkingLot Hearder File