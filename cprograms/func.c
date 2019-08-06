#include <stdio.h>
int main()
{
	int x = func(8,3);
	printf("%d \n", func(8,3));
}


int func(int x, int y)
{
int count = 0;
return x>>y ;
}
