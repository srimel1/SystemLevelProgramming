/**
 * C program to count occurrences of a word in file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

/* Function declarations */
int countFrequency(FILE *fp, const char *word);


int main()
{
    FILE *fp;
    char filename[100];

    char word[50];

    int wCount;

    /* Input file filename */
    printf("Enter file name: ");
    scanf("%s", filename);

    /* Input word to search in file */
    printf("Enter word to search in file: ");
    scanf("%s", word);

    /* Try to open file */
    fp = fopen(filename, "r");

    /* Exit if file not opened successfully */
    if (fp == NULL)
    {
        printf("Cannot open filename.\n");
        printf("Sorry, cannot open file.\n");

        exit(EXIT_FAILURE);
    }

    // Call function to count all occurrence of word
    wCount = countFrequency(fp, word);

    printf("'%s' is found %d times in file.", word, wCount);


    // Close file
    fclose(fp);

    return 0;
}


/**
 * Returns freqency of given word in the file.
 */
int countFrequency(FILE *fp, const char *word)
{
    char str[SIZE];
    char *pos;

    int index, count;
    
    count = 0;

    // Read lines from file till EOF.
    while ((fgets(str, SIZE, fp)) != NULL)
    {
        index = 0;

        // Find next occurrence
        while ((pos = strstr(str + index, word)) != NULL)
        {
            // index = of word in str 
            // pos =  memory address position of str
            index = (pos - str) + 1;

            count++;
        }
    }

    return count;
}