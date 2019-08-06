#include <stdio.h>
#include <string.h>

int main()
{
    char* buffer = "hello my name is";
    int size = strlen(buffer);
    reverseWords(buffer, size);
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
