#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main()
{
    int pid;

    pid = fork(); /* duplicate */

    /* branch based on return value from fork () */
    if(pid != 0)
    {
        /* never terminate, never execute a wait () */
        while(1)
        sleep(1000);

    }else{
        exit(42); /* exit with a silly number */
    }
    
}