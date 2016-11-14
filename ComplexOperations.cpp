//Created by A Wan on November 5, 2016
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define RADIANS_TO_DEGREES M_PI/180

inline void polarSTDConversion (const double& mag, const double& angle, double& real, double& imag) {
	real = mag*cos(angle*(RADIANS_TO_DEGREES));
	imag = mag*sin(angle*(RADIANS_TO_DEGREES));
	return;
}

void printResult (const char* operation, const double& real, const double& imag) {
	double mag, angle;
	char sign = ((imag >= 0) ? '+' : 0);
	STDPolarConversion(real,imag,mag,angle);
	cout<<operation<<" Result:"<<real<<sign<<imag<<"i"<<" ("<<mag<<","<<angle<<")"<<endl;
	return;
}

int main (void) {
	cout<<fixed<<setprecision(5);
	bool validInput;
	int inputtype;
	double re1, im1, re2, im2;
	
	do {
		cout << "Enter type (1 for standard form, 2 for polar form): ";
		cin >> inputtype;
		
		if(inputtype == 1) {
			validInput = true;
			cout << "Enter first complex number (as Re{z1} Im{z1}): ";
			cin >> re1 >> im1;
			cout << "Enter second complex number (as Re{z2} Im{z2}): ";
			cin >> re2 >> im2;
		}
		else if (inputtype == 2) {
			validInput = true;
			double temp1, temp2;
			char sign;

			cout << "Enter first complex number (as |z1| arg{z1} (in degrees)): ";
			cin >> temp1 >> temp2;
			polarSTDConversion(temp1, temp2, re1, im1);
			sign = ((imag >= 0) ? '+' : 0);
			cout << "Converted Value: "<<re1<<sign<<im1<<"i"<<endl;

			cout << "Enter second complex number (as |z2| arg{z2} (in degrees)): ";
			cin >> temp1 >> temp2;
			polarSTDConversion(temp1, temp2, re2, im2);
			sign = ((imag >= 0) ? '+' : 0);
			cout << "Converted Value: "<<re2<<sign<<im2<<"i"<<endl;
		}
		else {
			validInput = false;
			cout << "Error, you gave "<<inputtype<<" as input. Please retry and enter either 1 or 2."<<endl;
		}

		cout << endl;
	} while (!validInput);

	double resultre, resultim;

	resultre = re1+re2;
	resultim = im1+im2;
	printResult("Addition",resultre,resultim);
	
	resultre = re1-re2;
	resultim = im1-im2;
	printResult("Subtraction",resultre,resultim);

	resultre = re1*re2 + ((-1)*im1*im2);
	resultim = re1*im2 + re2*im1;
	printResult("Multiplication",resultre,resultim);

	resultre = (re1*re2 + im1*im2)/(re2*re2 + im2*im2);
	resultim = (im1*re2 - im2*re1)/(re2*re2 + im2*im2);
	printResult("Division",resultre,resultim);

	cout<<endl<<endl;
	return(0);
}
