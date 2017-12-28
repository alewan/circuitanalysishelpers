//Created by A Wan on November 13, 2016
//Perform basic operations using the Complex class (for test)
#include "Complex.h"
#include <iostream>

int main (void) {
	cout<<fixed<<setprecision(5); //constant precision of 5 decimal places
	Complex value1, value2;
	
	cin>>value1>>value2;
	cout<<"First value read: "<<value1<<"Second value read: "<<value2<<endl;

	cout<<"Addition Result: "<<(value1+value2);
	cout<<"Subtraction Result: "<<(value1-value2);
	cout<<"Multiplication Result: "<<(value1*value2);
	cout<<"Division Result: "<<(value1/value2);
	cout<<endl;
	
	return(0);
}
