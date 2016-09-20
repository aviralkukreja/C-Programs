
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int masterAccount;//Account from old master file
    int transactionAccount;//Account from transaction file
    double masterBalance;//Balance from old master file
    double transactionBalance;//Balance from transactions file
    char masterName[ 30 ];//Name from master file
    FILE *ofPtr;//old master file pointer
    FILE *tfPtr; /* transactions file pointer */
    FILE *nfPtr; /* new master file pointer */
    
    /* terminate application if old master file cannot be opened */
    if ( ( ofPtr = fopen( "oldmast.dat", "r" ) ) == NULL ) {
        printf( "Unable to open oldmast.dat\n" );
        exit( 1 );
    }/*endif*/
    
    /* terminate application if transactions file cannot be opened */
    if ( ( tfPtr = fopen( "trans.dat", "r" ) ) == NULL ) {
        printf( "Unable to open trans.dat\n" );
        exit( 1 );
    }/*endif*/
    
    /* terminate application if new master file cannot be opened */
    if ( ( nfPtr = fopen( "newmast.dat", "w" ) ) == NULL ) {
        printf( "Unable to open newmast.dat\n" );
        exit( 1 );
    }/*endif*/
    
    /* display account currently being processed */
    printf( "Processing....\n" );
    fscanf( tfPtr, "%d%lf", &transactionAccount, &transactionBalance );
    
    /* while not the end of transactions file */
    while ( !feof( tfPtr ) ) {
        
        /* read next record from old master file */
        fscanf( ofPtr, "%d%[^0-9-]%lf", &masterAccount, masterName, &masterBalance );
        
        /* display accounts from master file until number of new account is reached */
        while ( masterAccount < transactionAccount && !feof( ofPtr ) )
        { fprintf( nfPtr, "%d %s %.2f\n", masterAccount, masterName,masterBalance );
            printf( "%d %s %.2f\n", masterAccount, masterName, masterBalance );
            
        /* read next record from old master file */
            fscanf( ofPtr, "%d%[^0-9-]%lf", &masterAccount, masterName, &masterBalance );
        } /* end while */
        
        /*if matching account found, update balance and output account info */
        if( masterAccount == transactionAccount ) { masterBalance += transactionBalance;
            fprintf( nfPtr, "%d %s %.2f\n", masterAccount, masterName, masterBalance );
            printf( "%d %s %.2f\n", masterAccount, masterName, masterBalance );
        }/*endif*/
        
        /* tell user if account from transactions file does not match account from master file */
        else if ( masterAccount > transactionAccount ) {
            printf( "Unmatched transaction record for account %d\n",
                   transactionAccount );
            fprintf( nfPtr, "%d %s %.2f\n", masterAccount, masterName,
                    masterBalance );
            printf( "%d %s %.2f\n", masterAccount, masterName,
                   masterBalance ); }/*endelseif*/
        else {
            printf( "Unmatched transaction record for account %d\n",
                   transactionAccount );
        
    }//end else
    
    /* get next account and balance from transactions file */
    fscanf( tfPtr, "%d%lf", &transactionAccount, &transactionBalance );
    }/* end while */

/* loop through file and display account number, name and balance */
while (!feof (ofPtr) ) {
    fscanf( ofPtr, "%d%[^0-9-]%lf", &masterAccount, masterName, &masterBalance );
    fprintf( nfPtr, "%d %s %.2f", masterAccount, masterName, masterBalance );
    printf( "%d %s %.2f", masterAccount, masterName, masterBalance );
    } /* end while */
fclose( ofPtr ); /* close all file pointers */
fclose( tfPtr );
fclose( nfPtr );
}

