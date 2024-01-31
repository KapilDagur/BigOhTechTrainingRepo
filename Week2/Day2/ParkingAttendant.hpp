#include <bits/stdc++.h>
using namespace std;

/*
    Security Check for ParkingTicket Class Non-repeatation
*/
#ifndef PARKINGTICKET_HPP
#include "ParkingTicket.hpp"
#endif

/*
    Security Check for ParkingAttendant Class Non-repeatation
*/
#ifndef PARKINGATTENDANT_HPP
#define PARKINGATTENDANT_HPP 1

class ParkingAttendant{
public:
    void processPayment(const ParkingTicket& ticket, double payment_amount){
        cout<<"Processed Payment of $"<<payment_amount<<" by Parking Attendant for Ticket #"<<ticket.getTicketNumber()<<endl;
    }
};


#endif