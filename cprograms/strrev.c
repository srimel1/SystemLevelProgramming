#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
  
void printReverse(char buffer[]) 
{ 
    int size = strlen(buffer); 
    //printf("%d\n", size);

    if(buffer[size-1] == '\n') size--;
    printf("%d\n", size);
    
    //Traverse string from end 
    int i; 
    for (i = size; i >= 0; i--) { 
        if(buffer[i] == '\n') {
            buffer[i] = '\0';
            
           // printf("\n");
            printf("%s\n", &(buffer[i]) + 1); 
            i++;
            
            
        }
        else if(buffer[i] == ' ') { 
  
            // putting the NULL character at the  
            // position of space characters for 
            // next iteration.          
            buffer[i] = '\0'; 
  
            // Start from next charatcers
            printf("%s ", &(buffer[i]) + 1); 
        } 
     } 
  
     // printing the last word 
     printf("%s", buffer); 
}

#define _READFILE_GUESS 256

// Driver code 
int main() 
{ 
    char filename[40];
    printf("Enter a file name: ");
    scanf("%s", filename);

    
    FILE* fp = fopen(filename, "r");
    
    char* result = malloc(sizeof(char) * _READFILE_GUESS + 1);

    // the position in the string to write the character to
    size_t pos = 0;

    // the amount of memory allocated for the string
    size_t capacity = _READFILE_GUESS;

    // character to hold the currently-read character from the file
    char ch;

    // until the character is the EOF character
    while((ch = getc(fp)) != EOF){
        // update the character at position `pos` to `ch`
        result[pos++] = ch;

        // if the next position would exceed bounds
        if(pos >= capacity){
            // add the guess to the capacity
            capacity += _READFILE_GUESS;

            // allocate memory accordingly
            // (+ 1) for trailing null byte
            //result = realloc(result, sizeof(char) * capacity + 1);

            // 2. memory allocation failed
            // if(result == NULL)
            //     return NULL;
        }
    }

    // close the file
    fclose(fp);

    // remove extra memory
    //result = realloc(result, sizeof(char) * pos);

    // 2. memory allocation failed
    // if(result == NULL)
    //     return NULL;

    // `pos` now points to the index after the last character read
    result[pos] = '\0';

    char str[] = "2 I AM A GEEK 6\n3 WHAT ABOUT NOW 4\n"; 
    printReverse(str);
    printf("\n");
    char* buffer = result;
    printReverse(buffer);
    //printReverse(buffer);

    //printf("\n");
    return 0; 
} 