/*
* C Program to count frequency of characters in string
*/
#include <stdio.h>
 
int main(){
    char inputString[100];
    /* Declare a frequency counter array of size 256 
     * (for all ASCII characters) and initialize it with zero 
     */
    int index, frequency[256] = {0};
    printf("Enter a String\n");
    gets(inputString);
    for(index=0; inputString[index] != '\0'; index++){
        /* Populate frequency array */
        frequency[inputString[index]]++;
    }
    /* Print characters and their frequency */
    printf("\nCharacter   Frequency\n");
    for(index=0; index < 256; index++){
        if(frequency[index] != 0){
            printf("%5c%10d\n", index, frequency[index]);                    
        }
    }
 
    getch();
    return 0;
}
