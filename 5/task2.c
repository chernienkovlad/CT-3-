#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    int fd[2];
    pipe(fd);

    const char filename[] = "text.txt";
    struct stat filestat = {};
    stat(filename, &filestat);
    int size = filestat.st_size;
    const char file_to[] = "tmp.txt";

    pid_t pid = fork();

    if (pid == 0)
    {
        char* buff = (char*)calloc(size, sizeof(char));

        FILE* file = fopen(filename, "r");
        fread(buff, sizeof(char), size, file);
        fclose(file);

        int i = 0;
        while (size > 1000)
        {
            write(fd[1], &buff[i], 1000);
            size -= 1000;
            i += 1000;
        }
        write(fd[1], &buff[i], size);

        free(buff);
    }
    else
    {
        char buff[1000];
        FILE* file = fopen(file_to, "w");

        while (size > 1000)
        {
            read(fd[0], buff, 1000);
            fwrite(buff, sizeof(char), 1000, file);
            size -= 1000;
        }
        read(fd[0], buff, size);
        fwrite(buff, sizeof(char), size, file);
    }

    return 0;
}
