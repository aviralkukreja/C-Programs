//Game of Crapss
//Problem 6.20
//By: Aviral Kukreja
//7-5-16
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rollDice(void);//Function prototype

int main(void)//Function main begins program execution
{
    
    int roll;//defines integer roll
    int targetPoint=0;//Integer that holds the value of your target point that defines your win or loss
    int count;//defines count
    int winCount=0;//How many times did you win?
    int loseCount=0;//How many times did you lose?
    int i;//integer used for loop purposes
    int howManyTimes=0;//How many times do you want the game run?
    int rollCount=0;//This counts the number of dice rolled whole
    int winRollFrequency[30]={0};
    int loseRollFrequency[30]={0};
    int totalWinners=0;//Holds the value of the number of wins
    int totalLosers=0;//Holds the value with the number of losses
    
    enum Gamestatus {WON,LOST,CONTINUE};
    enum Gamestatus status;
    
    srand(time(0));	//You have to call srand once and under main!!! Not in rollDice() function!!!
    
    printf("Enter how many times to play the game:");//Outputs the question to the user
    scanf("%d",&howManyTimes);//Reads howManyTimes value
    
    
    
    for(i=1;i<=howManyTimes;i++){//For loop to run the games as many times as the user pleases
        
        
        printf("Game starting!!\n");//Output message to notify the start of the game
        printf("Are you ready!!!!!!!\n\n");//Fun message to notify the start of the game
        rollCount++;//Roll Count increases by 1
        roll=rollDice();//roll calculated using rollDice function
        printf("You rolled %d.\n", roll);//Outputs the number that is rolled
        count=1;//Defined count value
        
        switch(roll){
                
            case 7:
            case 11:
            //When either 7 or 11 is rolled...
                status=WON;//User wins
                printf("You WON in %d assumptions!\n",count);//Outputs win message
                winCount++;//Win count increases by 1
                winRollFrequency[count]++;//Win count frequency increases by 1
                break;//exit switch
                
            case 2:
            case 3:
            case 12:
            //When either 2,3,or 12 is rolled...
                status=LOST;//User loses
                printf("You LOST in %d assumptions!\n",count);//Outputs losing message
                loseCount++;//Lose count increases by 1
                loseRollFrequency[count]++;//Lose count frequency increases by 1
                break;//exit switch
                
            default://Catch all other characters
                status=CONTINUE;//Continue playing if any other number is choosen
                targetPoint=roll;//Both integers equal each other at this point
                printf("Your target point is: %d \n",roll);//States target point
                
                while(status==CONTINUE){//While loop for an extra roll
                    count++;//Count increases by 1
                    printf("You are rolling again: \n");//Print message to remind the action of another roll
                    rollCount++;//rollCount increases by 1
                    printf("You rolled %d\n",roll=rollDice());//Output the number that has been rolled
                    
                    if (targetPoint==roll){//if loop to check ones win or loss status
                        
                        printf("You WON in %d assumptions!\n",count);//Print win message with the number of wins
                        winCount++;//Increase winCount by 1
                        winRollFrequency[count]++;//Increase winRollFrequency by 1
                        status=WON;//Winning status
                        
                        
                    }
                    else if(7==roll){//else if loop to check ones win or loss status
                        
                        printf("You LOST in %d assumptions!\n",count);//Print loss message with the number of lossess
                        loseCount++;//Increase loos count by 1
                        loseRollFrequency[count]++;//Increase loseRollFrequency by 1
                        status=LOST;//Losing status
                    }
                    else //else loop to allow user to conitue playing if anything else comes up
                        status=CONTINUE;//Continuing status
                    
                } //end while
                
        }//end switch
        
    }//end for
    
    //The following for loops calculate the total number of wins and losses
    for (i = 0; i <30; i++)
    {
        totalWinners+=winRollFrequency[i];
    }
    
    for (i = 0; i < 30; i++)
    {
        totalLosers+=loseRollFrequency[i];
    }
    
    printf("Total winners: %d\nTotal losers: %d\n",winCount,loseCount);//Output the number of wins and losses
    printf("You rolled the dice %d times.\n",rollCount);//Output the number of times the dice was rolled
    for (i = 1; i < 30; i++)
    {
        printf("%4d games won and %4d games lost on roll %2d\n",winRollFrequency[i],loseRollFrequency[i], i);//Output the number of wins and losses per role
    }
    
    printf("The chances of winning are: %.2f percent\n" , 100.0*totalWinners/howManyTimes);//Ouput the chance of winning
    printf("The average game length is %.2f roll\n.",(double)rollCount/howManyTimes);//Output the average game length

    
    return 0;//Check program
}//end main

//rollDice function
int rollDice(void){
    
    return (1+rand()%6)+(1+rand()%6);//Calculations use to get the number rolled on dice
    
}