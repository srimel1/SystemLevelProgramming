#include <stdio.h>
main()
{
    printf("Im process %d and Im about to exec an ls -l\n", getpid());
    execl("/bin/ls", "ls", "-l", NULL); /*Execute ls*/
    printf("This line should never be executed\n");

}