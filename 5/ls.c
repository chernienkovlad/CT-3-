#include <stdio.h>
#include <sys/stat.h>
#include <getopt.h>
#include <dirent.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>

#define MAX_SIZE 2048

void print_ls(char* path)
{
    DIR* my_dir;
    struct dirent* file;
    struct stat filestat;
    my_dir = opendir(path);
    while((file = readdir(my_dir)) != NULL)
    {
        if (file->d_name[0] == '.')
        {
            continue;
        }
        char new_path[512];
        snprintf(new_path, 512, "%s/%s", path, file->d_name);
        stat(new_path, &filestat);
        printf("%s", file->d_name);
        if (S_ISDIR(filestat.st_mode) == 1)
        {
            printf("/");
        }
        printf("\n");
    }
    closedir(my_dir);
}

int main(int argc, char** argv)
{
    print_ls(argv[1] == NULL ? "." : argv[1]);
    return 0;
}
