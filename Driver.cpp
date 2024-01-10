#include <iostream>
#include <cmath>
#include "Driver.h"

// Default Constructor
Driver::Driver(std::string FN) { 
  First_Name = FN;
  }

// Second Complex Constructor 
Driver::Driver(std::string FN, std::string LN, std::string G, int A, std::string PN, double R, double CLA, double CLO, std::string VT, std::string CS, std::string RFN, std::string RLN, std::string RPN) { 
  First_Name = FN;
  Last_Name = LN;
  Gender = G;
  Age = A;
  Phone_Number = PN;
  Rating = R;
  Current_Latitude = CLA;
  Current_Longitude = CLO;
  Vehicle_Type = VT;
  Current_State = CS;
  RidersFN = RFN;
  RidersLN = RLN;
  RidersPN = RPN;
  }

// GETTERS
std::string Driver::getFirstName() const {
    return First_Name;
  }

std::string Driver::getLastName() const {
    return Last_Name;
  }

std::string Driver::getGender() const {
    return Gender;
}

int Driver::getAge() const {
    return Age;
}

std::string Driver::getPhoneNumber() const {
    return Phone_Number;
}

double Driver::getRating() const {
    return Rating;
}

double Driver::getCurrent_Lat() const {
    return Current_Latitude;
}

double Driver::getCurrent_Lon() const {
    return Current_Longitude;
}

std::string Driver::getVehicleType() const {
    return Vehicle_Type;
}

std::string Driver::getCurrentState() const {
    return Current_State;
}

std::string Driver::getRidersFN() const {
    return RidersFN;
}

std::string Driver::getRidersLN() const {
    return RidersLN;
}

std::string Driver::getRidersPN() const {
    return RidersPN;
}

/// /// /// /// ///

// SETTERS
void Driver::setFirstName(std::string FN) {
  First_Name = FN;
}

void Driver::setLastName(std::string LN) {
  Last_Name = LN;
}

void Driver::setGender(std::string G) {
  Gender = G;
}

void Driver::setAge(int A) {
  Age = A;
}

void Driver::setPhoneNumber(std::string PN) {
  Phone_Number = PN;
}

void Driver::setRating(double R) {
  Rating = R;
}

void Driver::setCurrent_Lat(double CLA) {
  Current_Latitude = CLA;
}

void Driver::setCurrent_Lon(double CLO) {
  Current_Longitude = CLO;
}

void Driver::setVehicleType(std::string VT) {
  Vehicle_Type = VT;
}

void Driver::setCurrentState(std::string CS) {
  Current_State = CS;
}

void Driver::setRidersFN(std::string RFN) {
  RidersFN = RFN;
}

void Driver::setRidersLN(std::string RLN) {
  RidersLN = RLN;
}

void Driver::setRidersPN(std::string RPN) {
  RidersPN = RPN;
}


// << Operator
std::ostream& operator<< (std::ostream& out, const Driver& m) {
  out << m.getFirstName() << " " << m.getLastName() << " ";
  out << m.getGender() << " " << m.getAge() << " ";
  out << m.getPhoneNumber() << " " << m.getRating() << " ";
  out << m.getCurrent_Lat() << " " << m.getCurrent_Lon() << " ";
  out << m.getVehicleType() << " " << m.getCurrentState() << " ";
  out << m.getRidersFN() << " " << m.getRidersLN() << " " << m.getRidersPN();
  return out;
}






