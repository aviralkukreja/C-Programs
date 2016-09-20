//World Population Growth
//Problem 4.39
//By: Aviral Kukreja
//6-22-16
#include <stdio.h>

//Function main begins program execution
int main(void)
{
    int columns;//define column
    int rows;//define row
    int year;//This integer holds the value of the year
    long int population;//This integer holds the population or expected population for that year
    float growthrate;//This number holds the valuse of the constant growth rate
    long int growthnumber;//This integer holds the value of the increase of population between the given year and the previous year
    
    year=2016;//Current year
    population=7434000000;//Current population
    growthrate=.0113;//Current growth rate
    
    //For loop allows the output of a table
    for(rows=1; rows<=25; rows++){
        
        //Nested for loop allows the output of columns of the table
        for (columns=1; columns<=3; columns++) {
            
            
            printf("%d ",year);//Outputs year in 1st column
            printf("%ld ",population);//Ouputs population in 2nd column
            printf("%ld",growthnumber);//Ouputs growth number in the 3rd columns
            printf("\n");//Ouputs space for next row
            
            year=year+1;//Add year for the next row
            growthnumber=(float)growthrate*population;//Calulation for the growth rate for the upcoming year
            population=growthnumber+population;//Calulation for the population for the upcoming year
            }//end for
        
        }//end for
    printf("If the growth rate stays constant, by 2078, our population will nearly double from 2016\n");//Outputs the expected year for the double of the current population
    
    }//end function main
