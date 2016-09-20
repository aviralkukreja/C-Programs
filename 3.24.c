//Tabular Output
//Problem 3.24
//By: Aviral Kukreja
//6-23-16
#include <stdio.h>

//Function main begins program execution
int main(void)
{
    int table;//define table
    int n1;//define n
    int n2;//deine n in 2nd column
    int n3;//define n in 3rd column
    int n4;//define n in 4th column
    
    printf("N\t10*N\t100*N\t1000*N\n\n");//Output the header of table
    
    n1=1;//Input N value
    
    for (table=1; table<=10; table++) {
        
        printf("%d\t",n1);//Output N value
        
        n2=n1*10;//Calculate N in 2nd row
        printf("%d\t\t",n2);//Print this value
        
        n3=n2*10;//Calculate N in 3rd row
        printf("%d\t\t",n3);//Print this value
        
        n4=n3*10;//Calculate N in 4th row
        printf("%d",n4);//Print this value
        
        n1=n1+1;//Add 1 to the next N value
        
        puts("");//Output space for the next line
        
    }//end for
    
}//end function main