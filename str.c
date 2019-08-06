#include <stdio.h>
#include <string.h>

int main()
{
  char s1[100], s2[100];
 
  printf("Enter a string\n");
  gets(s1);
  printf("Enter another string\n");
  gets(s2);

  strcpy(s1, "computer");
  strcpy(s2, "science");
  
  printf("%s\n",s1);
  printf("%s\n", s2);

  strcat(s1,s2);
  printf("%s", s1);
  printf("\n%s", s2);
  
  s1[strlen(s1)-6]='\0';
  
  return 0;


}