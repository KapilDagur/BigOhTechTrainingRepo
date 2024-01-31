#include <bits/stdc++.h>
using namespace std;

#ifndef PARKINGSYSTEM_HPP
#define PARKINGSYSTEM_HPP 1

#include "ParkingLot.hpp"
#include "EntrancePanel.hpp"
#include "ExitPanel.hpp"
#include "Customer.hpp"
#include "ParkingAttendant.hpp"

class ParkingSystem{
private:
    ParkingLot parking_lot;             //To store Parking Lot 
    EntrancePanel entrance_panel;       //To store & Control Entrance
    ExitPanel exit_panel;                     //To store & Control Exit
    Customer customer;                  //To store customer
    ParkingAttendant parking_attendant; //To store parking attendant
public:
    ParkingSystem(int number_of_floors, int capacity_per_floor) : parking_lot(number_of_floors, capacity_per_floor){};

    const ParkingLot& getParkingLot() const;    //Getter for Parking Lot
    EntrancePanel& getEntrancePanel();          //Getter for Parking Entrance
    ExitPanel& getExitPanel();                  //Getter for Parking Exit
    Customer& getCustomer();                    //Getter for Customer Action
    ParkingAttendant& getParkingAttandant();    //Getter for Parking Attandant
};

//Defination of getParkingLot for get Parking Lot
const ParkingLot& ParkingSystem::getParkingLot() const{
    return this->parking_lot;
}

//Defination of getEntrancePanel for get Entrance
EntrancePanel& ParkingSystem::getEntrancePanel(){
    return this->entrance_panel;
}

//Defination of getExitPanel for get Exit
ExitPanel& ParkingSystem::getExitPanel(){
    return this->exit_panel;
}

//Defination of getCusotmer for get Customer
Customer& ParkingSystem::getCustomer(){
    return this->customer;
}

//Defination of getParkingAttandant for get Parking Attandant
ParkingAttendant& ParkingSystem::getParkingAttandant(){
    return this->parking_attendant;
}

#endif