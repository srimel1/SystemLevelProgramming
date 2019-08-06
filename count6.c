#include <stdio.h>
#define MAX_FILE_NAME 100

int main()
{
    FILE* fp;
    int nl = 0, count = 0;
    char filename[MAX_FILE_NAME];
    char c;

    /* get file name from user */
    printf("Enter file name: ");
    scanf("%s", filename);
    
    /* open file */
    fp = fopen(filename, "r");

    /* check if file exists */
    if(fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

     /* get characters from file and store them */
     for(c = getc(fp); c != EOF; c = getc(fp))
    
         count = count + 1;
        
     /* close the file */
     fclose(fp);

     /* print the count of the characters */
     printf("The file %s has %d new lines\n ", filename, nl);

    
    int charCount;
    charCount = getChar(fp, filename);
    printf("There are %d characters in the file %s\n", charCount, filename);
    return 0;

}

int getChar(FILE* fp, char filename[MAX_FILE_NAME])
{
    int count = 0;
    int c;
     
    /* open file */
    fp = fopen(filename, "r");
    
    for(c = getc(fp); c != EOF; c = getc(fp))
    count++;

    /* close the file */
    fclose(fp);

    /* print the count of the characters */
    printf("The file %s has %d characters\n ", filename, count);

    return count;
    int d, nl = 0;
    while((d = getchar()) != 'Z')
     if(d == '\n')
      nl++;

    printf("%d\n", nl);

}
#define IN 1
#define OUT 0
int getLine()
{
    int c, nl = 0;
    while((c = getchar()) != 'Z')
     if(c == '\n')
      nl++;

    printf("%d\n", nl);
}