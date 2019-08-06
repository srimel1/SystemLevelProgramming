#include <fcntl.h> /* For file mode definitions */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* wasn't in the original code */
#include<string.h>

/* Enumerator */
enum { FALSE, TRUE }; /* Standard false and true values */
enum { STDIN, STDOUT, STDERR }; /* Standard I/O channel indices */

/* #define Statements */
#define BUFFER_SIZE 4096    /* Copy buffer size */
#define NAME_SIZE 12
#define MAX_LINES 100000 /* Max lines in file */

/* Function Prototypes */
void parseCommandLine (int argc, char* argv[]);
void processOptions (char* str);
void usageError (void);
void pass1   (void);
void trackLines (char* buffer, int charsRead);
void pass2   (void);
void processLine (int i);
void reverseLine (char* buffer, int size);
void reverseWords (char* buffer, int size);
void fatalError (void);

/* Globals */
char *fileName = NULL;  /* Points to file name */
char tmpName [NAME_SIZE];
int charOption = FALSE; /* Set to true if -c option is used */
int charOptionR = FALSE; /* *****Set to true if -r option is used****** */
int standardInput = FALSE; /* Set to true if reading stdin */
int lineCount = 0; /* Total number of lines in input */
int lineStart [MAX_LINES]; /* Store offsets of each line */
int fileOffset = 0; /* Current position in input */
int fd;  /* File descriptor of input */

/*  Main  */
int main (int argc, char* argv[]) {
    parseCommandLine (argc,argv); /* Parse cmd line */
    pass1 (); /* Perform first pass through input */
    pass2 (); /* Perform second pass through input */
    return (/* EXITSUCCESS */ 0); /* Done */ }

void parseCommandLine (int argc, char* argv[]) { /* Parse command line arguments */
    int i;
    for (i= 1; i  < argc; i++) {
        if(argv[i][0] == '-')
            processOptions (argv[i]);
        else if (fileName == NULL)
            fileName= argv[i];
        else
            usageError (); /* An error occurred */   }
    standardInput = (fileName == NULL);
}

void processOptions (char* str) { /* Parse options */
    int j;
    for (j=1; str[j] != NULL; j++) {
        switch(str[j]) /* Switch on command line flag */ {
            case 'c':
            charOption = TRUE;
            break;
            case 'r':
            charOptionR = TRUE; /* ****Trying to create a case for -r option**** */
            break;
            default:         usageError ();
            break;
                
        }
        
    }
    
}

void usageError () {
     fprintf (stderr, "Usage:  reverse -c [filename]\n\treverse -r [filename]\n");
    exit (/* EXITFAILURE */ 1);
    
}

void pass1 () {
    /* Perform first scan through file */
    int tmpfd, charsRead, charsWritten;
    char buffer [BUFFER_SIZE];
    
    if (standardInput) /* Read from standard input */ {
        fd = STDIN;
        sprintf (tmpName, ".rev.%d", getpid ());  /* Random name */
        /* Create temporary file to store copy of input */
        tmpfd = open (tmpName, O_CREAT | O_RDWR, 0600);
        if (tmpfd == -1) fatalError ();
        
    }
    else /* Open named file for reading */ {
        fd =    open (fileName, O_RDONLY);
        if ( fd == -1) fatalError ();
        }
    lineStart[0] = 0; /* Offset of first line */


while (TRUE)
{
/* Read all input */
    /* Fill buffer */
    charsRead = read (fd, buffer, BUFFER_SIZE);
    if (charsRead == 0)
        break; /* EOF */
    if (charsRead == -1)
        fatalError ();  /* Error */
        trackLines (buffer, charsRead); /* Process line */
    /* Copy line to temporary file if reading stdin */
    if (standardInput) {
        charsWritten = write (tmpfd, buffer, charsRead);
        if(charsWritten != charsRead) fatalError ();
        }
}

/* Store offset of trailing line, if present */
lineStart[0] = 0;

/* If reading standard input, prepare fd for pass2 */
if (standardInput)
    fd = tmpfd;
}
void trackLines (char* buffer, int charsRead) {
    /* Store offsets of each line start in buffer */
    int i;
    for (i = 0; i < charsRead; i++) {
        ++fileOffset; /* Update current file position */
        if (buffer[i] == '\n')
            lineStart[++lineCount] = fileOffset;
    }
}

void pass2 () {
    /* Scan input file again, displaying lines in reverse order */
    int i;
    for (i = lineCount - 1; i >= 0; i--)
        processLine (i);
    
    close (fd);   /* Close input file */
    if (standardInput)      unlink (tmpName); /* Remove temp file that we made*/ }

void processLine (int i) { /* Read a line and display it */
    int charsRead;
    char buffer [BUFFER_SIZE];   /* Find the line and read it */
    lseek (fd, lineStart[i], SEEK_SET);
    charsRead = read (fd, buffer, lineStart[i+1] - lineStart[i]);
    /* Reverse line if -c option was selected */
    if (charOption) 
        reverseLine (buffer, charsRead);
    /* Write it to standard output */
    write (1, buffer, charsRead);
    if (charOptionR)
    reverseWords (buffer, charsRead);
    /* Write it to standard output */
    write (1, buffer, charsRead);
    
}

void reverseLine (char* buffer, int size) { /* Reverse all the characters in the buffer */
    int start = 0, end = size - 1;
    char tmp;   /* Leave trailing newline */
    if (buffer[end] == '\n') --end;    /* Swap characters in a pairwise fashion */
    while (start < end) {
        tmp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = tmp;
        ++start; /* Increment start index */
        --end;  /* Decrement end index */
        
    }
    
}

/***********************************************************************/

void reverseWords (char* buffer, int size)
{
  int j=0,k=0;
  int i;
  char temp;
  for( i=0;i<size-1;i++){
    if(buffer[i] == ' ' && i!= 0){
      k=i-1;
      while (j<k){
        temp = buffer[j];
        buffer[j] = buffer[k];
        buffer[k] = temp;
        ++j;
        --k;
      }
      j=i+1;
    }
    else if(i == size-2)
    {
      k=i;
      while (j<k)
      {
        temp = buffer[j];
        buffer[j] = buffer[k];
        buffer[k] = temp;
        ++j;
        --k;
      }
      j=i+1;
    }
  }
}

/*****************************************************************************/
void fatalError () {
    perror ("reverse: ");  /* Describe error */
    exit (1);
}

