#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n;
	time_t t;

	n = 5;

/* Initializes random number generator */
	srand((unsigned) time(&t));

/* Print 5 random numbers from 0 through 49 */
	for(i=0; i<n; i++)
	{
		printf("%d\n", rand() % 50);
	}

	return(0);
	
}
