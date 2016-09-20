//Airplane Reservation System
//Problem 6.21
//By: Aviral Kukreja
//7-5-16
#include <stdio.h>

//All used integers are defined below
int findFreeLocationFirstClass(int b[]);
int findFreeLocationEconomyClass(int b[]);
int isEmptyFirstClass(int b[]);
int isEmptyEconomyClass(int b[]);
void printBoardingPass(int seatNumber);
int arrangeAndPrintFirstClass(int b[],int counter);
int arrangeAndPrintEconomyClass(int b[],int counter);

//Function main begins program execution
int main(void)
{
    
    //Initial values for all integers
    int choice=0;
    int seats[11]={0};
    static int countFirstClass=0;
    static int countEconomyClass=0;
    char charChoice=8;
    
    while (choice!=-1)//While loop used to assign seats and check for empty ones
    {
        printf("Please type 1 for first class(-1 to exit)(%d First Class Available) :",5-countFirstClass);//Outputs an instruction that must be followed to book a first class ticket
        printf("\nPlease type 2 for economy class(-1 to exit)(%d Economy Class Available) :",5-countEconomyClass);//Outputs an instruction that must be followed to book an economy class ticket
        scanf("%d",&choice);//Reads the choice integer
        
        //If choice is 1, First class ticket will be booked
        if (choice==1 && isEmptyFirstClass(seats))  {
            countFirstClass=arrangeAndPrintFirstClass(seats,countFirstClass);
            
            
        }
        //If choice is 2, Economy class ticket will be booked
        else if (choice==2 &&  isEmptyEconomyClass(seats))
        {
            countEconomyClass=arrangeAndPrintEconomyClass(seats,countEconomyClass);
            
        }
        else {
            //Anything else print the following
            printf("\nNext flight leaves in 3 hours.\n\n");
            
            //If statement allows you to choose economy class when first class is full
            if(choice==1 && (5-countEconomyClass)>0 ){
                
                printf("or You can choose Economy Class if you want.\nWe have empty places in there. (y or n) : ");
                scanf(" %c",&charChoice);
                if (charChoice=='y')
                {
                    countEconomyClass=arrangeAndPrintEconomyClass(seats,countEconomyClass);
                    
                    
                    
                }
                
                else printf("Good Bye");
                
            }
            
            //Else if statement allows you to choose first class if economy class is full
            else if (choice==2 && (5-countFirstClass)>0 ) {
                
                printf("\nr You can choose First Class if you want.\nWe have empty places in there. (y or n) : ");
                scanf(" %c",&charChoice);
                
                if (charChoice=='y')
                {
                    countFirstClass=arrangeAndPrintFirstClass(seats,countFirstClass);
                    
                    
                }
                
                else printf("Good Bye");
            }
            
            else {
                printf("\nNext flight leaves in 3 hours.\n\n");
            }
            return 0;
        }
    }
    
}

//Function findFreeLocationFirstClass
int findFreeLocationFirstClass(int b[]){
    
    int i;
    
    //For loop allows us to fill in space for first class
    for (i = 1; i <=5 ; i++)
    {
        if(b[i]==0)
            return i;
        
    }
    printf("\nNo place left in First Class\n");
    exit(1);
}

int findFreeLocationEconomyClass(int b[]){
    
    int i;
    
    //For loop allows us to fill in space for economy class
    for (i = 6; i <=10 ; i++)
    {
        if(b[i]==0)
            return i;
        
    }
    printf("\nNo place left in Economy Class");
    exit(1);
}

int isEmptyFirstClass(int b[]){
    
    int i;
    
    //For loop allows us to check if there is space in first class
    for (i = 1; i <=5 ; i++)
    {
        if(b[i]==0)
            return 1;
        
    }
    return 0;
}

int isEmptyEconomyClass(int b[]){
    
    int i;
    
    //For loop allows us to check if there is space in economy class
    for (i = 6; i <=10 ; i++)
    {
        if(b[i]==0)
            return 1;
        
    }
    return 0;
}

void printBoardingPass(int seatNumber){
    
    printf("Seat Number %d is reserved for you.\nHave a nice and safe flight.\n\n",seatNumber);//Outputs statement to confirm flight booking
    
}

//Function arrangaAndPrintFirstClass
int arrangeAndPrintFirstClass(int b[],int counter){
    
    //Allows us to take a first class seat away from availability
    int freePlace=0;
    int countFirstClass=counter;
    freePlace=findFreeLocationFirstClass(b);
    b[freePlace]=1;
    printBoardingPass(freePlace); 
    countFirstClass++;
    return countFirstClass;
    
}

//Function arrangeAndPrintEconomyClass
int arrangeAndPrintEconomyClass(int b[],int counter){
    
    //Allows us to take a first class seat away from availability
    int freePlace=0;
    int countEconomyClass=counter;
    freePlace=findFreeLocationEconomyClass(b);
    b[freePlace]=1;
    printBoardingPass(freePlace);
    countEconomyClass++;
    return countEconomyClass;
    
}