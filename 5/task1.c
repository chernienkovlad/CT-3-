#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd[2];
    pipe(fd);

    int N = 0;
    scanf("%d", &N);

    pid_t pid = fork();

    if (pid == 0)
    {
        int* num_arr = (int*)calloc(N, sizeof(int));
        read(fd[0], num_arr, N*sizeof(int));

        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += num_arr[i];

        printf("%d\n", sum);
        free(num_arr);
    }
    else
    {
        int* num_arr = (int*)calloc(N, sizeof(int));
        for (int i = 0; i < N; i++)
            scanf("%d", &num_arr[i]);

        write(fd[1], num_arr, N*sizeof(int));
        free(num_arr);
    }

    return 0;
}
