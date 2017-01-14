//Created by A Wan on December 21, 2016
//Include Statements
#include <iostream>
#include <iomanip>
#include "Complex.h" //Taking advantage of custom Complex class developed for another project

//Preprocessor definitions
#define PROMPT "Phasor Domain [AC] (P), Resistive (R), Capacitive (C), Inductive (I), or Default (D): "

//Read and add function that can handle inverting values (will continue reading values until EOF received and then return)
//Arguments: value (initially 1 because operator/ is likely defined for a generic class but an inverse might not be), addInverse
template <class genericType>
void readAddValues (genericType& value, bool addInverse) {
    //Initialization
    genericType holder;
    genericType inverseConst = value;
    value -= value;

    //Read until EOF, adjusting value
    while (!cin.eof()){
        cin>>holder;
        if (cin.fail()) {
            cin.clear();
            break; //Exiting if unable to read in without modifying value
        }
        value += ((addInverse)? inverseConst/holder : holder);
    }

    //Adjust value (if necessary) and return
    if (addInverse)
        value = inverseConst/value;
    return;
}

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
        addInverse = (((atype == 'P') && ((etype =='R')||(etype == 'I')||(etype == 'P')))||((atype =='S')&&(etype=='C')));
    }
    
    //Reading in values and printing result
    cout<<"Enter values separated by spaces, followed by EOF (CTRL+D) when done:  ";
    if (etype=='P') {
        cout << endl;
        Complex value = Complex(1,0);
        readAddValues(value,addInverse);
        cout<<"Final Value: "<<value<<endl<<endl;
    }
    else {
        double value = 1;
        readAddValues(value,addInverse);
        cout<<"Final Value: "<<value<<endl<<endl;
    }

	return(0);
}
