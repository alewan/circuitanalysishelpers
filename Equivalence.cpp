//Created by A Wan on December 21, 2016
#include <iostream>
#include <iomanip>
#include "Complex.h" //Taking advantage of custom Complex class developed for another project

#define PROMPT "Phasor Domain [AC] (P), Resistive (R), Capacitive (C), Inductive (I), or Default (D): "

double readAddDoubleValues (bool);
Complex readAddComplexValues (bool);
//Could have also used dynamic binding to avoid duplicating code by replacing double/Complex with generic cct element
//and using inheritance, but this is simpler and will run infinitesimally faster (primarily via static bind)

int main (void) {
    char domain = 0, atype = 0, etype = 0; //Arrangement type, Element type
    bool addInverse = false;
    cout<<fixed<<setprecision(5)<<endl;
    
    cout<<"This program helps find equivalences of basic circuits."<<endl
        <<"Please choose a network type to analyze. (Default is two parallel resistors)"<<endl;
    cout<<PROMPT;
    cin >> etype;
    
    //Determining whether to add inverse based on user input and number of values to read in
    if (etype == 'D')
        addInverse = true;
    else {
        cout<<"Parallel (P) or Series (S): ";
        cin>>atype;
        addInverse = !(((atype == 'S') && ((etype =='R')||(etype == 'I')))||((atype =='P')&&(etype=='C')));
    }
    
    //Reading in values and send appropriate result to cout
    cout<<"Enter values separated by spaces (Use CTRL+D when done): ";
    if (etype=='P'){
        cout << endl;
        Complex value = readAddComplexValues(addInverse);
        cout<<"Final Value: "<<((addInverse)? value.inverse() : value)<<endl;
    }
    else {
        double value = readAddDoubleValues(addInverse);
        cout<<"Final Value: "<<((addInverse)? 1/value : value)<<endl;
    }

    cout<<endl;
	return(0);
}

double readAddDoubleValues (bool addInverse) {
    double value = 0, holder;
        while (!cin.eof()){
            cin>>holder;
            if (cin.fail()) {
                cin.clear();
                break;
            }
	        value += ((addInverse)? 1/holder : holder);
        }
    return value;
}

Complex readAddComplexValues (bool addInverse) {
    Complex value;
    Complex* holder;
        while (!cin.eof()){
            cin>>holder;
            if (cin.fail()) {
                cin.clear();
                break;
            }
            value += ((addInverse)? holder->inverse() : *holder);
            delete holder;
        }
    return value;
}
