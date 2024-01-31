#include "ParkingSystem.hpp"

void test(){
    ParkingSystem parking_system(4, 20);

    EntrancePanel& entrance_panel = parking_system.getEntrancePanel();
    ExitPanel& exit_panel = parking_system.getExitPanel();
    Customer& customer = parking_system.getCustomer();
    ParkingAttendant& parking_attandent = parking_system.getParkingAttandant();

    ParkingTicket ticket = entrance_panel.getTicket(LARGE, 10.20);
    double money_paid = 10.0;
    exit_panel.processPayment(ticket, money_paid);
    customer.payAtPortal(money_paid);
    parking_attandent.processPayment(ticket, money_paid);

}