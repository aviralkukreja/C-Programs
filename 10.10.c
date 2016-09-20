#include <stdio.h>

 void displayBits( unsigned int value ); // prototype

int main( void )
{
    unsigned int number1;
    
    printf("Enter an integer\n");
    scanf("%d", &number1);
             // demonstrate bitwise right shift
    puts( "\nThe result of right shifting");
                     displayBits( number1 );
    puts( "4 bit positions using the right shift operator >> is" );
                            displayBits( number1 >> 4 );
                            }//endmain
                          
                            // display bits of an unsigned int value
                            void displayBits( unsigned int value )
                            {
                                unsigned int c; // counter
                                
                                // declare displayMask and right shift 31 bits
                                unsigned int displayMask = 1 << 31;
                                
                                printf( "%7u = ", value );
                                // loop through bits
                                for ( c = 1; c <= 32; ++c ) {
                                    putchar( value & displayMask ? '1' : '0' );
                                    value <<= 1; // shift value right by 1
                                    
                                    if ( c % 8 == 0 ) { // output a space after 8 bits
                                        putchar( ' ' );
                                        } // end if
                                    } // end for
                                
                                putchar( '\n' );
                                } // end function displayBits