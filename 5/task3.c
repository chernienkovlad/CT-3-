#include <stdio.h>
#include <unistd.h>

#define MAX_SIZE 2048

int main()
{
    int fd[2];
    pipe(fd);

    const char path[] = ".";

    pid_t pid = fork();

    if (pid == 0)
    {
        execl("ls.c", path);
    }
    else
    {
        char ls[MAX_SIZE];
        read(fd[0], ls, MAX_SIZE*sizeof(char));
        printf("%s", ls);
    }

    return 0;
}
