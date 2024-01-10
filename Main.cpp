#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <list>
#include "Rider.h"
#include "Driver.h"

//By making a function to print out every drivers for output1, it saves a lot of space
void PrintForOutput1(std::list<Driver>& drivers, std::list<Driver>::iterator itrDriver, std::ofstream& out_str){
	itrDriver = drivers.begin();
	int listSize = drivers.size();
	for (int i=0; i<listSize; i++)
	{
	out_str << *itrDriver << std::endl;
	itrDriver++;
	}
}

//Similar to the above function, this one saves a lot of space
void PrintForOutput2(std::list<Rider>& riders, std::list<Rider>::iterator itrRider, std::ofstream& out_str){
	itrRider = riders.begin();
	int listSize = riders.size();
	for (int i=0; i<listSize; i++)
	{
	out_str << *itrRider << std::endl;
	itrRider++;
	}
}

//You need two different print out functions for REQUEST, CANCEL, and NO_DRIVERS, since the text is different.
void PrintForOutput0Request(std::list<Rider>& riders, std::list<Rider>::iterator& itrRider, std::string DriverFN, double Rating, double Distance, std::ofstream& out_str){
	Distance = Distance * 10;
	Distance = floor(Distance);
	Distance = Distance / 10;

	if (itrRider->getVehicle_Pref() == "Economy")
	{
	out_str << "Ride requested for user " << itrRider->getFirstName() << ", looking for an " << itrRider->getVehicle_Pref() << " vehicle." << std::endl;
	out_str << "Pick Up Location: " << itrRider->getPickup_Location() << ", Drop Off Location: " << itrRider->getDropoff_Location() << "." << std::endl;
	out_str << "We have found the closest driver " << DriverFN << "(" << Rating << ") for you." << std::endl;
	out_str << DriverFN << " is now " << Distance << " miles away from you." << std::endl;
	}
	else
	{
	out_str << "Ride requested for user " << itrRider->getFirstName() << ", looking for a " << itrRider->getVehicle_Pref() << " vehicle." << std::endl;
	out_str << "Pick Up Location: " << itrRider->getPickup_Location() << ", Drop Off Location: " << itrRider->getDropoff_Location() << "." << std::endl;
	out_str << "We have found the closest driver " << DriverFN << "(" << Rating << ") for you." << std::endl;
	out_str << DriverFN << " is now " << Distance << " miles away from you." << std::endl;
	}
	
}

void PrintForOutput0Cancel(std::list<Rider>& riders, std::list<Rider>::iterator& itrRider, std::string OGDriverFN, std::string DriverFN, double Rating, double Distance, std::ofstream& out_str){
	Distance = Distance * 10;
	Distance = floor(Distance);
	Distance = Distance / 10;

	if (itrRider->getVehicle_Pref() == "Economy")
	{
	out_str << "Your driver " << OGDriverFN << " has cancelled the ride request. We will now find a new driver for you." << std::endl;
	out_str << "Ride requested for user " << itrRider->getFirstName() << ", looking for an " << itrRider->getVehicle_Pref() << " vehicle." << std::endl;
	out_str << "Pick Up Location: " << itrRider->getPickup_Location() << ", Drop Off Location: " << itrRider->getDropoff_Location() << "." << std::endl;
	out_str << "We have found the closest driver " << DriverFN << "(" << Rating << ") for you." << std::endl;
	out_str << DriverFN << " is now " << Distance << " miles away from you." << std::endl;
	}
	else
	{
	out_str << "Your driver " << OGDriverFN << " has cancelled the ride request. We will now find a new driver for you." << std::endl;
	out_str << "Ride requested for user " << itrRider->getFirstName() << ", looking for a " << itrRider->getVehicle_Pref() << " vehicle." << std::endl;
	out_str << "Pick Up Location: " << itrRider->getPickup_Location() << ", Drop Off Location: " << itrRider->getDropoff_Location() << "." << std::endl;
	out_str << "We have found the closest driver " << DriverFN << "(" << Rating << ") for you." << std::endl;
	out_str << DriverFN << " is now " << Distance << " miles away from you." << std::endl;
	}
}

void PrintForOutput0NoDriver(std::list<Rider>& riders, std::list<Rider>::iterator& itrRider, std::ofstream& out_str){
	if (itrRider->getVehicle_Pref() == "Economy")
	{
	out_str << "Ride request for user " << itrRider->getFirstName() << ", looking for an " << itrRider->getVehicle_Pref() << " vehicle." << std::endl;
	out_str << "Pick Up Location: " << itrRider->getPickup_Location() << ", Drop Off Location: " << itrRider->getDropoff_Location() << " ." << std::endl;
	out_str << "Sorry we can not find a driver for you at this moment." << std::endl;
	}
	else
	{
	out_str << "Ride request for user " << itrRider->getFirstName() << ", looking for a " << itrRider->getVehicle_Pref() << " vehicle." << std::endl;
	out_str << "Pick Up Location: " << itrRider->getPickup_Location() << ", Drop Off Location: " << itrRider->getDropoff_Location() << " ." << std::endl;
	out_str << "Sorry we can not find a driver for you at this moment." << std::endl;	
	}
}

//Two simple function that quickly checks a rider's/phone-nummber existence and outputs each scenarios text.
bool CheckForRider(std::list<Rider>& riders, std::list<Rider>::iterator itrRider, std::string PhoneNum, std::ofstream& out_str){
	itrRider = riders.begin();
	int listSize = riders.size();
	for (int i=0; i<listSize; i++)
	{
		if (PhoneNum == itrRider->getPhoneNumber())
		{
			if (itrRider->getCurrentState() == "Driver_on_the_way")
			{
			out_str << "You have already requested a ride and your driver is on the way to the pickup location." << std::endl;
			exit(1);	
			}

			if (itrRider->getCurrentState() == "During_the_trip")
			{
			out_str << "You can not request a ride at this moment as you are already on a trip." << std::endl;	
			exit(1);
			}

			if (itrRider->getCurrentState() == "Ready_to_request")
			{
			return true;
			}

			out_str << "Account does not exist." << std::endl;	
			exit(1);
		}
	itrRider++;
	}
	out_str << "Account does not exist." << std::endl;	
	exit(1);
}

bool CheckForPhoneNumber(std::list<Rider>& riders, std::list<Rider>::iterator itrRider, std::list<Driver>& drivers, std::list<Driver>::iterator itrDriver, std::string PhoneNum, std::ofstream& out_str){
	itrRider = riders.begin();
	itrDriver = drivers.begin();
	int listsize = riders.size();

	for (int i=0; i<listsize; i++)
	{
		if (PhoneNum == itrRider->getPhoneNumber())
		{
			return true;
		}

		if (PhoneNum == itrDriver->getPhoneNumber())
		{
			return true;
		}
	itrRider++;
	itrDriver++;
	}
	out_str << "Account does not exist." << std::endl;	
	exit(1);
}

//The given function by the assignment
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double radiusOfEarth = 6371.0; // Earth's radius in kilometers

    // convert latitude and longitude from degrees to radians
    lat1 *= M_PI / 180.0;
    lon1 *= M_PI / 180.0;
    lat2 *= M_PI / 180.0;
    lon2 *= M_PI / 180.0;

    // Haversine formula
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2.0) * sin(dLat / 2.0) + cos(lat1) * cos(lat2) * sin(dLon / 2.0) * sin(dLon / 2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    // distance in kilometers
    double distanceKM = radiusOfEarth * c;
    // convert it to distance in miles
    double distanceMiles = distanceKM * 0.621371;

    return distanceMiles;
}

 // // // // // // // // // // // // // // // // // // 

 // MAIN

int main(int argc, char** argv){

	//INPUT FOR DRIVERS
	std::ifstream in_str1(argv[1]);

    if (!in_str1.good()) {
    std::cerr << "Can't open " << argv[1] << " to read.\n";
    exit(1);
    }

    //INPUT FOR RIDERS
	std::ifstream in_str2(argv[2]);

    if (!in_str2.good()) {
    std::cerr << "Can't open " << argv[2] << " to read.\n";
    exit(1);
    }

    //OUTPUT-0
    std::ofstream out_str0(argv[3]);

    //OUTPUT-1
    std::ofstream out_str1(argv[4]);

    //OUTPUT-2
    std::ofstream out_str2(argv[5]);

    //COMMAND
    std::string Command = argv[7];

    //CHECKING IF PHONE NUMBERS PROVIDED IS VALID 974-349-9468

    std::string PhoneNumString = argv[6];
    if (PhoneNumString.size() != 12)
    {
    out_str0 << "Phone number is invalid." << std::endl;
    exit(1);
    }
    else
    {
    if (PhoneNumString[3] != '-' && PhoneNumString[7] != '-')
	    {
	    out_str0 << "Phone number is invalid." << std::endl;	
	    exit(1);
	    }
    }


 // // // // // // // // // // // // // // // // // // 

 // Creation of List and Their Iterators

 	std::list<Driver> drivers;
 	std::list<Driver>::iterator itrDriver = drivers.begin();

 	std::list<Rider> riders;
 	std::list<Rider>::iterator itrRider = riders.begin();

 	std::string ClassString;
 	std::list<std::string> ClassStorage;
 	std::list<std::string>::iterator itrString = ClassStorage.begin();

    //Parsing To Store DRIVERS 
    int newline = 0;
    int Age;
    double Rating;
    double LA;
    double LO;
    while (in_str1 >> ClassString) 
    {
	    ClassStorage.push_back(ClassString);
	    newline += 1;

	   //CREATING NEW OBJECTS
		if (newline == 13) 
		{
		itrString++;
		Driver a(*itrString);
		itrString++;
		//
		a.setLastName(*itrString);
		itrString++;
		//
		a.setGender(*itrString);
		itrString++;
		//
		Age = std::stoi(*itrString);
		a.setAge(Age);
		itrString++;
		//
		a.setPhoneNumber(*itrString);
		itrString++;
		//
		Rating = stod(*itrString);
		a.setRating(Rating);
		itrString++;
		//
		LA = stod(*itrString);
		a.setCurrent_Lat(LA);
		itrString++;
		//
		LO = stod(*itrString);
		a.setCurrent_Lon(LO);
		itrString++;
		//
		a.setVehicleType(*itrString);
		itrString++;
		//
		a.setCurrentState(*itrString);
		itrString++;
		//
		if (a.getCurrentState() == "Available")
		{
		a.setRidersFN("null");
		itrString++;
		a.setRidersLN("null");
		itrString++;
		a.setRidersPN("null");
		drivers.push_back(a);
		newline = 0;
		}
		else if (a.getCurrentState() != "Available")
		{
		a.setRidersFN(*itrString);
		itrString++;
		//
		a.setRidersLN(*itrString);
		itrString++;
		//
		a.setRidersPN(*itrString);
		drivers.push_back(a);
		newline = 0;
		}
		}
	}

	ClassStorage.clear();

	itrString = ClassStorage.begin();

	//Parsing To Store RIDERS
    double Lat_Pickup;
    double Lon_Pickup;
    double Lat_Dropoff;
    double Lon_Dropoff;
    while (in_str2 >> ClassString) 
    {
	    ClassStorage.push_back(ClassString);
	    newline += 1;

	   //CREATING NEW OBJECTS
		if (newline == 17) 
		{
		itrString++;
		Rider b(*itrString);
		itrString++;
		//
		b.setLastName(*itrString);
		itrString++;
		//
		b.setGender(*itrString);
		itrString++;
		//
		Age = std::stoi(*itrString);
		b.setAge(Age);
		itrString++;
		//
		b.setPhoneNumber(*itrString);
		itrString++;
		//
		Rating = stod(*itrString);
		b.setRating(Rating);
		itrString++;
		//
		b.setPickup_Location(*itrString);
		itrString++;
		//
		Lat_Pickup = stod(*itrString);
		b.setLatitude_P_L(Lat_Pickup);
		itrString++;
		//
		Lon_Pickup = stod(*itrString);
		b.setLongitude_P_L(Lon_Pickup);
		itrString++;
		//
		b.setDropoff_Location(*itrString);
		itrString++;
		//
		Lat_Dropoff = stod(*itrString);
		b.setLatitude_D_L(Lat_Dropoff);
		itrString++;
		//
		Lon_Dropoff = stod(*itrString);
		b.setLongitude_D_L(Lon_Dropoff);
		itrString++;
		//
		b.setVehicle_Pref(*itrString);
		itrString++;
		//
		b.setCurrentState(*itrString);
		itrString++;
		//
		if (b.getCurrentState() == "Ready_to_request")
			{
			b.setDriversFN("null");
			b.setDriversLN("null");
			b.setDriversPN("null");
			riders.push_back(b);
			newline = 0;
			itrString++;
			itrString++;
			}
			else if (b.getCurrentState() != "Ready_to_request")
			{
			b.setDriversFN(*itrString);
			itrString++;
			//
			b.setDriversLN(*itrString);
			itrString++;
			//
			b.setDriversPN(*itrString);
			riders.push_back(b);
			newline = 0;
			}
		}
	}
	ClassStorage.clear();



// IF GIVEN A REQUEST ORDER

if (Command == "request") 
{

 // // // // // // // // // // // // // // // // // // 

 // Checking Rider and Finding Nearest Driver

	CheckForRider(riders, itrRider, PhoneNumString, out_str0);

	//I need the loop to go through the rider data and find the right rider 
	itrRider = riders.begin();
	while (PhoneNumString != itrRider->getPhoneNumber())
	{
	itrRider++;
	}

	//Checks for the nearest driver
	itrDriver = drivers.begin();
	int driverslistSize = drivers.size();
	std::string SelectedDriverName;
	std::string SelectedDriverNumber;
	double SelectedDriverRating;
	double SelectedDriverDistance = 999;
	double SelectedDriverComparision;
	for (int i = 0; i < driverslistSize; i++)
	{
		if (itrDriver->getCurrentState() == "Available" && itrRider->getVehicle_Pref() == itrDriver->getVehicleType())
		{
		
		SelectedDriverComparision = calculateDistance(itrRider->getLatitude_P_L(), itrRider->getLongitude_P_L(), itrDriver->getCurrent_Lat(), itrDriver->getCurrent_Lon());

			if (SelectedDriverDistance > SelectedDriverComparision)
			{
			//If we didn't include these 4 variables below, I will never be able to obtain the NEAREST driver
			SelectedDriverDistance = SelectedDriverComparision;
			SelectedDriverName = itrDriver->getFirstName();
			SelectedDriverRating = itrDriver->getRating();
			SelectedDriverNumber = itrDriver->getPhoneNumber();
			}

		}	
	itrDriver++;
	}
	//Because the distance will never be 999, it's a good number to use to determine if we can't find a driver
	if (SelectedDriverDistance == 999) 
	{
	PrintForOutput0NoDriver(riders, itrRider, out_str0);
	exit(1);
	}

	itrDriver = drivers.begin();
	while (SelectedDriverNumber != itrDriver->getPhoneNumber())
	{
	itrDriver++;
	}
	

 // // // // // // // // // // // // // // // // // // 

 // Changing the Driver and Rider data for printiner

	itrDriver->setCurrentState("On_the_way_to_pickup");
	itrDriver->setRidersFN(itrRider->getFirstName());
	itrDriver->setRidersLN(itrRider->getLastName());
	itrDriver->setRidersPN(itrRider->getPhoneNumber());
	itrRider->setCurrentState("Driver_on_the_way");
	itrRider->setDriversFN(itrDriver->getFirstName());
	itrRider->setDriversLN(itrDriver->getLastName());
	itrRider->setDriversPN(itrDriver->getPhoneNumber());


 // // // // // // // // // // // // // // // // // // 

 // Printing Output

	PrintForOutput0Request(riders, itrRider, SelectedDriverName, SelectedDriverRating, SelectedDriverDistance, out_str0);
	PrintForOutput1(drivers, itrDriver, out_str1);
	PrintForOutput2(riders, itrRider, out_str2);
}

// IF GIVEN A CANCEL ORDER
else if (Command == "cancel") 
{

	CheckForPhoneNumber(riders, itrRider, drivers, itrDriver, PhoneNumString, out_str0);

 // // // // // // // // // // // // // // // // // // 

 // Checking if command is a Rider or Driver, also other cases.

	bool RiderCanceling = false;
	bool DriverCanceling = false;
	bool Nothing = false;
	itrRider = riders.begin();
	itrDriver = drivers.begin();
	while (RiderCanceling == false && DriverCanceling == false && Nothing == false)
	{
		if (PhoneNumString == itrRider->getPhoneNumber())
		{
		RiderCanceling = true;
		std::cout << "Rider" << std::endl;
		} 
		else if (PhoneNumString == itrDriver->getPhoneNumber())
		{
		DriverCanceling = true;
		std::cout << "Driver" << std::endl;
		}
		else
		{
		if (itrRider == riders.end())
		{
		Nothing = true;
		}
		itrRider++;
		itrDriver++;
		}
	}

	if (RiderCanceling == false && DriverCanceling == false)
	{

	out_str0 << "Account does not exist." << std::endl;	
	exit(1);
	}


 // // // // // // // // // // // // // // // // // // 

 // If the Rider is Canceling

	if (RiderCanceling == true)
	{	
		if (itrRider->getCurrentState() == "Driver_on_the_way")
		{
		out_str0 << "Ride request for user " << itrRider->getFirstName() << " is now canceled by the user." << std::endl;

		itrDriver = drivers.begin();
		while (PhoneNumString != itrDriver->getRidersPN())
		{
		itrDriver++;
		}
		itrDriver->setCurrentState("Available");
		itrDriver->setRidersFN("null");
		itrDriver->setRidersLN("null");
		itrDriver->setRidersPN("null");

		riders.erase(itrRider);
		}
		else
		{
		out_str0 << "You can only cancel a ride request if your driver is currently on the way to the pickup location." << std::endl;	
		exit(1);
		}


 // // // // // // // // // // // // // // // // // // 

 // Printing Output

	PrintForOutput1(drivers, itrDriver, out_str1);
	PrintForOutput2(riders, itrRider, out_str2);

	}

 // // // // // // // // // // // // // // // // // // 

 // If the Driver is Canceling

	if (DriverCanceling == true)
	{
		if (itrDriver->getCurrentState() == "On_the_way_to_pickup")
		{

			//I need the loop to go through the rider data and find the right rider 
			itrRider = riders.begin();
			while (PhoneNumString != itrRider->getDriversPN())
			{
			itrRider++;
			}

			std::string OGDriverName = itrDriver->getFirstName();

			// Changes The Current Driver's State and Data
			itrDriver->setCurrentState("Holder");
			itrDriver->setRidersFN("null");
			itrDriver->setRidersLN("null");
			itrDriver->setRidersPN("null");
			

			// // // // // // // // // // // // // // // // // // 

 			// Finding Nearest Driver

			itrDriver = drivers.begin();
			int driverslistSize = drivers.size();
			std::string SelectedDriverName;
			std::string SelectedDriverNumber;
			double SelectedDriverRating;
			double SelectedDriverDistance = 999;
			double SelectedDriverComparision;
			for (int i = 0; i < driverslistSize; i++)
			{
				if (itrDriver->getCurrentState() == "Available" && itrRider->getVehicle_Pref() == itrDriver->getVehicleType())
				{
				
				SelectedDriverComparision = calculateDistance(itrRider->getLatitude_P_L(), itrRider->getLongitude_P_L(), itrDriver->getCurrent_Lat(), itrDriver->getCurrent_Lon());

					if (SelectedDriverDistance > SelectedDriverComparision)
					{
					SelectedDriverDistance = SelectedDriverComparision;
					SelectedDriverName = itrDriver->getFirstName();
					SelectedDriverRating = itrDriver->getRating();
					SelectedDriverNumber = itrDriver->getPhoneNumber();
					}

				}	
			itrDriver++;
			}
			if (SelectedDriverDistance == 999)
			{
			PrintForOutput0NoDriver(riders, itrRider, out_str0);
			exit(1);
			}

			itrDriver = drivers.begin();
			while (SelectedDriverNumber != itrDriver->getPhoneNumber())
			{
			itrDriver++;
			}


			// // // // // // // // // // // // // // // // // // 

			// Changing the Driver and Rider data for printiner

				itrDriver->setCurrentState("On_the_way_to_pickup");
				itrDriver->setRidersFN(itrRider->getFirstName());
				itrDriver->setRidersLN(itrRider->getLastName());
				itrDriver->setRidersPN(itrRider->getPhoneNumber());
				itrRider->setCurrentState("Driver_on_the_way");
				itrRider->setDriversFN(itrDriver->getFirstName());
				itrRider->setDriversLN(itrDriver->getLastName());
				itrRider->setDriversPN(itrDriver->getPhoneNumber());

				itrDriver = drivers.begin();
				while (itrDriver->getCurrentState() != "Holder")
				{
				itrDriver++;
				}
				itrDriver->setCurrentState("Available");

			// // // // // // // // // // // // // // // // // // 

			// Printing Output

				PrintForOutput0Cancel(riders, itrRider, OGDriverName, SelectedDriverName, SelectedDriverRating, SelectedDriverDistance, out_str0);
				PrintForOutput1(drivers, itrDriver, out_str1);
				PrintForOutput2(riders, itrRider, out_str2);

		}
		else
		{
		out_str0 << "You can only cancel a ride request if you are currently on the way to the pickup location." << std::endl;	
		exit(1);
		}
	}
}
else
{
out_str0 << "Not a given command, must be 'request' or 'cancel'." << std::endl;
exit(1);
}

return 0;
}

