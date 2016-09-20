//Exercise 12.6 
#include <stdio.h>
#include <stdlib.h>

/* ListNode structure definition */
struct ListNode {
    char data; /* node data */
    struct ListNode *nextPtr; /* pointer to next node */
}; /* end struct ListNode */
typedef struct ListNode ListNode; typedef ListNode *ListNodePtr;
/* function prototypes */
void concatenate( ListNodePtr a, ListNodePtr b );
void insert( ListNodePtr *sPtr, char value );
void printList( ListNodePtr currentPtr );

int main()
{
    
    ListNodePtr list1Ptr = NULL; /* pointer to first list */ ListNodePtr list2Ptr = NULL; /* pointer to second list */
    char i; /* loop counter */
    /* assign letters from A to C into first list */
    for(i='A';i<='C';i++){
        insert( &list1Ptr, i );
        }/*endfor*/
    
    printf( "List 1 is: " );

    printList( list1Ptr );
    /* assign letters from D to F into second list */
    for(i='D';i<='F';i++){
        insert( &list2Ptr, i );
        }/*endfor*/
    
    printf( "List 2 is: " );
    printList( list2Ptr );
    
    concatenate( list1Ptr, list2Ptr ); printf( "The concatenated list is: " ); printList( list1Ptr );
    return 0; /* indicate successful termination */ }/*endmain*/
/* Concatenate two lists */
void concatenate( ListNodePtr a, ListNodePtr b )
{
    ListNodePtr currentPtr; /* temporary pointer */ currentPtr = a; /* set currentPtr to first linked list */
    /* while currentPtr does not equal NULL */
    while( currentPtr->nextPtr != NULL ) { currentPtr = currentPtr->nextPtr;
       
    } /* end while */
    currentPtr->nextPtr = b; /* concatenate both lists */
} /* end function concatenate */
/* Insert a new value into the list in sorted order */
void insert( ListNodePtr *sPtr, char value ) {
    ListNodePtr newPtr; /* new node */
    ListNodePtr previousPtr; /* previous node */
    ListNodePtr currentPtr; /* current node */
    
    /* dynamically allocate memory */
    newPtr = malloc( sizeof( ListNode ) );
    
    /* if newPtr does not equal NULL */
    if(newPtr){
        newPtr->data = value;
        
        newPtr->nextPtr = NULL; previousPtr = NULL;
        currentPtr = *sPtr; /* set currentPtr to start of list */
        /* loop to find correct location in list */
        while ( currentPtr != NULL && value > currentPtr->data ) { previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            
        } /* end while */
        /* insert at beginning of list */
        if ( previousPtr == NULL ) { newPtr->nextPtr = *sPtr; *sPtr = newPtr;
        } /* end if */
        
        else { /* insert node between previousPtr and currentPtr */ previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        } /* end else */
    } /* end if */ else {
        printf( "%c not inserted. No memory available.\n", value ); } /* end else */
    
} /* end function insert */
/* Print the list */
void printList( ListNodePtr currentPtr ) {
    /* if list is empty */
    if ( !currentPtr ) {
        
        printf( "List is empty.\n\n" ); } /* end if */
    else {
        /* loop while currentPtr does not equal NULL */
        while ( currentPtr ) {
            printf( "%c ", currentPtr->data ); currentPtr = currentPtr->nextPtr;
        } /* end while */
        printf( "*\n\n" );
        } /* end else */
    
    } /* end function printList */