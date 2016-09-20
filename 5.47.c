//Craps Game Modification
//Problem 5.47
//By: Aviral Kukreja
//7-5-16
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time

// enumeration constants represent game status
enum Status { CONTINUE, WON, LOST };

 int rollDice( void ); // function prototype 11
void assess (int bankBalance);

 // function main begins program execution
 int main( void )
 {
    int sum; // sum of rolled dice
    int myPoint; // player must make this point to win
     int bankBalance=1000;//current bank balance
     int wager;//define wager
     int roll;//define roll
     int count;//define count
     int rollcount;//define number of times the dice is rolled
    enum Status gameStatus; // can contain CONTINUE, WON, or LOST
    // randomize random number generator using current time
    srand( time( NULL) );
     
    
    sum = rollDice(); // first roll of the dice
     //Output the given statements
     printf("Game is starting\n");//Output a message to start the game
     printf("Your balance is 1000 dollars\n");//Output the player's current balance
     
     while (bankBalance>0) {
         printf("Are you ready!\n\n");//Output message to notify the start of a new game
         wager=askwager();//Use of function askwager
         rollcount++;//Increase roll count by one every time a wager is given
         sum=rollDice();//Use of rollDice function
         printf("You rolled %d\n",roll);//Print what was rolled
         count=1;//define count value
     
     
     // determine game status based on sum of dice
     switch( sum ) {
             // win on first roll
         case 7: // 7 is a winner
         case 11: // 11 is a winner
             gameStatus = WON; // game has been won
             printf("You Won in %d assumptions\n",count);//Output number of times won
             printf("Your balance is now %d\n", bankBalance+=wager);//Output your current bank balance
             
             break;
             // lose on first roll
         case 2: // 2 is a loser
         case 3: // 3 is a loser
         case 12: // 12 is a loser
             gameStatus = LOST; // game has been lost
             printf("You lost in %d assumptions\n",count);
             printf("Your balance is now %d\n",bankBalance-=wager);
             break;//optional
             // remember point
         default:
             gameStatus = CONTINUE; // player should keep rolling
             myPoint = sum; // remember the point
             printf( "Point is %d\n", myPoint );
             break; // optional
     } // end switch
     }
     
     // while game not complete
     while ( CONTINUE == gameStatus ) { // player should keep rolling
         sum = rollDice(); // roll dice again
         
         if
             //determine game status
             ( sum == myPoint ) { // win by making point
                 gameStatus = WON; // game over, player won
             } // end if
         else {
         if ( 7 == sum ) { // lose by rolling 7
             gameStatus = LOST; // game over, player lost
         } // end if
     } // end else
 } // end while
// display won or lost message
if (WON == gameStatus)

{
    
    puts( "Player wins" );//Output wins when the player wins
}//end if
else {
    puts( "Player loses" );//Outputs loses when the player loses
    }//end else
 }//end function main


    int rollDice( void )
     {
    int die1; // first die
    int die2; // second die
    int workSum; // sum of dice

         
    die1=1+(rand()%6);//pickrandomdie1value
    die2=1+(rand()%6);//pickrandomdie2value
    workSum = die1 + die2; // sum die1 and die2
    
    // display results of this roll
    printf( "Player rolled %d + %d = %d\n", die1, die2, workSum );//Print the numbers that were rolled
    return workSum; // return sum of dice
    } // end function rollRice
int askwager (void)
{
    int wager;//Wager value
    printf ("What is your wager amount?");//Output poses a question to user
    scanf("%d", &wager);//Read wager value
    
    return wager;//Calculate wager and return result
}
void assess(int bankBalance){
    if ((bankBalance<500)&& (bankBalance>0))
    printf("Oh, you're going for broke, huh?\n");//Fun output message to remind user
    else if  ((bankBalance>=500)&&(bankBalance<1100))
        printf("Aw cmon, take a chance!?\n");//Fun output message to make the user wager more
    else if(bankBalance>1100)
        printf("You're up big. Now's the time to cash in your chips!\n");//Fun message to make the user wager more
    else printf("You are bankrupt!!!!!\n");//Ouput message of becoming bankrupt
}
