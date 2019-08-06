#include <stdio.h>

main()
{
    int pid;
    printf("I'm the original process with PID %d and PPID %d.\n", getpid(), getppid());
    pid = fork();

    if(pid != 0){
    printf("Im the parent process with PID %d and PPID %d.\n",getpid(), getppid());
    printf("My childs ID is %d\n", pid);
    }else{
        /* pid is 0 so must be child */
        sleep(5);
        printf("Im the child process with PID %d and PPID %d\n", getpid(), getppid());

    }
    printf("PID %d terminates \n", getpid());
    /* both process execute because PID is the parent */
}