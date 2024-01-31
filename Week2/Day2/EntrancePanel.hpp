#include <bits/stdc++.h>
using namespace std;

#ifndef PARKINGTICKET_HPP
#include "ParkingTicket.hpp"
#endif

/*
    Security Check for EntrancePanel Class Non-repeatation
*/
#ifndef ENTRANCEPANEL_HPP
#define ENTRANCEPANEL_HPP 1

class EntrancePanel{
public:
    ParkingTicket getTicket(SpotType type, float entry_time);

};

ParkingTicket EntrancePanel::getTicket(SpotType type, float entry_time){
    static int ticket_counter = 1;
    return ParkingTicket(ticket_counter++, type, entry_time);
}

#endif