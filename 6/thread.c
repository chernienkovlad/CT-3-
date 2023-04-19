#include <stdio.h>
#include <pthread.h>

void* func(void* c)
{
    int* no = (int*)c;
    printf("I am thread #%d\n", *no);
    pthread_exit(NULL);
}

int main()
{
    pthread_t t[4];
    int a[8];

    for (int i = 0; i < 8; i++)
        a[i] = i;

    for (int i = 0; i < 8; i++)
        pthread_create(&t[i], NULL, func, &a[i]);

    for (int i = 0; i < 8; i++)
        pthread_join(t[i], NULL);

    return 0;
}
