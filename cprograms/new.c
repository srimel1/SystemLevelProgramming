#include <time.h>
#include <stdlib.h>

int randint(int n)
{
	if((n-1)== RAND_MAX)
	{
		return rand();
	}
	else
	{
		assert(n<= RAND_MAX)
		int end = RAND_MAX/n;
		assert(end>0);
		end*=n;

		int r;
		while((r=rand())>= end);
		return r% n;
	}
}
