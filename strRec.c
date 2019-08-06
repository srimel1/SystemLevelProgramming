#include <stdio.h>
#include <string.h>

void print(char*);

int main()
{
    char s[100];
    printf("Please enter a string: \n");
    gets(s);
    print(s);
    printf("\n");

    return 0;
}

void print(char *t)
{
    if(*t == '\0')
    return;
    printf("%c", *t);
    print(++t);
}