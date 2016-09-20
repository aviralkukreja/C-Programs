#include <stdio.h>
#include<math.h>

//function prototypes
void circumference(double radius);
void area(double radius);
void volume(double radius);
void print_menu();
const float PI=3.141593;

//function main begins program execution
int main()
{
    void(*f[3])(double)={circumference,area,volume};
    
    //initialization phase
    size_t selection=0;
    
    //processing phase
    while(selection!=3)//When selection number is not 3
    {
        
        //execute function print_menu if section is out of range
        print_menu();
        do
        {
            scanf("%ld",&selection);
        }while(selection<0||selection>3);//end do while
        
        
        //if selection isn't equal to three, follow the corresponding function
        if(selection!=3)
        {
            (*f[selection])(selection);
        }//end if
        
    }//end while
    
        //if selection 3 is selected, terminate program
        if(selection==3)
        {
        puts("Done. Program terminated.");
        }//end if
    
    
}//end function main

//Output the menu
void print_menu( void )
{
    printf( "Enter a choice:\n"
           "0 Calculate the circumference\n"
           "1 Calculate the area\n"
           "2 Calculate the volume of a sphere\n"
           "3 End program\n");
}

//Find the circumference of the circle
void circumference (double radius)
{
    //Ouput question
    puts("\n\nWhat is the radius of the circle?");
    scanf("%lf",&radius);
    
    //Ouput the radius given
    printf("\nRadius= %f",radius);
    
    //This formula calulates the circumference using the given radius
    double circ = 2*PI*radius;
    printf("%s%.2f%s\n\n","\nThe circumference of the circle is ",circ," meters.");//Output the circumference
}

//Find the area of the circle
void area (double radius)
{
    //Output question
    printf("\n\nWhat is the radius of the circle?");
    scanf("%lf",&radius);
    
    //Ouput radius given
    printf("\nRadius= %f",radius);
    
    //This formula calculates the area using the given radius
    double area = PI*radius*radius;
    printf("\n%s%.2f%s\n\n","The area of the circle is ",area," square meters.");//Ouput the area
}

//Find the volume of the sphere
void volume (double radius)
{
    //Ouput question
    puts("\n\nWhat is the radius of the sphere?");
    scanf("%lf",&radius);
    
    //Output radius given
    printf("\nRadius= %f",radius);
    
    //This formula calculates the volume of the sphere using the given radius
    double volume = (4/3)*PI*pow(radius,3);
    printf("%s%.2f%s\n\n","\nThe volume of the sphere is ",volume," cubed meters.");//Ouput the volume
}
