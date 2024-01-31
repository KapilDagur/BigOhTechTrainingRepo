#include <bits/stdc++.h>
using namespace std;

/*
    Security Check for ParkingTicket class Non-repeatation
*/
#ifndef PARKINGTICKET_HPP
#include "ParkingTicket.hpp"
#endif

/*
    Security Check for ExitPanel class Non-repeatation 
*/
#ifndef ExitPanel
#define EXITPANEL_HPP 1

class ExitPanel{
public:
    void processPayment(const ParkingTicket& ticket, double payment_amount);
    double getCharge(const ParkingTicket& ticket);
};

void ExitPanel::processPayment(const ParkingTicket& ticket, double payment_amount){
    cout<<"Payment of $"<<payment_amount<<", for Ticket Number #"<<ticket.getTicketNumber()<<" Recived !!"<<endl;
}

double ExitPanel::getCharge(const ParkingTicket& ticket){
    int time_hh = ticket.getTime();
    double charge = 0;
    if(time_hh >= 1){
        charge += 4.0;
        time_hh -= 1;
    }
    if(time_hh >= 1){
        charge += 3.5;
        time_hh -= 1;
    }
    if(time_hh >= 1){
        charge += 3.5;
        time_hh -= 1;
    }
    if(time_hh > 0){
        charge += time_hh*2.5;
    }
    return charge;
}

#endif