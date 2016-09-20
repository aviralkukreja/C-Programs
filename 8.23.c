//Starting Strings with 'b'
//Problem 8.23
//By: Aviral Kukreja
//07-12-16
#include <stdio.h>

int i;

//function main begins program execution
int main(void){
    
    char strings[4][100];
    
    puts("Enter 4 string: ");//Output for user
    
    //get the strings
    for (i = 0; i < 4; i++)
    {
        fgets(strings[i], 99, stdin);
    }
    
    //print the strings
    for (i = 0; i < 4; i++)
    {
        //Output any words that start with 'b' using this loop
        if (strings[i][0]=='b')
        {
            printf("%s", strings[i]);
        }
        
    }
    
}//end function main