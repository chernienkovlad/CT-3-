#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <sys/timeb.h>
#include <math.h>
#define TNUM 8

void* sum(void *c)
{
    int *No = (int *)c;
	printf("I'm thread # %d\n", *No);
    pthread_exit(NULL);
}

int main()
{
    int i;
    int s = 0;
    pthread_t t[TNUM];
    for (i = 0; i < TNUM; i++)
    {
        pthread_create(&t[i], NULL, sum, &i);
        for (int j = 0; j < 100000; j++) {
			s++;
		}
    }
    for (i = 0; i < TNUM; i++)
    {
        pthread_join(t[i], NULL);
    }
    
    
    return 0;
}
