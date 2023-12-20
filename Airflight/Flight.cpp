#include <iostream>
#include "Flight.h"
using namespace std;
Flight::Flight()
	:company_name(""), city_destination(""), flight_numb(0001)
{
}
Flight::Flight(const string& name, const string& destination, int flightnumb)
	:company_name(name), city_destination(destination), flight_numb(flightnumb)
{
}
Flight::Flight(const Flight& C)
	:company_name(C.company_name), city_destination(C.city_destination), flight_numb(C.flight_numb)
{
}
Flight::~Flight()
{
}
string Flight::getName() const
{
	return company_name;
}
string Flight::getDestCity() const
{
	return city_destination;
}
int Flight::getFlightNumb() const
{
	return flight_numb;
}
void Flight::setName(string& newName)
{
	company_name = newName;
}
void Flight::setDestCity(string& newDestCity)
{
	city_destination = newDestCity;
}
void Flight::setFlightNumb(int newFlightNumb)
{
	flight_numb = newFlightNumb;
}
void Flight::print() const
{
	std::cout << "Company: " << company_name
		<< ". Destination city: " << city_destination
		<< ". Number of flight: " << flight_numb << '\n';
}
void Flight::readFrom(std::istream& in)
{
	std::getline(in, company_name, '*');
	std::getline(in, city_destination, '*');
	in >> flight_numb;
}
void Flight::writeTo(std::ostream& out)const
{
	out << company_name << " * " << city_destination << " * " << flight_numb ;
}	
istream& operator>>(istream& in, Flight& C)
{
	C.readFrom(in);
	return in;
}
ostream& operator<<(ostream& out, const Flight& C)
{
	C.writeTo(out);
	return out;
}
Flight* allFlights(const std::string& fileName, size_t& AllFlights)
{
	std::ifstream fin(fileName);
	fin >> AllFlights;
	Flight* Flights = new Flight[AllFlights];
	for (size_t i = 0; i < AllFlights; ++i)
	{
		fin.get();
		fin >> Flights[i];
	}
	fin.close();
	return Flights;
}
void printFlights(Flight* flights, size_t n)
{
	for (size_t i = 0; i < n; ++i) {
		flights[i].print();
		
	}
	cout << endl;
}
Flight* certainParametrFlights(Flight* Flights, int n, bool (*predicate)(Flight*, const std::string&), const std::string& ourCompany, size_t& newSize)
{
	size_t count = 0;
	for (size_t i = 0; i < n; ++i) {
		if (predicate(&Flights[i], ourCompany)) {
			++count;
		}
	}
	newSize = count;
	Flight* CertainCompany = new Flight[count];
	count = 0;
	for (size_t i = 0; i < n; ++i) {
		if (predicate(&Flights[i], ourCompany)) {
			CertainCompany[count] = Flights[i];
			++count;
		}
	}
	return CertainCompany;
}
void writeFlight(Flight* Flight, size_t n, const std::string& fileName)
{
		std::ofstream fout(fileName);
		fout << n << '\n';
		for (size_t i = 0; i < n; ++i) {
			fout << Flight[i] << '\n';
		}
		fout.close();
}
void SortByFlightNumber(Flight* Flights, int n)
{
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < n - i - 1; ++j) {
				if (Flights[j].getFlightNumb() > Flights[j + 1].getFlightNumb()) {
					Flight temp = Flights[j];
					Flights[j] = Flights[j + 1];
					Flights[j + 1] = temp;
				}
			}
		}
}

bool isCompany(Flight* C, const std::string& ourCompany)
{
	return C->getName() == ourCompany;
}
bool isCity(Flight* C, const std::string& ourCity)
{
	return C->getDestCity() == ourCity;
}


