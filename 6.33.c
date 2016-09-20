//Binary Search
//Problem 6.33
//By: Aviral Kukreja
//7-5-16
#include <stdio.h>
#define SIZE 20//Maximum size of array

//All of the integers are defined for the array
int binarySortRecursive(int key, int low, int high);
void printSubArray(int b[],int low, int high);
int myArray[SIZE]={0};
int i, middle;

int main(void) {
    
    int key;
    //intialize array sorted
    for (i = 0; i < SIZE; i++)
    {
        myArray[i]=i*2;
        
    }
    printf("Enter a number between 0 and 38: ");
    scanf("%d",&key);
    
    if(binarySortRecursive(key, 0, SIZE-1)){
        
        printf("Key is found at index %d\n", middle);
        
    }
    else
    {
        printf("key is not found");
    }
    
    
}
//recursive BinarySort algorithm
int binarySortRecursive(int key, int low, int high){
    
    printSubArray(myArray,low,high);
    middle=(low+high)/2;
    
    if (myArray[middle]==key)
    {
        return 1;
    }
    else if (key<myArray[middle] && low<high) //lower portion
    {
        return binarySortRecursive(key, low, middle-1);
    }
    else if(key>myArray[middle] && low<high)//upper portion
    {
        return binarySortRecursive(key, middle+1, high);
    }
    else
    {
        return 0;
    }
}
//prints new SubArray
void printSubArray(int b[], int m, int n){
    
    for (i = m; i <= n; i++)
    {
        printf("%d ",myArray[i]);
    }
    printf("\n");
}