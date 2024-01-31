#include <bits/stdc++.h>
using namespace std;
/*
    @author : KAPIL DAGUR
*/


/*
    Security Check for MP Class Non-repeatation
*/

#ifndef MP_HPP
#define MP_HPP 1

class MP{
protected:
    string winning_constituency;     //To store the winning constituency of mp
    string driver;                   //To store the allocated drive name
    string vehicle; 
    long current_spending;

public:
    MP(const string& winning_constituency); //Constructor of MP Class
    const string& getDriverName() const;    //To get driver name
    const string& getConstituency() const;  //To get winning constituency
    void spendMoney(long amount);           //To spend of Base Class
    virtual bool isExceedsSpendingLimit() const;//To check expenses(spending) virtual function for override

};

MP::MP(const string& winning_constituency) {
    this->winning_constituency = winning_constituency;
    this->driver = "Mohan";
    this->vehicle = "Car";
}

//Defination of getDriverName function
const string& MP::getDriverName() const{
    return this->driver;
}

//Defination of getConstituency of MP
const string& MP::getConstituency() const{
    return this->winning_constituency;
}

//Defination of spendMoney of  MP
void MP::spendMoney(long amount){
    if(amount > 0){
        current_spending += amount;
    }
}

//Defination of virtual fuction of isExceedsSpendingLimit
bool MP::isExceedsSpendingLimit() const{
    return this->current_spending > 100000;
}

#endif