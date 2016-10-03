//Created on March 19, 2016
#include <stdio.h>
#include <stdbool.h>

int main (void) {
    char atype = 0, etype = 0;
    int number;
    bool addInverse = false;
    
    //User Prompt
    printf("\nResistor (R), Capacitor (C), Inductor (I), or Default (D) (any other key to exit): "); //Default: two parallel resistors
    scanf(" %c", &etype);
    
    //Main Action
    while ((etype =='R')||(etype =='C')||(etype =='I')||(etype=='D')) {
        //Determining whether to add inverse based on user input and number of values to read in
        if (etype == 'D') {
            addInverse = true;
            number = 2;
        }
        else {
            printf("Parallel (P) or Series (S): ");
            scanf(" %c", &atype);
            
            if (((atype == 'S') && ((etype =='R')||(etype == 'I')))||((atype =='P')&&(etype=='C')))
                addInverse = false;
            else
                addInverse = true;
            
            printf("How many values: ");
            scanf("%d", &number);
        }
        
        //Reading in values and providing appropriate output
        double value = 0, holder;
        printf("Enter values separated by spaces: ");
        for (int i = 0; i < number; i++)
        {
            scanf("%lf", &holder);
	        value += ((addInverse)? 1/holder : holder);
        }
        printf("Final Value: %.8lf\n\n", ((addInverse)? 1/value : value));
        
        //User Prompt
        printf("Resistor (R), Capacitor (C), Inductor (I), or Default (D) (any other key to exit): ");
        scanf(" %c", &etype);
    } 
    
	return(0);
}
