#include<stdio.h>
main()
{
    int pid;
    printf("Im the original process with PID %d and PPID %d \n",
    getpid(), getppid());
    pid = fork ();
    if(pid !=0)
    {
    printf("im the parent process with PID %d and PPID %d \n",
    getpid(), getppid());
    printf("My childs PID is %d\n", pid);
    } 
    else
    {
    printf("Im the child process with PID %d and PPID %d\n",
    getpid(), getppid());
    }
    printf("PID %d terminates \n", getpid());
}