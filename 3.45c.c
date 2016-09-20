//e^x Calculator
//Problem 3.45c
//By: Aviral Kukreja
//06/16/16
#include <stdio.h>

//Function main begins program execution
int main(void)
{
    float e;//This number holds the value of e with the given exponent in decimal form
    int exponent;//First number entered by user
    int exponent2;//This number holds the samae value as exponent in order to continue the power of the exponent in equilibream with the counter
    int counter;//Number of times to perform the given calculation
    int denominator;//This number holds the value of the factorial which is the part of the denominator to calulate e
    
    printf("Enter a number for the exponent of e\n");//Prompts to enter an exponent for e
    scanf("%d", &exponent);//Reads exponent
    
    //Initialization phase
    counter=1;//initialize loop counter
    e=1;//initialize e value
    denominator=1;//initialize denominator value
    exponent2=exponent;//initialize exponent2 value
    
    while (counter<=10) {//loop 10 times
        e=(float) exponent/denominator+e;//Calculates e with the exponent
        counter=counter+1;//increments counter
        denominator=counter*denominator;//Calculates the factorial which is part of the denominator to calculate e
        exponent=exponent*exponent2;//Prepares the total before the continuation or termination of the calcuation
       
}//ends while
    
    printf("Your value is %f\n", e);//Output the value of e with the given exponent

}//ends function main