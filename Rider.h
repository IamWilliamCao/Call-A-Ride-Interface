#ifndef RIDER_H
#define RIDER_H

class Rider {

public:
  Rider();
  Rider(std::string FN);
  Rider(std::string FN, std::string LN, std::string G, int A, std::string PN, std::string PL, double R, double LA_PL, double LO_PL, std::string DL, double LA_DL, double LO_DL, std::string VP, std::string CS, std::string DFN, std::string DLN, std::string DPN);

  // GETTERS
  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getGender() const;
  int getAge() const;
  std::string getPhoneNumber() const;
  double getRating() const;
  std::string getPickup_Location() const;
  double getLatitude_P_L() const;
  double getLongitude_P_L() const;
  std::string getDropoff_Location() const;
  double getLatitude_D_L() const;
  double getLongitude_D_L() const;
  std::string getVehicle_Pref() const;
  std::string getCurrentState() const;
  std::string getDriversFN() const;
  std::string getDriversLN() const;
  std::string getDriversPN() const;

  // MODIFIERS
  void setFirstName(std::string FN);
  void setLastName(std::string LN);
  void setGender(std::string G);
  void setAge(int A);
  void setPhoneNumber(std::string PN);
  void setRating(double R);
  void setPickup_Location(std::string PL);
  void setLatitude_P_L(double LA_PL);
  void setLongitude_P_L(double LO_PL);
  void setDropoff_Location(std::string DL);
  void setLatitude_D_L(double LA_DL);
  void setLongitude_D_L(double LO_DL);
  void setVehicle_Pref(std::string VP);
  void setCurrentState(std::string CS);
  void setDriversFN(std::string DFN);
  void setDriversLN(std::string DLN);
  void setDriversPN(std::string DPN);

private:  // REPRESENTATION (member variables)
  std::string First_Name;
  std::string Last_Name;
  std::string Gender;
  int Age;
  std::string Phone_Number;
  double Rating;
  std::string Pickup_Location;
  double Latitude_P_L;
  double Longitude_P_L;
  std::string Dropoff_Location;
  double Latitude_D_L;
  double Longitude_D_L;
  std::string Vehicle_Pref;
  std::string Current_State;
  std::string Drivers_F_N;
  std::string Drivers_L_N;
  std::string Drivers_P_N;

};

std::ostream& operator<< (std::ostream& out, const Rider& m);

#endif

