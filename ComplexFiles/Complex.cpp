//Created by A Wan on November 13, 2016
#include "Complex.h"
#define DEGREES_TO_RADIANS M_PI/180
#define RADIANS_TO_DEGREES 180/M_PI

inline void polarSTDConversion (const double& mag, const double& angle, double& real, double& imag) {
	real = mag*cos(angle*(DEGREES_TO_RADIANS));
	imag = mag*sin(angle*(DEGREES_TO_RADIANS));
	return;
}

inline void STDPolarConversion(const double& real, const double& imag, double& mag, double& angle) {
	mag = sqrt(((real*real)+(imag*imag)));
	angle = atan(imag/real)*(RADIANS_TO_DEGREES);
	return;
}

Complex::Complex() {
	real=0;
	imaginary=0;
	magnitude=0;
	angle=0;
}

Complex::Complex(double value1, double value2) {
	real = value1;
	imaginary = value2;
	STDPolarConversion(real,imaginary,magnitude,angle);
}

Complex::Complex(double value1, double value2, bool stdform) {
	if (stdform) {
		real = value1;
		imaginary = value2;
		STDPolarConversion(value1,value2,magnitude,angle);
	}
	else {
		magnitude = value1;
		angle = value2;
		polarSTDConversion(value1,value2,real,imaginary);
	}
}

Complex::~Complex() {
	//Nothing to be done
}

Complex Complex::operator+(const Complex &rhs) const {
	return Complex(real+rhs.real, imaginary+rhs.imaginary);
}

Complex Complex::operator-(const Complex &rhs) const {
	return Complex(real-rhs.real, imaginary-rhs.imaginary);
}

Complex Complex::operator*(const Complex &rhs) const {
	return Complex((real*rhs.real + ((-1)*imaginary*rhs.imaginary)), (real*rhs.imaginary + rhs.real*imaginary));
}

Complex Complex::operator/(const Complex &rhs) const {
	return Complex(((real*rhs.real + imaginary*rhs.imaginary)/(rhs.real*rhs.real + rhs.imaginary*rhs.imaginary)), ((imaginary*rhs.real - rhs.imaginary*real)/(rhs.real*rhs.real + rhs.imaginary*rhs.imaginary)));
}

ostream& operator<<(ostream& out, const Complex& outVal) {
	char sign = ((outVal.imaginary >= 0) ? '+' : 0);
	out<<outVal.real<<sign<<outVal.imaginary<<"i"<<" ("<<outVal.magnitude<<","<<outVal.angle<<")"<<endl;
	return out;
}