//Created by A Wan on November 13, 2016
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

inline void polarSTDConversion (const double& mag, const double& angle, double& real, double& imag);
inline void STDPolarConversion(const double& real, const double& imag, double& mag, double& angle);

class Complex {
private:
	double real;
	double imaginary;
	double magnitude;
	double angle;

public:
	Complex();
	Complex(double, double);
	Complex(double, double, bool);
	~Complex();

	Complex operator+(const Complex&rhs) const;
	Complex operator-(const Complex&rhs) const;
	Complex operator*(const Complex&rhs) const;
	Complex operator/(const Complex&rhs) const;

	friend ostream& operator<<(ostream&, const Complex&);
};

ostream& operator<<(ostream& out, const Complex& toPrint);

#endif
