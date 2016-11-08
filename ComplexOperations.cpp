#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void polarSTDConversion (const double& mag, const double& angle, double& real, double& imag) {
	real = mag*cos(angle*M_PI/180);
	imag = mag*sin(angle*M_PI/180);
	char sign = ((imag >= 0) ? '+' : 0);
	cout << "Converted Value: "<<real<<sign<<imag<<"i"<<endl;
	return;
}

int main (void) {
	cout<<fixed<<setprecision(8);
	bool validInput;
	int inputtype;
	double re1, im1, re2, im2;
	
	do {
		validInput = true;
		cout << "Enter type (1 for standard form, 2 for polar form): ";
		cin >> inputtype;
		
		if(inputtype == 1) {
			cout << "Enter first complex number (as Re{z1} Im{z1}): ";
			cin >> re1 >> im1;
			cout << "Enter second complex number (as Re{z2} Im{z2}): ";
			cin >> re2 >> im2;
		}
		else if (inputtype == 2) {
			double temp1, temp2;
			cout << "Enter first complex number (as |z1| angle(z1)): ";
			cin >> temp1 >> temp2;
			polarSTDConversion(temp1, temp2, re1, im1);
			cout << "Enter second complex number (as |z2| angle(z2)): ";
			cin >> temp1 >> temp2;
			polarSTDConversion(temp1, temp2, re2, im2);
		}
		else {
			validInput = false;
			cout << "Error, you gave "<<invalidValue<<" as input. Please retry and enter either 1 or 2."<<endl<<endl;
		}
	} while (!validInput);

	double resultre, resultim;
	char sign;

	resultre = re1+re2;
	resultim = im1+im2;
	sign = ((resultim >= 0) ? '+' : 0);
	cout <<endl<<"Addition Result: "<<resultre<<sign<<resultim<<"i";
	
	resultre = re1-re2;
	resultim = im1-im2;
	sign = ((resultim >= 0) ? '+' : 0);
	cout <<endl<<"Subtraction Result: "<<resultre<<sign<<resultim<<"i";

	resultre = re1*re2 + ((-1)*im1*im2);
	resultim = re1*im2 + re2*im1;
	sign = ((resultim >= 0) ? '+' : 0);
	cout <<endl<<"Multiplication Result: "<<resultre<<sign<<resultim<<"i";

	resultre = (re1*re2 + im1*im2)/(re2*re2 + im2*im2);
	resultim = (im1*re2 - im2*re1)/(re2*re2 + im2*im2);
	sign = ((resultim >= 0) ? '+' : 0);
	cout <<endl<<"Division Result: "<<resultre<<sign<<resultim<<"i";

	cout<<endl<<endl;
	return(0);
}
