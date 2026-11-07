#include "Lorry.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

Lorry::Lorry() : Car() {
	capacity = 0.0;
}
Lorry::Lorry(const string& brand, int cylinders, double power, double capacity) : Car(brand, cylinders, power) {
	SetCapacity(capacity);
}
Lorry::Lorry(const Lorry& other) : Car(other) {
	capacity = other.capacity;
}

double Lorry::GetCapacity() const {
	return capacity;
}

void Lorry::SetCapacity(double value) {
	if (value > 0) {
		capacity = value;
	}
	else {
		cout << "Помилка: Некоректне значення вантажопідйомності! Роботу завершено." << endl;
		exit(1);
	}
}

Lorry::operator string() const {
	stringstream sout;
	sout << "Вантажівка: " << Car::operator string() << ", Вантажопідйомність: " << capacity << " т";
	return sout.str();
}

ostream& operator<<(ostream& out, const Lorry& obj) {
	out << string(obj);
	return out;
}

istream& operator>>(istream& in, Lorry& obj) {
	cout << "--- Введення даних вантажівки ---" << endl;
	in >> (Car&)obj;
	double cap;
	cout << "Введіть вантажопідйомність: ";
	in >> cap;
	obj.SetCapacity(cap);
	return in;
}
void Lorry::ReassignBrand(const string& newBrand) {
	SetBrand(newBrand);
}
void Lorry::ChangeCapacity(double newCapacity) {
	SetCapacity(newCapacity);
}