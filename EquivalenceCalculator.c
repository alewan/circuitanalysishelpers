//Created by awan on March 19, 2016
//EquivalenceCalculator code in C for RLC circuits
#include <stdio.h>
#include <stdbool.h>

//Preprocessor definitions
#define USERPROMPT "Resistor (R), Capacitor (C), Inductor (I), or Default (D) (any other key to exit): "

int main (void) {
    char atype = 0, etype = 0; //arrangement type (Parallel or Series), element type (R, L, or C)
    int numInputs = 0;
    bool addInverse = false;
    
    //User Prompt
    printf("\n");
    printf(USERPROMPT); //Default: two parallel resistors
    scanf(" %c", &etype);
    
    //Main Action
    while ((etype =='R')||(etype =='C')||(etype =='I')||(etype=='D')) {
        //Determining whether to add inverse based on user input and number of values to read in
        if (etype == 'D') {
            addInverse = true;
            numInputs = 2;
        }
        else {
            printf("Parallel (P) or Series (S): ");
            scanf(" %c", &atype);
            
            if (((atype == 'S') && ((etype =='R')||(etype == 'I')))||((atype =='P')&&(etype=='C')))
                addInverse = false;
            else
                addInverse = true;
            
            printf("How many values: ");
            scanf("%d", &numInputs);
        }
        
        //Reading in values and providing appropriate output
        double value = 0, holder;
        printf("Enter values separated by spaces: ");
        for (int i = 0; i < numInputs; i++) {
            scanf("%lf", &holder);
	        value += ((addInverse)? 1/holder : holder);
        }
        printf("Final Value: %.8lf\n\n", ((addInverse)? 1/value : value));
        
        //User Prompt
        printf(USERPROMPT);
        scanf(" %c", &etype);
    } 
    
	return(0);
}
