#include <stdio.h>

int main()
{
    unsigned int N = 0;
    scanf("%d", &N);

    unsigned int chests_count[N], sum = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &chests_count[i]);
        sum += chests_count[i];
    }

    unsigned int count = sum / N;
    printf("\n");
    for (int i = 0; i < N; i++)
        printf("%d\n", count - chests_count[i]);

    return 0;
}
