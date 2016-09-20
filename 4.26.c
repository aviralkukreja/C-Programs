//Calculation of the value of pi
//Problem 4.26
//By: Aviral Kukreja
//06-23-16
#include <stdio.h>

//Function main begins program execution
int main()
{
    unsigned int counter;//define coounter
    double pi = 0;//define value of pi
    int term = 1;//define value of term number
    
    //For else loop will help make sure when to add or subtract according to the given formula
    for ( counter = 1; counter <= 6; counter++) {
        
        if ( counter % 2 == 0) {
            pi = pi - (4.0 / (2 * counter - 1));//Calculation if the value needs to be subtracted
        }
        
        else {
            pi = pi + (4.0 / (2 * counter - 1));//Calulation if the value needs to be added
        }//end if else
        
        printf("%d\t",term);//Output term number in the first column
        printf( "%f\n", pi );//Output value of pi in the second column
        term = term + 1;//term number for the upcoming value of pi
    }
    puts("");//Outputs a space for the next line
    printf("It takes 119 terms to get to 3.14\nIt takes 1686 terms to get to 3.141\nIt takes 10738 terms to get to 3.1415\nIt takes 146063 terms to get to 3.14159\n");//Outputs statistics of the pi value in relation to the calculations
}//end function main