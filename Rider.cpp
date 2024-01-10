#include <iostream>
#include <cmath>
#include "Rider.h"


// Default Constructor
Rider::Rider(std::string FN) { 
  First_Name = FN;
  }

// Second Complex Constructor 
Rider::Rider(std::string FN, std::string LN, std::string G, int A, std::string PN, std::string PL, double R, double LA_PL, double LO_PL, std::string DL, double LA_DL, double LO_DL, std::string VP, std::string CS, std::string DFN, std::string DLN, std::string DPN) { 
  First_Name = FN;
  Last_Name = LN;
  Gender = G;
  Age = A;
  Phone_Number = PN;
  Rating = R;
  Pickup_Location = PL;
  Latitude_P_L = LA_PL;
  Longitude_P_L = LO_PL;
  Dropoff_Location = DL;
  Latitude_D_L = LA_DL;
  Longitude_D_L = LO_DL;
  Vehicle_Pref = VP;
  Current_State = CS;
  Drivers_F_N = DFN;
  Drivers_L_N = DLN;
  Drivers_P_N = DPN;
  }

// GETTERS

std::string Rider::getFirstName() const {
  return First_Name;
}

std::string Rider::getLastName() const {
  return Last_Name;
}

std::string Rider::getGender() const {
  return Gender;
}

int Rider::getAge() const {
  return Age;
}

std::string Rider::getPhoneNumber() const {
  return Phone_Number;
}

double Rider::getRating() const {
  return Rating;
}

std::string Rider::getPickup_Location() const {
  return Pickup_Location;
}

double Rider::getLatitude_P_L() const {
  return Latitude_P_L;
}

double Rider::getLongitude_P_L() const {
  return Longitude_P_L;
}

std::string Rider::getDropoff_Location() const {
  return Dropoff_Location;
}

double Rider::getLatitude_D_L() const {
  return Latitude_D_L;
}

double Rider::getLongitude_D_L() const {
  return Longitude_D_L;
}

std::string Rider::getVehicle_Pref() const {
  return Vehicle_Pref;
}

std::string Rider::getCurrentState() const {
  return Current_State;
}

std::string Rider::getDriversFN() const {
  return Drivers_F_N;
}

std::string Rider::getDriversLN() const {
  return Drivers_L_N;
}

std::string Rider::getDriversPN() const {
  return Drivers_P_N;
}

/// /// /// /// ///

// SETTERS
void Rider::setFirstName(std::string FN) {
  First_Name = FN;
}

void Rider::setLastName(std::string LN) {
  Last_Name = LN;
}

void Rider::setGender(std::string G) {
  Gender = G;
}

void Rider::setAge(int A) {
  Age = A;
}

void Rider::setPhoneNumber(std::string PN) {
  Phone_Number = PN;
}

void Rider::setRating(double R) {
  Rating = R;
}
  
void Rider::setPickup_Location(std::string PL) {
  Pickup_Location = PL;
}

void Rider::setLatitude_P_L(double LA_PL) {
  Latitude_P_L = LA_PL;
}

void Rider::setLongitude_P_L(double LO_PL) {
  Longitude_P_L = LO_PL;
}

void Rider::setDropoff_Location(std::string DL) {
  Dropoff_Location = DL;
}

void Rider::setLatitude_D_L(double LA_DL) {
  Latitude_D_L = LA_DL;
}

void Rider::setLongitude_D_L(double LO_DL) {
  Longitude_D_L = LO_DL;
}

void Rider::setVehicle_Pref(std::string VP) {
  Vehicle_Pref = VP;
}

void Rider::setCurrentState(std::string CS) {
  Current_State = CS;
}

void Rider::setDriversFN(std::string DFN) {
  Drivers_F_N = DFN;
}

void Rider::setDriversLN(std::string DLN) {
  Drivers_L_N = DLN;
}

void Rider::setDriversPN(std::string DPN) {
  Drivers_P_N = DPN;
}

// << Operator
std::ostream& operator<< (std::ostream& out, const Rider& m) {
  out << m.getFirstName() << " " << m.getLastName() << " ";
  out << m.getGender() << " " << m.getAge() << " ";
  out << m.getPhoneNumber() << " " << m.getRating() << " ";
  out << m.getPickup_Location() << " ";
  out << m.getLatitude_P_L() << " " << m.getLongitude_P_L() << " ";
  out << m.getDropoff_Location() << " ";
  out << m.getLatitude_D_L() << " " << m.getLongitude_D_L() << " ";
  out << m.getVehicle_Pref() << " " << m.getCurrentState() << " ";
  out << m.getDriversFN() << " " << m.getDriversLN() << " " << m.getDriversPN();
  return out;
}










