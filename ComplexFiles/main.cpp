//Created by A Wan on November 13, 2016
#include "Complex.h"

int main (void) {
	cout<<fixed<<setprecision(5);
	bool validInput;
	Complex* value1 = NULL;
	Complex* value2 = NULL;
	
	do {
		int type;
		double temp1,temp2;

		cout << "Enter input type (1 for standard form, 2 for polar form): ";
		cin >> type;
		
		if (type == 1) {
			validInput = true;
			cout << "Enter first complex number (as Re{z1} Im{z1}): ";
			cin >> temp1 >> temp2;
			value1 = new Complex(temp1,temp2);
			
			cout << "Enter second complex number (as Re{z2} Im{z2}): ";
			cin >> temp1 >> temp2;
			value2 = new Complex(temp1,temp2);
		}
		else if (type == 2) {
			validInput = true;
			cout << "Enter first complex number (as |z1| arg{z1} (in degrees)): ";
			cin >> temp1 >> temp2;
			value1 = new Complex(temp1,temp2,false);

			cout << "Enter second complex number (as |z2| arg{z2} (in degrees)): ";
			cin >> temp1 >> temp2;
			value2 = new Complex(temp1,temp2,false);
		}
		else {
			validInput = false;
			cout << "Error, you gave "<<type<<" as input. Please retry and enter either 1 or 2."<<endl;
		}
		
		cout<<endl;
	} while (!validInput);

	cout<<"First value read: "<<(*value1)<<"Second value read: "<<(*value2)<<endl;

	cout<<"Addition Result: "<<((*value1)+(*value2));
	cout<<"Subtraction Result: "<<((*value1)-(*value2));
	cout<<"Multiplication Result: "<<((*value1)*(*value2));
	cout<<"Division Result: "<<((*value1)/(*value2));
	cout<<endl;

	delete value1;
	delete value2;
	return(0);
}
