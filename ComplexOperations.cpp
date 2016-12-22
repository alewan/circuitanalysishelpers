//Created by A Wan on November 13, 2016
#include "Complex.h"

int main (void) {
	cout<<fixed<<setprecision(5);
	Complex* value1 = NULL;
	Complex* value2 = NULL;
	
	cin>>value1>>value2;
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
