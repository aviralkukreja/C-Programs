//Fibonacci Series
//Problem 5.35
//By: Aviral Kukreja
//7-5-16
#include<stdio.h>


double fib(int n);//Function prototype
int main(void)//Function main begins program execution
{
    int i;//define i
    
    for(i = 0;i <= 100;++ i)//For loop for the fibonacci series
    {
        printf("%1.0f \n",fib(i));//Output the numbers in the series
    }
    
    puts("The largest number that can be outputed is 130698922376339873754511593703999304853661815941920982715896371280424691495866567130509827216117625177952738381240755518030797439683443697785696230802473309617042775347304891963181519627287463521203531259388682404883801028462229399345567884825464934136563115441584430300333788777345438315116223032518554681344");//Output the largest number that can be outputed
    
    return 0;//Check program
    
}//end function main

//non recursive fibonacci function
double fib(int n)
{
    //Defined integers
    double prev = -1;
    double result = 1;
    double sum;
    int i;
    
    for(i = 0;i <= n;++ i)//For loop to find the values in the series
    {
        //Calulations used to find the numbers in the series
        sum = result + prev;
        prev = result;
        result = sum;
    }
    
    return result;//Calculate result and return it
}