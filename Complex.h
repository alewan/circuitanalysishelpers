//Created by A Wan on November 13, 2016
//A custom Complex class broadly similar to std::complex (was built while experimenting for another project)
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Pre-processor definitions
#define DEGREES_TO_RADIANS M_PI/180
#define RADIANS_TO_DEGREES 180/M_PI

//Helper function to convert from polar to STD form
inline void polarSTDConversion (const double& mag, const double& angle, double& real, double& imag);

//Complex Class
class Complex {
private:
	double real;
	double imaginary;
	
	double getMagnitude() const;
	double getAngle() const;

public:
	Complex();
	Complex(double, double);
	Complex(double, double, bool); //Constructor with a flag identifying if args are in STD form (flag) or polar form (!flag)
	~Complex();
	
	Complex operator+(const Complex& rhs) const;
	Complex operator-(const Complex& rhs) const;
	Complex operator*(const Complex& rhs) const;
	Complex operator/(const Complex& rhs) const;
	
	Complex& operator+=(const Complex&); //return type of assignment operator is Complex&
	Complex& operator-=(const Complex&);

	//Friend Functions (allows extraction and insertion operators to work without accessors)
	friend istream& operator>>(istream&, Complex&);
	friend ostream& operator<<(ostream&, const Complex&); 
};

//Prototypes for insertion and extraction operators
istream& operator>>(istream&, const Complex&); //Note: sends prompts to std::cout and std::cerr
ostream& operator<<(ostream& out, const Complex& toPrint); //inserts: a+bi (|z|,arg{z})\n

#endif
