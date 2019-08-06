#include <stdio.h>
#include <string.h>

int main()
{
    char arr[100];
    int c;

    printf("Enter the string: \n");
    gets(arr);\
    int length = strlen(arr);
    char* buffer = arr;

    printf("%s\n", arr);
    reverseWord(arr, length);

    /* or use while loop
    while(arr[c] != '\0'){
        printf("%c", arr[c]);
        c++;
    }
    printf("\n");
    //or use for loop
    for(c = 0; arr[c] != '\0'; c++){
        printf("%c", arr[c]);
    }*/
}

void reverseWord (char* buffer, int size) {
    int i;
    char tmp;

    int length = size - 1;
    for(i = length; i >= 0; i--)
    {
        if(buffer[i] == '\n')
        {
            i--;
        }
        if(buffer[i] == ' ')
        {
            buffer[i] == '\0';

            printf("%s ", &(buffer[i]) + 1);
        }
        
        
        
    }
    printf("%s", buffer);
}
