#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Flight
{
private:
	string company_name;
	string city_destination;
	int flight_numb;

public:
	Flight();
	Flight(const string& name, const string& destination, int flightnumb);
	Flight(const Flight& C);
	~Flight();
	string getName() const;
	string getDestCity() const;
	int getFlightNumb() const;
	void setName(string& newName);
	void setDestCity(string& newDestCity);
	void setFlightNumb(int newFlightNumb);
	void print() const;
	void readFrom(std::istream& in);
	void writeTo(std::ostream& out)const;
};
istream& operator >> (istream& in, Flight& C);
ostream& operator << (ostream& out, const Flight& C);
Flight* allFlights(const std::string& fileName, size_t& AllFlights);
void printFlights(Flight* flights, size_t n);
bool isCompany(Flight* C, const std::string& ourName);
bool isCity(Flight* C, const std::string& ourCity);
Flight* certainParametrFlights(Flight* Flights, int n, bool (*predicate)(Flight*, const std::string&), const std::string& ourParametr, size_t& newSize);
void writeFlight(Flight* Garden, size_t n, const std::string& fileName);
void SortByFlightNumber(Flight* Flights, int n);
	
	