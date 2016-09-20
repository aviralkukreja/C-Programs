/* Exercise 12.7*/
#include <stdio.h>
#include <stdlib.h>

/* ListNode structure definition */
struct ListNode {
    int data; /* node data */
    struct ListNode *nextPtr; /* pointer to next node */
}; /* end struct ListNode */ typedef struct ListNode ListNode;
typedef ListNode *ListNodePtr;
/* function prototype */
void insert( ListNodePtr *sPtr, int value );
void printList( ListNodePtr currentPtr );
ListNodePtr merge( ListNodePtr a, ListNodePtr b );

int main()
{
    ListNodePtr list1Ptr = NULL; /* pointer to first list */
    ListNodePtr list2Ptr = NULL; /* pointer to second list */
    ListNodePtr list3Ptr; /* pointer to merged list */
    int i; /* loop counter */
    
    /* build first list */
    for(i=2;i<=10;i+=2){
        insert( &list1Ptr, i );
        }/*endfor*/
    
    printf( "List 1 is: " );
    printList( list1Ptr );
    
    /* build second list */
    for(i=1;i<=9;i+=2){
        insert( &list2Ptr, i );
        }/*endfor*/
    
    printf( "List 2 is: " );
    printList( list2Ptr );
    /* merge both lists and print results */
    list3Ptr = merge( list1Ptr, list2Ptr );
    printf( "The merged list is: " );
    printList( list3Ptr );
    
    return 0; /* indicate successful termination */
    
}/*endmain*/
/* Merge two lists of integers */
ListNodePtr merge( ListNodePtr a, ListNodePtr b ) {
    ListNodePtr currentPtr1; /* pointer to first list */
    ListNodePtr currentPtr2; /* pointer to second list */
    ListNodePtr c = NULL; /* pointer to merged list */
    
    currentPtr1 = a; /* set currentPtr1 to first linked list */ currentPtr2 = b; /* set currentPtr2 to second linked list */
    /* while currentPtr1 does not equal NULL */
    while ( currentPtr1 != NULL ) {
        /* compare currentPtr1 and currentPtr2, insert lesser node */
        if ( currentPtr2 == NULL || currentPtr1->data < currentPtr2->data ) {
            /* insert currentPtr1 node */
            insert( &c, currentPtr1->data );
            currentPtr1 = currentPtr1->nextPtr;
            } /* end if */
        else {
            
            /* insert currentPtr2 node */
            insert( &c, currentPtr2->data );
            
            currentPtr2 = currentPtr2->nextPtr; } /* end else */
    } /* end while */
    /* insert any remaining nodes in currentPtr2 list */
    while ( currentPtr2 != NULL ) { insert( &c, currentPtr2->data ); currentPtr2 = currentPtr2->nextPtr;
    } /* end while */
    
    return c; /* return merged list */ } /* end function merge */
/* Insert a new value into the list in sorted order */
void insert( ListNodePtr *sPtr, int value ) {
    ListNodePtr newPtr; /* new node */
    ListNodePtr previousPtr; /* previous node */
    ListNodePtr currentPtr; /* current node */
    
    /* dynamically allocate memory */
    newPtr = malloc( sizeof( ListNode ) );
    
    /* if newPtr does not equal NULL */
    if ( newPtr ) {
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
            printf( "%d ", currentPtr->data ); currentPtr = currentPtr->nextPtr;
        } /* end while */
        printf( "*\n\n" );
        } /* end else */
    
    } /* end function printList */