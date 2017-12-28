//Created by A Wan on November 13, 2016
//A custom Complex class broadly similar to std::complex (was built while experimenting for another project)
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
	Complex(double, double, bool); //Constructor with a flag identifying if args are in STD form (flag) or polar form (!flag)
	~Complex();
	
	Complex operator+(const Complex& rhs) const;
	Complex operator-(const Complex& rhs) const;
	Complex operator*(const Complex& rhs) const;
	Complex operator/(const Complex& rhs) const;
	
	Complex& operator+=(const Complex&); //return type of assignment operator is Complex&
	Complex& operator-=(const Complex&);

	//Friend Functions
	//(I/O stream extraction and insertion operators)
	friend istream& operator>>(istream&, Complex&);
	friend ostream& operator<<(ostream&, const Complex&); //inserts: a+bi (|z|,arg{z})\n
};

istream& operator>>(istream&, const Complex&); //Note: sends prompts to std::cout
ostream& operator<<(ostream& out, const Complex& toPrint);

#endif
