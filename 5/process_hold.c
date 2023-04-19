#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// fd[0] - read
// fd[1] - write

int main()
{
    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        close(fd[1]);

        char string[10];
        int size = read(fd[0], string, 10);

        close(fd[0]);
    }
    else
    {
        close(fd[0]);

        int stat_loc = 0;
        wait(&stat_loc);

        close(fd[1]);
    }

    return 0;
}
