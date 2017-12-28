//Created by awan on September 28, 2016
#include <iostream>
using namespace std;

inline double calcWyeValue (double r1, double r2, double total) {
	return (r1*r2)/total;
}

int main (void) {
	double rab, rac, rbc, sum;
	cout << endl << "Enter the delta resistance values delimited with spaces (in order: Rab, Rac, Rbc): ";
	cin >> rab >> rac >> rbc;
	sum = rab+rac+rbc;
	cout << "wye resistance values (in order: R1, R2, R3): "
		<<calcWyeValue(rab,rac,sum)<<", "<<calcWyeValue(rab,rbc,sum)<<", "<<calcWyeValue(rbc,rac,sum)<<endl<<endl;
	return(0);
}
