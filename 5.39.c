//Recursive Greateset Common Denominator
//Problem 5.39
//By: Aviral Kukreja
//7-5-16
#include <stdio.h>

int gcd(int, int);//Function prototype
int main(void)//Function main begins program execution
{
    int a, b, result;//Feine integer a, b, and result
    
    printf("Enter the two numbers to find the GCD ");//Ouput the following statement
    scanf("%d%d", &a, &b);//Read integer a and b
    
    result=gcd(a,b);
    
    printf("The GCD of %d and %d is %d\n", a,b,result);//Print the two given numbers with its answer
}//end function main

int gcd(int a, int b)//Function GCD definition
{
    while (a != b)//while a is not equal to b
    {
        if (a>b) {//if a > b
            return gcd(a-b, b);//Calulate GCD using this formula and return result
        }//end if
        else {
            return gcd(a, b-a);//Calculate GCD using this formula and return result
        }//end else
    }//end while
    return a;//Calculate a and return result
}//end function GCD