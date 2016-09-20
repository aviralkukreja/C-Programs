/* Exercise 12.9*/
#include <stdio.h>
#include <stdlib.h>
/* ListNode structure definition */
struct ListNode {
    char data; /* node data */
    struct ListNode *nextPtr; /* pointer to next node */
}; /* end struct ListNode */
typedef struct ListNode ListNode;
typedef ListNode *ListNodePtr;

/* function prototypes */
ListNodePtr reverseList( ListNodePtr currentPtr );
void insert( ListNodePtr *sPtr, char value );
void printList( ListNodePtr currentPtr );
void push( ListNodePtr *topPtr, char info );

int main()
{
    ListNodePtr listPtr = NULL; /* list pointer */ char i; /* loop counter */
    /* build list with characters A to J */
    for(i='A';i<='J';i++){ insert( &listPtr, i );
    }/*endfor*/
    
    printf( "The list is:\n" );
    printList( listPtr );
    
    /* reverse the list and display result */
    printf( "The list in reverse is:\n" );
    printList( reverseList( listPtr ) );
    
    return 0; /* indicate successful termination */
    
}/*endmain*/
/* Create a list in the reverse order of the list argument */
ListNodePtr reverseList( ListNodePtr currentPtr ) {
    ListNodePtr stack = NULL; /* pointer to reversed list */
    /* loop through list currentPtr */
    while ( currentPtr != NULL ) {
        
        /* push current element on to stack */
        push( &stack, currentPtr->data );
        currentPtr = currentPtr->nextPtr; } /* end while */
    return stack; /* return reversed list */ } /* end function reverseList */

/* Insert a new value into the list in sorted order */
void insert( ListNodePtr *sPtr, char value )
{
    ListNodePtr newPtr; /* new node */ ListNodePtr previousPtr; /* previous node */ ListNodePtr currentPtr; /* current node */
    /* dynamically allocate memory */
    newPtr = malloc( sizeof( ListNode ) );
    /* if newPtr does not equal NULL */
    if ( newPtr )
    { newPtr->data = value; newPtr->nextPtr = NULL;
            previousPtr = NULL;
            currentPtr = *sPtr; /* set currentPtr to start of list */
        
            /* loop to find correct location in list */
            while ( currentPtr != NULL && value > currentPtr->data ) { previousPtr = currentPtr;
                currentPtr = currentPtr->nextPtr;
            } /* end while */
        
            /* insert at beginning of list */
            if ( previousPtr == NULL ) { newPtr->nextPtr = *sPtr; *sPtr = newPtr;
                            } /* end if */
            else { /* insert node between previousPtr and currentPtr */
                previousPtr->nextPtr = newPtr;
                newPtr->nextPtr = currentPtr; } /* end else */
        } /* end if */
    
    else {
            printf( "%c not inserted. No memory available.\n", value );
        
            } /* end else */
        } /* end function insert */

    /* Insert a node at the stack top */
    void push( ListNodePtr *topPtr, char info ) {
    ListNodePtr newPtr; /* temporary node pointer */
    
    /* dynamically allocate memory */
    newPtr = malloc( sizeof( ListNode ) );
    /* if memory was allocated, insert node at top of list */
    if(newPtr){
        newPtr->data = info; newPtr->nextPtr = *topPtr; *topPtr = newPtr;
    }/*endif*/
    
    else {
        printf( "%c not inserted. No memory available.\n", info );
    } /* end else */
} /* end function push */

/* Print the list */
void printList( ListNodePtr currentPtr )
{
    /* if list is empty */
    if ( !currentPtr ) {
        printf( "List is empty.\n\n" );
    }/*endif*/
    else {
        
        /* loop while currentPtr does not equal NULL */
        while ( currentPtr ) {
            printf( "%c ", currentPtr->data ); currentPtr = currentPtr->nextPtr;
        } /* end while */
        printf( "*\n\n" );
    } /* end else */
     } /* end function printList */