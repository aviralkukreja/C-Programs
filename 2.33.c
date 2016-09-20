//Carpool Savings Calculator
//Problem 2.33
//By: Aviral Kukreja
//06/15/16
#include <stdio.h>

//Function main begins program execution
int main(void)
{
    int integer1;//First number to be entered by user
    int integer2;//Second number to be entered by user
    int integer3;//Third number to be entered by user
    int integer4;//This number holds the value of the capacity of gas for ones veichle
    int integer5;//This number holds the value of the amount of money spent on gasoline per day
    int integer6;//Fourth number to be entered by user
    int integer7;//Fifth number to be entered by user
    int sum;//This number holds the value of the sum of the amount of money spent on a daily commute
    int quotient;//This number holds the value of the amount of money saved when carpooling
    
    printf("Enter the total number of miles you drive per day\n");//Prompts to enter miles driven per day
    scanf("%d", &integer1);//Reads integer1
    
    printf("Enter the cost per gallon on gasoline\n");//Prompts to enter the cost of gasoline per mile
    scanf("%d", &integer2);//Reads integer2
    
    printf("Enter the average miles per gallon on your veichle\n");//Prompts to enter the care milage
    scanf("%d", &integer3);//Reads integer3
    
    integer4 = integer1 / integer3;//Calculates the number of gallons of gas ones car holds
    
    integer5 = integer4 * integer2;//Calulates the amount of money spent on purchasing gasoline per day
    
    printf("Enter the amount of money you spend on parking fees per day\n");//Prompts to enter dollars spent on parking per day
    scanf("%d", &integer6);//Reads integer6
    
    printf("Enter the amount of money you spend on tolls per day\n");//Prompts to enter dollars spent on tolls per day
    scanf("%d", &integer7);//Reads integer7
    
    sum = integer5 + integer6 + integer7;//Calulates the amount of money spent on ones commute
    
    quotient= sum / 2;//Calculates the amount of money saved when carpooling
    
    printf("You spend around %d dollars on your commute per day\n", sum);//Prints the amount of money spent on ones commute by themselves
    printf("You can save around %d dollars per day once you start carpooling\n", quotient);//Prints the amount of money spent on ones commute when carpooling
    
}//end function main