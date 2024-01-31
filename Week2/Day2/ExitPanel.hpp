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
};

void ExitPanel::processPayment(const ParkingTicket& ticket, double payment_amount){
    cout<<"Payment of $"<<payment_amount<<", for Ticket Number #"<<ticket.getTicketNumber()<<" Recived !!"<<endl;
}

#endif