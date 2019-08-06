#define MAX 256
#include<string.h>
#include<stdio.h>
int main()
{
        int i,j,alpha=0,others=0,digi=0,lines=0,words=0;
        FILE *fp1;
        char word[MAX], fname[MAX],ch;

        /* Get the name of the File from User*/
        printf("Enter your input file name:");
        fgets(fname, MAX, stdin);
        fname[strlen(fname) - 1] = '\0';
     
        /* Open File In Read Mode */
        fp1 = fopen(fname, "r");

        /* If We got error in opening the file */
        if (!fp1) {
                printf("Unable to open the input file!!\n");
                return 0;
        }

       ifstream fin(fname);
       printf("The orginal text is \n\n");
       while(fin.get(ch))
       {
       i=ch;
       cout<<ch;
  
       if(i>64&&i<91||i>96&&i<123)
       alpha++;
       }

   printf("\nThere are %d Characters in the file %s\n",alpha,&fname);
  
}
