//Created by A Wan on December 21, 2016
//Include Statements
#include <iostream>
#include <iomanip>
#include "Complex.h" //Taking advantage of custom Complex class developed for another project

//Preprocessor definitions
#define PROMPT "Phasor Domain [AC] (P), Resistive (R), Capacitive (C), Inductive (I), or Default (D): "

//Function prototypes
double readAddDoubleValues (bool);
Complex readAddComplexValues (bool);
//Could use many tactics (e.g. templating) to avoid writing duplicate code, but for this small program this is a simpler approach

//Main Function
int main (void) {
    //Initialization of variables and configuring cout
    char domain = 0, atype = 0, etype = 0; //Arrangement type, Element type
    bool addInverse = false;
    cout<<fixed<<setprecision(5)<<endl;
    
    //Initial Prompt
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

//Function to read in double values until EOF received and return the appropriate result
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

//Function to read in Complex values until EOF received and return the appropriate result
Complex readAddComplexValues (bool addInverse) {
    Complex value;
    Complex* holder;
        while (!cin.eof()){
            cin>>holder; //Note: the extraction operator dynamically allocates Complex object and reads values to it (necessitating delete later)
            if (cin.fail()) {
                cin.clear();
                break;
            }
            value += ((addInverse)? holder->inverse() : *holder);
            delete holder;
        }
    return value;
}
