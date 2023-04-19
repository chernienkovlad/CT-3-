#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("%d %d\n", getpid(), getppid());
    }
    else
    {
        printf("%d %d %d\n", getpid(), pid, getppid());

        int stat_loc = 0;
        wait(&stat_loc);
    }

    return 0;
}
