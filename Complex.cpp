//Created by A Wan on November 13, 2016
#include "Complex.h"

inline void polarSTDConversion (const double& mag, const double& angle, double& real, double& imag) {
	real = mag*cos(angle*(DEGREES_TO_RADIANS));
	imag = mag*sin(angle*(DEGREES_TO_RADIANS));
	return;
}

Complex::Complex() {
	real=0;
	imaginary=0;
}

Complex::Complex(double value1, double value2) {
	real = value1;
	imaginary = value2;
}

Complex::Complex(double value1, double value2, bool stdform) {
	if (stdform) {
		real = value1;
		imaginary = value2;
	}
	else {
		polarSTDConversion(value1,value2,real,imaginary);
	}
}

Complex::~Complex() {
	//Nothing to be done
}

Complex Complex::operator+(const Complex& rhs) const {
	return Complex(real+rhs.real, imaginary+rhs.imaginary);
}

Complex Complex::operator-(const Complex& rhs) const {
	return Complex(real-rhs.real, imaginary-rhs.imaginary);
}

Complex Complex::operator*(const Complex& rhs) const {
	return Complex((real*rhs.real + ((-1)*imaginary*rhs.imaginary)), (real*rhs.imaginary + rhs.real*imaginary));
}

Complex Complex::operator/(const Complex& rhs) const {
	return Complex(((real*rhs.real + imaginary*rhs.imaginary)/(rhs.real*rhs.real + rhs.imaginary*rhs.imaginary)), ((imaginary*rhs.real - rhs.imaginary*real)/(rhs.real*rhs.real + rhs.imaginary*rhs.imaginary)));
}

Complex& Complex::operator+=(const Complex& rhs){
	real += rhs.real;
	imaginary += rhs.imaginary;
	return (*this);
}

Complex& Complex::operator-=(const Complex& rhs){
	real -= rhs.real;
	imaginary -= rhs.imaginary;
	return (*this);
}

double Complex::getMagnitude() const {
	return sqrt(((real*real)+(imaginary*imaginary)));
}

double Complex::getAngle() const {
	return atan(imaginary/real)*(RADIANS_TO_DEGREES);
}

istream& operator>>(istream& in, Complex& inVal) {
	int type;
	double temp1,temp2;

	cout << "Enter input type (1 for standard form, 2 for polar form): ";
	in >> type;
	
	if (type == 1) {
		cout << "Enter complex number (as Re{z} Im{z}): ";
		in >> temp1 >> temp2;
		inVal = Complex(temp1,temp2);
	}
	else if (type == 2) {
		cout << "Enter complex number (as |z| arg{z} (in degrees)): ";
		in >> temp1 >> temp2;
		inVal = Complex(temp1,temp2,false);
	}
	else {
		cerr << "Could not read appropriate type. Initializing with default constructor." << endl;
		inVal = Complex();
	}
	
	cout<<endl<<endl;
	return in;
}

ostream& operator<<(ostream& out, const Complex& outVal) {
	char sign = ((outVal.imaginary >= 0) ? '+' : 0); //Note: If it is negative, this sets the char to 0 not '0' (only '-' appears)
	out<<outVal.real<<sign<<outVal.imaginary<<"i"<<" ("<<outVal.getMagnitude()<<","<<outVal.getAngle()<<")"<<endl;
	return out;
}

