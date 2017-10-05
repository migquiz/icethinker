//Automobile Exercise
//Write a class named automobile with the following
//attributes : manufacturer's name , model name and
//model year. Write a method or a function that will
//return a description of the automobile together
//it's age.

//Not Complete Program
//In the description method. It must return a string
//since the "+" is overloaded operator , it acts as
//a concatenator :D . the problem is to convert the
//year in int to string (char *) or char []. That is
//another support method. Multiply the modulo of year
//by 10 by 10 then add the result to a variable while
//modulo is not equal to zero.

#include <iostream>
using namespace std;

const int CURRENT_YEAR = 2017;

class Automobile {
private:
	string _manufacturer;
	string _model;
	int _model_year;
public:
	Automobile();
	~Automobile();
	Automobile(string manufacturer, string model, int model_year);
	string manufacturer();
	string model();
	int model_year();
	void set_Manufacturer(string _manufacturer);
	void set_Model(string _model);
	void set_Model_Year(int _model_year);
	string description();
	int age();
};

string Automobile::manufacturer() {
	return _manufacturer;
}

string Automobile::model() {
	return _model;
}

int Automobile::model_year() {
	return _model_year;
}

void Automobile::set_Manufacturer(string manufacturer) {
	_manufacturer = manufacturer;
}

void Automobile::set_Model(string model) {
	_model = model;
}

void Automobile::set_Model_Year(int model_year) {
	_model_year = model_year;
}

string Automobile::description() {
	return _model_year + " " + _manufacturer + " " + _model;
}

int Automobile::age() {
	return CURRENT_YEAR - _model_year;
}

Automobile::Automobile() {
	set_Manufacturer("Generic");
	set_Model("Generic");
	set_Model_Year(2017);
}

Automobile::Automobile(string manufacturer, string model, int model_year) {
	set_Manufacturer(manufacturer);
	set_Model(model);
	set_Model_Year(model_year);	
}

Automobile::~Automobile() {
	cout << "Destructor Activated" << endl;
}

int main (int argc, char ** argv) {
	Automobile miguel;
	cout << miguel.description() << endl;
	return 0;
}