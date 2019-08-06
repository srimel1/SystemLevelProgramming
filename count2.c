#include <stdio.h> 
#define MAX_FILE_NAME 100 
  
int main() 
{ 
    FILE* fp; 
  
    // Character counter (result) 
    int count = 0; 
  
    char filename[MAX_FILE_NAME]; 
  
    // To store a character read from file 
    char c, d; 

    //to store nl
    int nl;
  
    // Get file name from user. 
    // The file should be either in current folder 
    // or complete path should be provided 
    printf("Enter file name: "); 
    scanf("%s", filename); 
  
    // Open the file 
    fp = fopen(filename, "r"); 
  
    // Check if file exists 
    if (fp == NULL) { 
        printf("Could not open file %s", 
               filename); 
        return 0; 
    } 
  
    // Extract characters from file 
    // and store in character c 
    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        count++;

            if(c == '\n' || c == '\0')
                nl++;
    }
  
        // Increment count for this character 
        //count++;
        

    //Count lines

    // Print the count of characters 
    printf("The file %s has %d characters\n ", filename, count); 
    printf("The file %s has %d lines\n", filename, nl);
    

    // Close the file 
    fclose(fp); 
  
    
    return 0; 
} 