#include <bits/stdc++.h>
using namespace std;

/*
    Security Check for ParkingSpot class & SpotType enum non-repeatation
*/
#ifndef PARKINGSPOT_HPP
#include "ParkingSpot.hpp"
#endif

/*
    Security Check for ParkingTicket Class non-repeatation
*/
#ifndef PARKINGTICKET_HPP
#define PARKINGTICKET_HPP 1

class ParkingTicket{
private:
    int ticket_number;      //To store ticket number of parking
    SpotType spot_type;     //To store type of parking spot
    float entry_time;       //To store time of punch in
public:
    ParkingTicket(int ticket_number, SpotType spot_type, float entry_time);     //Constructor for ParkingTicket init
    int getTicketNumber() const;                                                //Getter for Ticket Number
    SpotType getSpotType() const;                                               //Getter for Ticket Spot Type
    float getEntryTime() const;                                                 //Getter for Entry Time of Vehicle
};

//Defination of ParkingTicket constructor
ParkingTicket::ParkingTicket(int ticket_number, SpotType spot_type, float entry_time){
    this->ticket_number = ticket_number;
    this->spot_type = spot_type;
    this->entry_time = entry_time;
}

//Defination of getTicketNumber 
int ParkingTicket::getTicketNumber() const{
    return this->ticket_number;
}

//Defination of getSpotType
SpotType ParkingTicket::getSpotType() const{
    return this->spot_type;
}

//Defination of getEntryTime
float ParkingTicket::getEntryTime() const{
    return this->entry_time;
}

#endif