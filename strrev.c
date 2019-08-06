#include <stdio.h> 
#include <string.h> 
  
void printReverse(char str[]) 
{ 
    int length = strlen(str); 
  
    // Traverse string from end 
    int i; 
    for (i = length - 1; i >= 0; i--) { 
        if(str[i] == '\n') {
            str[i] = '\0';
            printf("\n");
            i--;
        }
        if (str[i] == ' ') { 
  
            // putting the NULL character at the  
            // position of space characters for 
            // next iteration.          
            str[i] = '\0'; 
  
            // Start from next charatcers
            printf("%s ", &(str[i]) + 1); 
        } 
    } 
  
    // printing the last word 
    printf("%s", str); 
} 
  
// Driver code 
int main() 
{ 
    char str[] = "I AM A GEEK\nWHAT ABOUT NOW"; 
    char* buffer = str;
    printReverse(buffer);
    printf("\n");
    return 0; 
} this is line 1
this is line 2
this is line 3
this is line 4
this is line 5

And this is the output:
5
 line is this4
 line is this3
 line is this2
 line is this1


The output I need is like this:
5 line is this
4 line is this
3 line is this
2 line is this
1 line is this