#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "arrayUtil.h"

int main (int argc, char *argv[])
{
    char *fileName="myFile.txt";
    if(argc!=2){
        printf("Please enter only one argument\n");
        exit(-1);
    }
    
    fileName=argv[1];
    
    FILE  *fp;
    fp = fopen(fileName, "r");

    if(fp == NULL){
        printf("Error opening file\n");
        exit(-1);
    }
     

    int count[26] = {0};

    char buff[10];
    int i=0;
    while(fgets(buff, 10, (FILE*)fp)){
        for (i = 0; i < strlen(buff); i++) {
            char c = buff[i];
            //printf("%c",c);
            if(c <= 'z'&& c >= 'a')
                count[c-'a']++;
            else if(c <= 'Z'&& c >= 'A')
                count[c-'A']++;
        }
       
    }
    
    fclose(fp);
  
    int max=0, maxIndex=0;
    
    for (i = 0; i < 26; i++) {
        if(max < count[i]){
            max = count[i];
            maxIndex = i;
        }
    }
    
    
    printf("The most frequent letter is '%c' , it appears %d times \n", 'a'+maxIndex, max);
}

