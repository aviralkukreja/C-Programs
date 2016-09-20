//Left-Shiftng Integers
//Problem 10.11
//By: Aviral Kukreja
//07-20-16
#include <stdio.h>

void displayInBitFormat(int);//Prototype
int i, value, power;

int main(void)
{
    
    puts("Enter an integer");
    scanf("%d",&value);
    
    //Demonstrated bit representation using the integer given
    printf("\n%d's bit representation is: \n",value);
    displayInBitFormat(value);
    puts("");
    
    //The user must enter a number that will be used as an exponent of 2
    puts("Enter power of two");
    scanf("%d",&power);
    
    //Output the number value and bit representaion by the number of the power of 2
    printf("result is: %d\n", value=value<<power);
    puts("In bit format:");
    displayInBitFormat(value);
    
    
}//end function main

//bit representer of an int
void displayInBitFormat(int val){
    
    //Declare mask and left shift 31 bits
    int mask=1<<31;
    
    //loop through bits
    for (i = 0; i < 32; i++)
    {
        //here inclusive or checked
        if (val&mask)
        {
            printf("1");
        }//end if
        else
        {
            printf("0");
        }//end else
        
        //Outputs a space after 8 bits
        if ((i+1)%8==0)
        {
            printf(" ");
        }//end if
        
        //here val's bits are shifted to left one by one
        val=val<<1;
    }//end for
    
}
