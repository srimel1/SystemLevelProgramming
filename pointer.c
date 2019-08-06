#include <stdio.h>

int main()
{
    int *p, q, var1;
    q = 50;
    char var2[10];
    /* address of q is assigned */
    p = &q;
    /* display q's value with pointer */
    printf("%d\n", *p); //prints 50
    /* prints address */
    printf("Address of var1 is %x\n", &var1); 
    printf("Address of var2 is %x\n", &var2);
    return 0;
}