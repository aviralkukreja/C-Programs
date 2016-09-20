//Strings ending with 'ed'
//Problem 8.24
//By: Aviral Kukreja
//07-12-16
#include <stdio.h>
int i;

//Function main begins program execution
int main(void){
    
    char strings[4][100];
    char comp[3]="ed";
    
    puts("Enter 4 string: ");//Ouput for user to answer
    
    //get the strings
    for (i = 0; i < 4; i++)
    {
        fgets(strings[i], 99, stdin);
    }
    
    //print the strings
    for (i = 0; i < 4; i++)
    {
        //Output any words that end in 'ed' using this if loop
        if ( strstr(strings[i],comp)!=NULL )
        {
            printf("%s", strings[i]);
        }
        
    }
}//end function main