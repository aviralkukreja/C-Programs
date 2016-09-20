// Maze Traversal
// Problem 7.22
// By: Aviral Kukreja
// 07-12-16
#include <stdio.h>
#include <stdlib.h>

#define DOWN  0 // move down
#define RIGHT 1 // move right
#define UP    2 // move up
#define LEFT  3 // move left



// function prototypes
void mazeTraversal( char maze[ 12 ][ 12 ], size_t xCoord, size_t yCoord,
                   unsigned int direction );
void printMaze( const char maze[][ 12 ] );
int validMove( const char maze[][ 12 ], size_t r, size_t c );
int coordsAreEdge( size_t x, size_t y );
void findStart( const char maze[][ 12 ] );

int X_START, Y_START; // starting X and Y coordinate for maze

int main()
{
    // maze grid
    char maze[ 12 ][ 12 ] =
    {   { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        { '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        { '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
        { '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
        { '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
        { '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        { '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        { '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        { '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        { '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
        { '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' } };
    
    findStart(maze);
    
    mazeTraversal( maze, X_START, Y_START, RIGHT );
} // end main

//Find the maze entrance in the first column of the maze
void findStart(const char maze[][ 12 ])
{
    int x;
    Y_START = 0;  // maze entrance is at the leftest edge of the maze --> column 0
    for ( x = 0; x < 12; ++x ) {
        if ( maze [x][Y_START] == '.') {
            X_START = x;
            break;
        }
    }
}

// Assume that there is exactly 1 entrance and
// exactly 1 exit to the maze.
void mazeTraversal( char maze[ 12 ][ 12 ], size_t xCoord, size_t yCoord,
                   unsigned  direction )
{
    static int flag = 0; // starting position flag
    
    maze[ xCoord ][ yCoord ] = 'X'; // mark current point
    printMaze( maze );
    
    // if maze completed
    if ( coordsAreEdge( xCoord, yCoord ) && xCoord != X_START &&
        yCoord != Y_START ) {
        puts( "\nMaze successfully exited!\n\n" );
        return;
    } // end if
    else if ( xCoord == X_START && yCoord == Y_START && flag == 1 ) {
        puts( "\nArrived back at the starting location.\n\n" );
        return;
    } // end else if
    else { // make next move
        unsigned int move; // next move
        unsigned int count; // counter
        
        flag = 1;
        
        // loop 4 times and find first valid move
        for ( move = direction, count = 0; count < 4; ++count,
             ++move, move %= 4 ) {
            
            // choose valid move
            switch( move ) {
                    
                case DOWN: // move down
                    
                    // if move is valid, call mazeTraversal
                    if ( validMove( maze, xCoord + 1, yCoord ) ) {
                        mazeTraversal( maze, xCoord + 1, yCoord, LEFT );
                        return;
                    } // end if
                    
                    break; // exit switch
                    
                case RIGHT: // move right
                    
                    // if move is valid, call mazeTraversal
                    if ( validMove( maze, xCoord, yCoord + 1 ) ) {
                        mazeTraversal( maze, xCoord, yCoord + 1, DOWN );
                        return;
                    } // end if
                    
                    break; // exit switch
                    
                case UP: // move up
                    
                    // if move is valid, call mazeTraversal
                    if ( validMove( maze, xCoord - 1, yCoord ) ) {
                        mazeTraversal( maze, xCoord - 1, yCoord, RIGHT );
                        return;
                    } // end if
                    
                    break; // exit switch
                    
                case LEFT: // move left
                    
                    // if move is valid, call mazeTraversal
                    if ( validMove( maze, xCoord, yCoord - 1 ) ) { // go left
                        mazeTraversal( maze, xCoord, yCoord - 1, UP );
                        return;
                    } // end if
                    
                    break; // exit switch
            } // end switch
            
        } // end for
        
    } // end else
    
} // end function mazeTraversal

// validate move
int validMove( const char maze[][ 12 ], size_t r, size_t c )
{
    return ( r >= 0 && r <= 11 && c >= 0 && c <= 11 &&
            maze[ r ][ c ] != '#' );
    
} // end function validMove

// function to check coordinates
int coordsAreEdge( size_t x, size_t y )
{
    int areEdge;
    
    
    // if coordinate is not valid
    if ( ( x == 0 || x == 11 ) && ( y >= 0 && y <= 11 ) ) {
        areEdge = 1;
    } // end if
    else if ( ( y == 0 || y == 11 ) && ( x >= 0 && x <= 11 ) ) {
        areEdge = 1;
    } // end else if
    else { // coordinate is valid
        areEdge = 0;
    } // end else
    
    return areEdge; // return result 
} // end function coordsAreEdge

// print the current state of the maze
void printMaze( const char maze[][ 12 ] )
{ 
    size_t x; // row counter
    size_t y; // column counter
    
    // iterate through the maze
    for ( x = 0; x < 12; ++x ) { 
        
        for ( y = 0; y < 12; ++y ) {
            printf( "%c ", maze[ x ][ y ] );
        } // end for
        
        puts( "" );
    } // end for
    
    puts( "\nHit return to see next move" );
    getchar();
} // end function printMaze
