//Factorial Calculator
//Problem 3.45a
//By: Aviral Kukreja
//06/16/16
#include <stdio.h>//Function allows the use of imput and output function

//Function main begins program execution
int main(void)
{
    int number;//First number to be entered by user
    int total;//This number holds the value of the factorial
    
    printf("Enter a nonnegative integer that you need to find the factorial of\n");//Prompt to enter a number that wants a factorial answer
    scanf("%d", &number);//Reads number
    
    //Initialization phase
    total=1;//initialize total
  

    while (number>=2) {//Loop until the whole factorial is calulated
        total=number*(number-1)*total;//Calculates the total of the factorial multiplication
        number = number-2;//Calculation that prepares the next pair of numbers to be calculated for the factorial
        }
    
    printf("The factorial is %d\n", total);//Outputs the factorial from the given number
}//end function main

