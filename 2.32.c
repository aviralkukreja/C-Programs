//BMI Calculator
//2.32
//Created by: Aviral Kukreja
//06/15/16
#include <stdio.h>

//Function main begins program execution
int main(void)
{
    int integer1;//First number to be entered by user
    int integer2;//Second number to be entered by user
    int integer3;//This number holds the value of the numerator of the BMI formula and is calculated using the value from integer1
    int integer4;//This number holds the value of the denominator of the BMI formula and is calculated using the value from integer2
    int division;//This number holds the value of the body mass index
    
    printf("Enter wieght in pounds\n");//Prompt to enter weight in lb.
    scanf("%d", &integer1);//Read integer1
    
    integer3 = integer1 * 703;//Calulates the numerator of the BMI formula

    printf("Enter height in inches\n");//Prompt to enter height in in.
    scanf("%d", &integer2);//Read integer2
    
    integer4 = integer2 * integer2;//Calculates the denominator of the BMI formula
    
    division = integer3 / integer4;//Calulates the BMI value
    
    printf("Your BMI is %d\n", division);//Displays the users BMI
    
    if (division<19) {
        printf("You are underweight\n");//Prints 'underweight' status when user's BMI is below 19
    }//end if
    
    if (19<=division && division<25) {
        printf("Your weight is normal\n");//Prints 'normal' status when the user's BMI ranges from 19 to 25
    }//end if
    
    if (25<=division && division<30) {
        printf("You are overweight\n");//Prints 'overweight' status when the user's BMI ranges from 25 to 30
    }//end if
    
    if (30<=division){
        printf("You are obese");//Prints 'obese' status when the user's BMI is 30 and over
    }//end if
}//end function main