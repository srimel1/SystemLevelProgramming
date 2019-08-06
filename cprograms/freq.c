#include <stdio.h>
int main()
{
char buff[255];
FILE *fp;
fp = fopen("C:/temp/test1.txt", "r");
fscanf(fp, "%s", buff);
printf("1 : %s\n", buff );
fgets(buff, 255, (FILE*)fp);
printf("2: %s\n", buff );
}
