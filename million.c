
#include <fcntl.h>
#include <stdio.h> 
#include <stdlib.h>


enum { FALSE, TRUE }; 
enum { STDIN, STDOUT, STDERR }; 

#define BUFFER_SIZE 4096 
#define NAME_SIZE 12
#define MAX_LINES 100000 


char *fileName = NULL; 
char tmpName [NAME_SIZE]; 
int charOption = FALSE;
int standardInput = FALSE; 
int lineCount = 0; 
int lineStart [MAX_LINES]; 
int fileOffset = 0; 
int fd; 

/****************************************************************/

main (argc, argv)

int argc; 
char* argv [];

{

parseCommandLine (argc,argv);
pass1 (); 
pass2 (); 
return (/* EXIT SUCCESS */ 0); /* Done */


}

/****************************************************************/

parseCommandLine (argc, argv)

int argc; 
char* argv [];


{

int i;

for (i= 1; i < argc; i++)

{ 
if(argv[i][0] == '-')
  processOptions (argv[i]); 
else if (fileName == NULL) 
fileName= argv[i]; 
else usageError (); 
 }

standardInput = (fileName == NULL);

}

/****************************************************************/

processOptions (str)

char* str;
{
int j;
for (j= 1; str[j] != NULL; j++)
{ 
switch(str[j])  { 
case'c':
charOption = TRUE; 
break;
case'r':
charOption = TRUE; 
break;
default:
usageError (); 
break;

}

}

}

/****************************************************************/

usageError ()

{

fprintf (stderr, "Usage: reverse -c [filename]\n"); 
exit (/* EXIT FAILURE */ 1);

}
/****************************************************************/

pass1 ()


{

int tmpfd, charsRead, charsWritten; 
char buffer [BUFFER_SIZE];

if (standardInput)  {
      fd = STDIN;
      
 sprintf (tmpName, ".rev.%d",getpid ()); 
    

    
 tmpfd = open (tmpName, O_CREAT | O_RDWR, 0600);
 
  if (tmpfd == -1) fatalError ();
 } 

else  { 
fd = open (fileName, O_RDONLY);
if (fd == -1) fatalError (); }

lineStart[0] = 0;

while (TRUE) 
{

 charsRead = read (fd, buffer, BUFFER_SIZE);
 if (charsRead == 0) break; 
 if (charsRead == -1) fatalError ();

trackLines (buffer, charsRead); 


 if (standardInput) { 
charsWritten = write (tmpfd, buffer, charsRead);
 if(charsWritten != charsRead) fatalError ();
 }

}

 lineStart[lineCount + 1] = fileOffset;

 if (standardInput) fd = tmpfd;

}

/****************************************************************/

trackLines (buffer, charsRead)

char* buffer;
int charsRead;


{

int i;

for (i = 0; i < charsRead; i++)

{ 
++fileOffset; 
 if (buffer[i] == '\n') lineStart[++lineCount] = fileOffset; 
}

}

/****************************************************************/

int pass2 () {

int i;

for (i = lineCount - 1; i >= 0; i--) 
processLine (i);

close (fd); 
 if (standardInput) unlink (tmpName); 

}

/****************************************************************/

processLine (i)

int i; 

{

int charsRead;
char buffer [BUFFER_SIZE];

lseek (fd, lineStart[i], SEEK_SET);

charsRead = read (fd, buffer, lineStart[i+1] - lineStart[i]);

if (charOption==1) reverseLine (buffer, charsRead);
if(charOption==2)
    reverseLine (buffer, charsRead);
    reverseWords (buffer, charsRead);

write (1, buffer, charsRead); 

}

/****************************************************************/

reverseLine (buffer, size)

char* buffer; 
int size;

{

int start = 0, end = size - 1; 
char tmp;

if (buffer[end] == '\n') --end; /* Leave trailing newline */


while (start < end)

{ 
tmp = buffer[start];
buffer[start] = buffer[end]; 
buffer[end] = tmp; 
++start; 

--end;
 }

}

/****************************************************************/
reverseWords (char* buffer, int size){
  int j=0,k=0;
  int i;
  char temp;
  for( i=0;i<size-1;i++){
    if(buffer[i]==' '&&i!=0){
      k=i-1;
      while(j<k){
        temp=buffer[j];
        buffer[j]=buffer[k];
        buffer[k]=temp;
        ++j;
        --k;
      }
      j=i+1;
    }
    else if(i==size-2){
      k=i;
      while(j<k){
        temp=buffer[j];
        buffer[j]=buffer[k];
        buffer[k]=temp;
        ++j;
        --k;
      }
      j=i+1;
    }
  }
}
fatalError ()

{

perror ("reverse: "); /* Describe error */ 
exit (1);

}
