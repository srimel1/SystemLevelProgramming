#include <stdio.h>

int main(int argc, char *argv[])
{
 FILE *fp;
 char *filename;
 char ch;

  // Check if a filename has been specified in the command
  if (argc < 2)
   {
        printf("Missing Filename\n");
        return(1);
   }
   else
  {
        filename = argv[1];
        printf("Filename : %s\n", filename);
   }

   // Open file in read-only mode
   fp = fopen(filename,"r");

   // If file opened successfully, then print the contents
   if ( fp )
      {
        printf("File contents:\n");
        while ( (ch = fgetc(fp)) != EOF )
           {
                printf("%c",ch);
           }

       }
   else
      {
         printf("Failed to open the file\n");
        }

return(0);
}
int getFreq(char *filename)
{
	char buff[255];
	fgets(buff, 255, (FILE*)fp);
	printf("%s\n", buff);
	int count[26]=0;
	c=buff[i];
	if(c<='z' && c>='a')
		count[c-'a']++;
	else if(c<='Z' &&'A')
		count[c-j'A')++;
}
