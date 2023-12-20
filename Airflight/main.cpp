#include <iostream>
#include "Flight.h"
using namespace std;

int main()
{
	size_t n;
	Flight* Flights = allFlights("flights.txt", n);
	printFlights(Flights, n);
	cout << "All companys: " << "Turkish Airlines, United, Airbus, Delta\n" << "Choose what you want :";
	std::string Company;
	getline(cin, Company);
	size_t newSize;
	Flight* certainCompanyFlights = certainParametrFlights(Flights, n, isCompany, Company, newSize);
	cout << "All flights of " << Company << ":\n";
	SortByFlightNumber(certainCompanyFlights, newSize);
	printFlights(certainCompanyFlights, newSize);
	cout << "Choose what city you want to visit: ";
	size_t newerSize;
	std::string City;
	getline(cin, City);
	Flight* certainCityFlights = certainParametrFlights(certainCompanyFlights, newSize, isCity, City, newerSize);
	cout << "So, your flights are: \n";
	printFlights(certainCityFlights, newerSize);
	writeFlight(certainCityFlights, newerSize, "Yourflights.txt");
	cout << "Check your files:";
	delete[] Flights;
	delete[] certainCompanyFlights;
	delete[] certainCityFlights;
	return 0;
}