#include <stdio.h>
#include <string.h>

int main()
{
	char buf[BUFSIZ];
char *p;
printf("Enter a line of text, max %d characters\n",sizeof(buf));
if(fgets(buf, sizeof(buf), stdin)!= NULL)
{	printf("thank you, you evered >%s<\n",buf);

if((p=strchr(buf, '\n\))!= NULL)
*p='\0';
printf("And now its >>%s<\n", buf);
} return 0;
}