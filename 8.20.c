#include <stdio.h>
#include <string.h>
#define MAX_LINE 80

//function main begins program execution
int main(void)
{
    //initialize array string
    char line[MAX_LINE];//sets
    char delim[] = " ,.!;:\n";// sets up word separators
    char *words, *ptr;
    
    //counter loop initiation
    int count = 0;
    
    //Output question to user for entering words in a string
    printf("Enter line of text \n");
    fgets(line,MAX_LINE,stdin);
    
    ptr= line;//define pointer
    
    //While loop to count the number of words in the string
    while ((words = strtok(ptr, delim)) !=NULL)
    {printf("\n%s\n",words);//Output the number of words
        count++;//add every word found in the string into the counter
        ptr = NULL;//continue adding until it becomes 0 or null
    }//end while
    
    printf("%d word(s) in this string \n",count);//Ouput the number of words in the string
  
}//end function main

