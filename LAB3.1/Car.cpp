#include "Car.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

Car::Car() {
	brand = "";
	cylinders = 0;
	power = 0.0;
}
Car::Car(const string& brand, int cylinders, double power) {
	SetBrand(brand);
	SetCylinders(cylinders);
	SetPower(power);
}
Car::Car(const Car& other) {
	brand = other.brand;
	cylinders = other.cylinders;
	power = other.power;
}

string Car::GetBrand() const {
	return brand;
}
int Car::GetCylinders() const {
	return cylinders;
}
double Car::GetPower() const {
	return power;
}

void Car::SetBrand(const string& value) {
	if (!value.empty()) {
		brand = value;
	}
	else {
		cout << "Помилка: Некоректне значення потужності! Роботу завершено." << endl;
		exit(1);
	}
}
void Car::SetCylinders(int value) {
	if (value > 0) {
		cylinders = value;
	}
	else {
		cout << "Помилка: Некоректне значення потужності! Роботу завершено." << endl;
		exit(1);
	}
}
void Car::SetPower(double value) {
	if (value > 0) {
		power = value;
	}
	else {
		cout << "Помилка: Некоректне значення потужності! Роботу завершено." << endl;
		exit(1);
	}
}

Car::operator string() const {
	stringstream sout;
	sout << "(Марка: " << brand << ", Циліндри: " << cylinders << ", Потужність: " << power << ")";
	return sout.str();
}

ostream& operator<<(ostream& out, const Car& obj) {
	out << string(obj);
	return out;
}
istream& operator>>(istream& in, Car& obj) {
	string b;
	int c;
	double p;

	cout << "Введіть марку автомобіля: ";
	in >> b;
	cout << "Введіть кількість циліндрів: ";
	in >> c;
	cout << "Введіть потужність: ";
	in >> p;

	obj.SetBrand(b);
	obj.SetCylinders(c);
	obj.SetPower(p);

	return in;
}

void Car::ChangePower(double newPower) {
	SetPower(newPower);
}
void Car::ReassignBrand(const string& newBrand) {
	SetBrand(newBrand);
}