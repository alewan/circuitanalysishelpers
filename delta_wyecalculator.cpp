#include <iostream>
using namespace std;
int main (void) {
	double rab, rac, rbc, r1, r2, r3, sum;
	cout << endl << "Enter the delta resistance values delimited with spaces (in order: Rab, Rac, Rbc): ";
	cin >> rab >> rac >> rbc;
	sum = rab+rac+rbc;
	r1 = (rab*rac)/sum;
	r2 = (rab*rbc)/sum;
	r3 = (rac*rbc)/sum;
	cout << "wye resistance values (in order: R1, R2, R3): "<<r1<<" "<<r2<<" "<<r3<<endl<<endl;
	return(0);
}
