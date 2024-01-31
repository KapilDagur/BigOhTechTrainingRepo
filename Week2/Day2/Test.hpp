#include "ParkingSystem.hpp"

void test(){
    ParkingSystem parking_system(4, 20);

    EntrancePanel& entrance_panel = parking_system.getEntrancePanel();
    ExitPanel& exit_panel = parking_system.getExitPanel();
    Customer& customer = parking_system.getCustomer();
    ParkingAttendant& parking_attandent = parking_system.getParkingAttandant();

    //Test Case 1
    cout<<"Test 1 : (10hr parking charge)"<<endl;
    ParkingTicket ticket = entrance_panel.getTicket(LARGE, 10);
    double money_paid = exit_panel.getCharge(ticket);
    exit_panel.processPayment(ticket, money_paid);
    customer.payAtPortal(money_paid);
    parking_attandent.processPayment(ticket, money_paid);

    //Test Case 2
    cout<<"Test 2 : (8hr parking charge)"<<endl;
    ParkingTicket ticket1 = entrance_panel.getTicket(LARGE, 8);
    money_paid = exit_panel.getCharge(ticket1);
    exit_panel.processPayment(ticket, money_paid);
    customer.payAtPortal(money_paid);
    parking_attandent.processPayment(ticket, money_paid);

}