//Recursive Exponentiation
//Problem 5.34
//By: Aviral Kukreja
//7-5-16
#include <stdio.h>

int power(int n1,int n2);
int main()//Function main begins program execution
{
    int base, exp;//Define integer base and exp(exponent)
    printf("Enter base number: ");//Outputs the given statement
    scanf("%d",&base);//Reads base
    printf("Enter power number(positive integer): ");//Outputs the given statement
    scanf("%d",&exp);//Reads exp(exponent)
    printf("%d^%d = %d\n", base, exp, power(base, exp));//Outputs the equation with the answer
    return 0;//Check program
}//end function main

//Function power definition
int power(int base,int exp)
{
    if ( exp!=1 )//If exponent is not equal to 1
        return (base*power(base,exp-1));//Calulation to find the answer of the power
    
    return base;//Calculate base and return result
    
}//end function power