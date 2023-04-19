#include <stdio.h>
#include <stdlib.h>

void change_arr(int*, int);
void output_arr(int*, int);

int main()
{
    unsigned int N = 0;
    scanf("%d", &N);

    int *arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    change_arr(arr, N);
    output_arr(arr, N);

    free(arr);
    return 0;
}

void change_arr(int *arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] % 2 == 0) {
            arr[i] *= 2;
        } else {
            arr[i] += 2;
        }
    }
}

void output_arr(int *arr, int N)
{
    printf("\n");
    for (int i = 0; i < N; i++)
        printf("%d\n", arr[i]);
}
