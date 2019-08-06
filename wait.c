#include <stdio.h>
#include <stdlib.h>

main()
{
    int pid, status, childPid;
    printf("Im the parent process and my PID is %d\n", getpid());
    pid = fork();

    if(pid !=0)
    {
        printf("Im the parent with PID %d and PPID %d\n", getpid(), getppid());
        /* wait for child to terminate */
        childPid = wait(&status);
        printf("A child with PID %d terminated with exit code %d\n", childPid, status>> 8);

    }else{
        printf("Im the child with PID %d and PPID %d\n", getpid(), getppid());
        exit(42);
    }
    printf("PID %d terminates\n", getpid());
}