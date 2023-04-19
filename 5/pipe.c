#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        char string1[] = "pivo";
        int size = write(fd[1], string1, 10);
    }
    else
    {
        char string2[10];
        int size = read(fd[0], string2, 10);
        printf("%s\n", string2);
    }

    return 0;
}
