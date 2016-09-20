//
//  8.c
//  Testing
//
//  Created by Aviral Kukreja on 7/11/16.
//  Copyright © 2016 Aviral Kukreja. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(void)
{
    int i,j,k;
    char a[30],b[30];

    
    
        
    
    puts("Enter a message: \n");
    fgets(a,sizeof(a), stdin);
    
    printf("\n\nYour SMS translation is: \n%c",a[0]);

    
    if (strlen(a)>=4) {
    
    for(i=0;a[i]!='\0';i++)
    {
        
            
        
        if(a[i]==' ')
            printf("%c",a[i+1]);
    }
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ')
            for(j=i,k=0;a[j]!='\0';j++,k++)
                b[k]=a[j];
    }
    
    b[k]='\0';
    
  //  for(i=0;b[i]!='\0';i++)
        printf("%c\n",b[i]);
    
    


if (strlen(a) <= 3){
        puts("bye");
}
}
}

