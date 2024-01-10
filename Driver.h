#ifndef DRIVER_H
#define DRIVER_H

class Driver {

public:
  Driver();
  Driver(std::string FN);
  Driver(std::string FN, std::string LN, std::string G, int A, std::string PN, double R, double CLA, double CLO, std::string VT, std::string CS, std::string RFN, std::string RLN, std::string RPN);

  // GETTERS
  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getGender() const;
  int getAge() const;
  std::string getPhoneNumber() const;
  double getRating() const;
  double getCurrent_Lat() const;
  double getCurrent_Lon() const;
  std::string getVehicleType() const;
  std::string getCurrentState() const;
  std::string getRidersFN() const;
  std::string getRidersLN() const;
  std::string getRidersPN() const;

  // MODIFIERS
  void setFirstName(std::string FN);
  void setLastName(std::string LN);
  void setGender(std::string G);
  void setAge(int A);
  void setPhoneNumber(std::string PN);
  void setRating(double R);
  void setCurrent_Lat(double CLA);
  void setCurrent_Lon(double CLO);
  void setVehicleType(std::string VT);
  void setCurrentState(std::string CS);
  void setRidersFN(std::string RFN);
  void setRidersLN(std::string RLN);
  void setRidersPN(std::string RPN);

private:  // REPRESENTATION (member variables)
  std::string First_Name;
  std::string Last_Name;
  std::string Gender;
  int Age;
  std::string Phone_Number;
  double Rating;
  double Current_Latitude;
  double Current_Longitude;
  std::string Vehicle_Type;
  std::string Current_State;
  std::string RidersFN;
  std::string RidersLN;
  std::string RidersPN;

};

std::ostream& operator<< (std::ostream& out, const Driver& m);

#endif


