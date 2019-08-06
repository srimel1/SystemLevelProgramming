#include <stdio.h>
#include <stdlib.h>

main()
{
    printf("Im the process %d and Im about to exec and ls -l\n", getpid());
    execl("/bin/ls", "ls", "-l", NULL); /* execute ls */
    printf("This line should nev er be executed\n");
}