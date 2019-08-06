#include <stdio.h>

int main()
{
    int d = 8;
    double f = 7.6;
    unsigned int x = 01000101;
    printf("%d & %f %x are variables" , d, f, x);
    printf("\n\n");
    printf("%d works\n", bitcount(x));
}
int bitcount(unsigned int x)
{
    int b;
    for(b=0; x != 0; x = x>>1)
    {
        if(x & 01)
        b++;

        return b;
    }

}