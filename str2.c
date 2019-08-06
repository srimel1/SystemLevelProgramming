#include <stdio.h>
#include <string.h>

int main()
{
    int i, len, cmp;
    char s1[100], s2[100];
    char st1[] = "abc";
    char st2[] = "def";


    printf("Please enter a string: ");
    gets(s1);
    
    printf("Enter a string to compare: ");
    gets(s2);

    printf("\nThe first string is:            %s", s1);
    printf("\nThe second string is:           %s", s2);
    
    len = strlen(s1);
    cmp = strcmp(s1, s2);

    printf("\nThe length of the string:       %d", len);
    printf("\nString comparison:              %d\n", cmp);
    
    printf("%s\n%s\n", st1,st2);
    //strcpy(st1, st2);
    strcat(st1, st2);
    printf("%s\n%s\n",st1, st2);
    return 0;
}
int print(char *arr, int size)
{
    int len, i;
    len = strlen(arr);
    for(int i = 0; i < size; i++)
    {

    }
}
}