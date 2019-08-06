#include <stdio.h>

main()
{
    int pid;
    printf("I'm the original process with PID %d and PPID %d\n\n", getpid(), getppid());
    pid = fork(); /* duplicate, child and parent continue from here */
    if(pid != 0){/* pid is non-zero, so must be the parent */
        printf("\nI'm the parent process with PID %d and PPID %d.\n", getpid(), getppid());
        printf("My childs PID is %d\n", pid);
    } 

    else /* pid is zero so i must be the child */{
        printf("\nI'm the child process with PID %d and PPID %d.\n", getpid(), getppid());
    }

    printf("PID %d terminates\n", getpid()); /* both processes execute termination */

}