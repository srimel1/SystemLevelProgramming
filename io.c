
/* checks for end of file */
#include <stdio.h>
int main()
{
    FILE *fp = fopen("test", "r");
    int ch = getc(fp);
    while(ch != EOF)
    {
        putchar(ch);
        ch = getc(fp);
    }
    if(feof(fp))
        printf("\n End of file");
    else
        printf("\n Something went wrong.");
    fclose(fp);
    getchar();
    printf(getchar());
    return 0;
}