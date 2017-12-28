//Created by A Wan on December 21, 2016
//A program to calculate equivalent resistance/capacitance/inductance values for basic circuits

//Include Statements
#include <iostream>
#include <iomanip>
#include "Complex.h" //Using a custom Complex class

//Preprocessor definitions
#define PROGDESCRIPTION "This program helps find equivalences for basic circuits."
#define PROMPT "Please choose a network type to analyze. (Default is two parallel resistors)"
#define CHOICES "Phasor Domain [AC] (P), Resistive (R), Capacitive (C), Inductive (I), or Default (D): "

//Templated Helper Function (Prototypes)
template <class T>
bool readin (T& temp);
template <class T>
void readAddValues (T& result);

//General Helper Function (Prototypes)
void readAddInverseValues (double& result);
void readAddInverseValues (Complex& result);

//Main Function
int main (void) {
    //Initialization of variables and configuring cout
    char domain = 0, atype = 0, etype = 0; //Arrangement type, Element type
    bool addInverse = false;
    cout<<fixed<<setprecision(5)<<endl; //constant precision of 5 decimal places
    
    //Initial Prompt (no input validation)
    cout<< PROGDESCRIPTION <<endl;
    cout<< PROMPT << endl <<CHOICES;
    cin >> etype;
    
    //Determining whether to add inverse based on user input and number of values to read in
    if (etype == 'D') {
        addInverse = true;
    }        
    else {
        cout<<"Parallel (P) or Series (S): ";
        cin>>atype;
        addInverse = (((atype == 'P') && ((etype =='R')||(etype == 'I')||(etype == 'P')))||((atype =='S')&&(etype=='C')));
    }
    
    //Reading in values and printing result (improper input is caught, but just leads to the reading stopping silently)
    cout<<"Enter the values separated by spaces, followed by 'X' when done:  "; //readin will catch X as in invalid input
    if (etype=='P') {
        Complex value; //default constructor initializes to 0+0i
        addInverse ? readAddInverseValues(value) : readAddValues(value);
        cout<<"Final Value: "<<value<<endl<<endl;
    }
    else {
        double value = 0;
        addInverse ? readAddInverseValues(value) : readAddValues(value);
        cout<<"Final Value: "<<value<<endl<<endl;
    }

	return(0);
}

//Helper Functions
//Read a value from std input (std::cin) and check for EOF or success
template <class T>
bool readin (T& temp) {
    if (cin.eof())
        return false;
    cin >> temp;
    if (cin.fail()) {
        cin.clear();
        return false;
    }
    return true;
}

//'Read and Add' Helper Functions
//Read and add function, reads and adds to result (will continue reading values until done and then return)
template <class T>
void readAddValues (T& result) {
    T temp;
    while (readin(temp))
        result += temp;

    return;
}

//Overloaded read and add inverse values for double, complex (simpler and less overhead than creating a workaround for 1/Complex())
void readAddInverseValues (double& result) {
    double temp = 0;
    while (readin(temp)) {
        result += 1/temp; //invert values as they are read in
    }
    result = 1/result; //finally, invert the final result
    return;
}
void readAddInverseValues (Complex& result) {
    Complex temp;
    Complex inverseConstant = Complex(1,0);
    while (readin(temp)){ 
        result += inverseConstant/temp; //invert values as they are read in
    }
    result = inverseConstant/result; //finally, invert the final result
    return;
}
