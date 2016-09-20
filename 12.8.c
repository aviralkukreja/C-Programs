/* Exercise 12.8 Solution */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ListNode structure definition */
typedef struct ListNode {
    int data; /* node data */
    struct ListNode *nextPtr; /* pointer to next node */
} ListNode; /* end struct ListNode */
typedef ListNode *ListNodePtr;

/* function prototypes */
int sumList( ListNodePtr a );
double averageList( ListNodePtr a );
void insert( ListNodePtr *sPtr, int value );
void printList( ListNodePtr currentPtr );

int main()
  {
    ListNodePtr listPtr = NULL; /* list pointer */
    int i; /* loop counter */
    
    srand( time( NULL ) ); /* randomize */
    
    /* build list with random numbers from 0 to 100 */
    for(i=1;i<=25;i++){
        insert( &listPtr, rand() % 101 );
        }/*endfor*/
    
    printf( "The list is:\n" );
    printList( listPtr );
    
    /* calculate and display the sum and average of list values */
    printf( "The sum is %d\n", sumList( listPtr ) );
    printf( "The average is %f\n", averageList( listPtr ) );
    
    return 0; /* indicate successful termination */
  
}/*endmain*/
/* Sum the integers in a list */
int sumList( ListNodePtr a ) {
    ListNodePtr currentPtr; /* temporary pointer to list a */ int total = 0; /* sum of node values */
    
    currentPtr = a; /* set currentPtr to list a */ /* loop through list */
    while ( currentPtr != NULL ) {
        /* add node value to total */
        total += currentPtr->data;
        currentPtr = currentPtr->nextPtr; } /* end while */
  
    return total;
} /* end function sumList */
/* Average the integers in a list */
double averageList( ListNodePtr a ) {
    ListNodePtr currentPtr; /* temporary pointer to list a */ double total = 0.0; /* sum of node values */
    
    int count = 0; /* number of nodes in list */ currentPtr = a; /* set currentPtr to list a */
    /* loop through list */
    while ( currentPtr != NULL ) {
        ++count; /* increment count */
        total += currentPtr->data; /* update total */
        
        currentPtr = currentPtr->nextPtr; } /* end while */
    return total / count; /* return average */ } /* end function averageList */
/* Insert a new value into the list in sorted order */
void insert( ListNodePtr *sPtr, int value ) {
    ListNodePtr newPtr; /* new node */
    ListNodePtr previousPtr; /* previous node */
    ListNodePtr currentPtr; /* current node */
    
    /* dynamically allocate memory */
    newPtr = malloc( sizeof( ListNode ) );
    
     /* if newPtr does not equal NULL */
    if(newPtr){
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        
        previousPtr = NULL;
        currentPtr = *sPtr; /* set currentPtr to start of list */
        
        /* loop to find correct location in list */
        while ( currentPtr != NULL && value > currentPtr->data ) {
            previousPtr = currentPtr;
            
            currentPtr = currentPtr->nextPtr; } /* end while */
        /* insert at beginning of list */
        if ( previousPtr == NULL ) { newPtr->nextPtr = *sPtr; *sPtr = newPtr;
        }/*endif*/
        else { /* insert node between previousPtr and currentPtr */
                        previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr; } /* end else */
    } /* end if */
    else {
        
        printf( "%c not inserted. No memory available.\n", value ); } /* end else */
} /* end function insert */
/* Print the list */
void printList( ListNodePtr currentPtr ) {
    /* if list is empty */
    
    if ( !currentPtr ) {
        printf( "List is empty.\n\n" );
    } /* end if */ else {
        /* loop while currentPtr does not equal NULL */
        while ( currentPtr ) {
            printf( "%d ", currentPtr->data );
            
            currentPtr = currentPtr->nextPtr; } /* end while */
        printf( "*\n\n" );
    } /* end else */
} /* end function printList */