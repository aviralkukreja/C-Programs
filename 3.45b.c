//Value of e
//Problem 3.45b
//By: Aviral Kukreja
//06/16/16
#include <stdio.h>

//Function main begins program execution
int main(void)
{
    float e;//This number holds the value of e in decimal values
    int denominator;//This number holds the value of the ++incrementing factorial
    unsigned int counter;//Number of times to perform the calculation
    
    //Initialization phase
    counter=1;//Initialize loop counter
    e=1;//Initialize e value
    denominator=1;//Initialize denominator value
    
    while (counter<=10) {//loop 10 times
        e=(float) 1/denominator+e;//Calculate e using the factorial given by counter
        counter=counter+1;//increment counter
        denominator=counter*denominator;//Prepare the total before multiplying a new factorial fraction
    }//end while
    
    
    printf("e is equal to %f\n", e);//Outputs the value of e
}//end function main
