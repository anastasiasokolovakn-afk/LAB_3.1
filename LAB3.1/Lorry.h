#pragma once
#include "Car.h"

using namespace std;

class Lorry : public Car
{
private:
	double capacity = 0.0;
public:
	Lorry();
	Lorry(const string& brand, int cylinders, double power, double capacity);
	Lorry(const Lorry& other);

	double GetCapacity() const;
	void SetCapacity(double value);

	operator string() const;

	friend ostream& operator<<(ostream& out, const Lorry& obj);
	friend istream& operator>>(istream& in, Lorry& obj);

	void ReassignBrand(const string& newBrand);
	void ChangeCapacity(double newCapacity);
};

