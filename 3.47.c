//Target Heart Rate Calculator
//Problem 3.47
//By: Aviral Kukreja
//06/17/16
#include <stdio.h>

//Function main begins program execution
int main(void)

{
    int byear;//This value is the year of birth
    int bmonth;//This value is the month of birth
    int bdate;//This value is the date of birth
    int cyear;//This value is the current year
    int cmonth;//This is the current month
    int cdate;//This is the current date
    int age;//This value is the age
    int max;//This value is the maximum heart rate in beats per minute
    int t50;//This value is the lowest target heart rate
    int t85;//This value is the highest target heart rate
    
    printf("Enter your year of birth here\n");//Prompt to enter birth year
    scanf("%d", &byear);//Read byear
    
    printf("Enter your month of birth (Note: Enter in digit form)\n");//Prompt to enter birth month in digit form
    scanf("%d", &bmonth);//Read bmonth
    
    printf("Enter your date of birth\n");//Prompt to enter birth date
    scanf("%d", &bdate);//Read bdate
    
    //The following refers to the current date
    cyear = 2016;
    cmonth = 6;
    cdate = 16;
    
    //The following calculations is to see if the month and date is before or after the current date, causing a change in the age
    byear = cyear - byear;
    bmonth = cmonth - bmonth;
    bdate = cdate - bdate;
    
    if (bdate<0) {
        bmonth = bmonth-1;
        //if the bdate is negative when subtracted, borrow from the bmonth value
    }//ends if
    
    if (bmonth<0) {
        byear = byear-1;
        //if the month is negative when subtracted, borrow from the byear value
    }//ends if
    
    age = byear;
    printf("You are %d years old\n", age);//Output age
    
    max = 220 - age;
    printf("Your maximum heart rate in beats per minute is %d\n", max);//Output max heartrate using the calculation above
    
    t50 = max * 0.5;
    printf("Your target heart rate is between %d", t50);//Output lower range of target heart rate using the calculation above
    
    t85 = max * 0.85;
    printf(" and %d\n", t85);//Output higher range of target heart rate using the calculation above
}//Ends main function